#include <iostream>
#include <stdexcept>
#include "CampusIncidentCoordinator.h"
#include "AccessControlAdapter.h"
#include "LockdownProcedures.h"
#include "ReportedState.h"
#include "CommandInvoker.h"
#include "IncidentCommand.h"
#include "DispatchUnitCommand.h"
#include "SecureAreaCommand.h"
#include "IssueEvacuationCommand.h"
#include "CancelActionCommand.h"

using namespace std;
using namespace CampusGuard;

int passed = 0, failed = 0;

void check(bool result, string name) {
    cout << (result ? "[PASS] " : "[FAIL] ") << name << endl;
    result ? ++passed : ++failed;
}

template <typename F>
void testNull(F action, string name) {
    try { action(); check(false, name); }
    catch (const invalid_argument&) { check(true, name); }
}

class TestObserver : public Observer {
public:
    int updates = 0;
    void update(Incident*) override { ++updates; }
};

int main() {
    CampusIncidentCoordinator coordinator;
    AccessControlSystem access;
    AccessControlAdapter adapter;
    AlertService alerts;
    FacilitiesTeam facilities;
    MedicalTeam medical;
    SecurityTeam security;
    ResponseUnit unit("U1", "Security");
    ResponseUnit defaultUnit;
    TestObserver observer;
    Incident incident("I1", "Fire", "Engineering", "Smoke detected");
    Incident other("I2", "Medical", "Library", "Injured student");

    access.setMediator(&coordinator);
    alerts.setMediator(&coordinator);
    facilities.setMediator(&coordinator);
    medical.setMediator(&coordinator);
    security.setMediator(&coordinator);

    cout << "\n--- STATE AND OBSERVER ---\n";
    check(incident.getId() == "I1" && incident.getType() == "Fire" &&
          incident.getLocation() == "Engineering" &&
          incident.getDescription() == "Smoke detected", "Incident getters");
    check(incident.getStateName() == "Reported", "Initial state");
    incident.attach(&observer);
    incident.attach(&observer); // Duplicate must not be added.
    incident.attach(nullptr);
    incident.attach(&unit);
    incident.notifyObservers();
    check(observer.updates == 1, "Attach, duplicate/null handling and notify");
    incident.resolve();
    check(incident.getStateName() == "Reported", "Cannot resolve Reported incident");
    incident.activate();
    check(incident.getStateName() == "Active" && observer.updates == 2,
          "Activation changes state and notifies observers");
    check(unit.getStatus() == "Dispatched to Engineering", "Observer dispatches unit");
    incident.activate();
    check(observer.updates == 2, "Repeated activation causes no transition");
    incident.resolve();
    check(incident.getStateName() == "Resolved" && observer.updates == 3,
          "Resolution changes state and notifies observers");
    check(unit.getStatus() == "Unavailable", "Observer stands unit down");
    incident.activate();
    incident.resolve();
    check(incident.getStateName() == "Resolved" && observer.updates == 3,
          "Resolved state rejects further transitions");
    incident.detach(&observer);
    incident.detach(&observer);
    incident.detach(nullptr);
    incident.notifyObservers();
    check(observer.updates == 3, "Detached observer receives no updates");
    incident.detach(&unit);
    incident.setState(new ReportedState()); // Incident owns this state.
    check(incident.getStateName() == "Reported", "setState replaces state");

    cout << "\n--- RESPONSE UNIT ---\n";
    check(unit.getId() == "U1" && unit.getType() == "Security", "Unit getters");
    check(defaultUnit.getStatus() == "Available", "Default unit constructor");
    unit.dispatchTo("Library");
    check(unit.getStatus() == "Dispatched to Library", "dispatchTo");
    unit.markUnavailable();
    check(unit.getStatus() == "Unavailable", "markUnavailable");
    unit.update(&incident); // Reported: should not dispatch.
    check(unit.getStatus() == "Unavailable", "update handles Reported state");

    cout << "\n--- ADAPTER AND LEGACY SYSTEM ---\n";
    LegacyDoorSystem legacy;
    check(legacy.getBuildingMode(101) == "UNKNOWN", "Unknown legacy code");
    legacy.setBuildingMode(101, "LOCKED");
    check(legacy.getBuildingMode(101) == "LOCKED", "Legacy set/get mode");
    AccessControlSystem* target = &adapter;
    check(target->lockArea("Engineering") && target->getAreaState("Engineering") == "LOCKED", "Adapter lock");
    check(target->unlockArea("Engineering") && target->getAreaState("Engineering") == "UNLOCKED", "Adapter unlock");
    check(target->restrictArea("Engineering") && target->getAreaState("Engineering") == "RESTRICTED", "Adapter restrict");
    check(!target->lockArea("Missing") && !target->unlockArea("Missing") &&
          !target->restrictArea("Missing") && target->getAreaState("Missing") == "UNKNOWN", "Adapter rejects unknown area");

    cout << "\n--- MEDIATOR AND SERVICES ---\n";
    check(access.getAreaState("Missing") == "Unknown", "Modern unknown area");
    check(access.lockArea("Library") && access.getAreaState("Library") == "Locked", "Modern lock");
    check(access.unlockArea("Library") && access.getAreaState("Library") == "Unlocked", "Modern unlock");
    check(access.restrictArea("Library") && access.getAreaState("Library") == "Restricted", "Modern restrict");
    // These void functions expose output only: inspect their printed messages.
    facilities.unlockAreaRequest("Library");
    facilities.maintenanceCheck("Library");
    medical.stretcherAway("Student A");
    security.arrestPerson("Suspect B");
    facilities.changed();
    alerts.broadcastAlert("Library", "Keep the stairs clear");
    alerts.cancelAlert("Library");
    cout << "[MANUAL] Check mediator dispatch, maintenance, medical, security and alert messages above.\n";
#ifdef TEST_LOCK_REQUEST
    facilities.lockAreaRequest("Library");
#else
    cout << "[SKIP] lockAreaRequest has no implementation in your ZIP.\n";
#endif

    cout << "\n--- COMMANDS AND INVOKER ---\n";
    // Invoker owns submitted commands. All receivers above outlive it.
    CommandInvoker invoker;
    invoker.showHistory();
    invoker.submit(nullptr);
    invoker.undoLast();
    invoker.redoLast();
    invoker.submit(new IncidentCommand(&other, "Activate Library incident"));
    check(other.getStateName() == "Active", "IncidentCommand execute");
    invoker.undoLast();
    check(other.getStateName() == "Resolved", "IncidentCommand undo resolves incident");
    invoker.redoLast();
    check(other.getStateName() == "Active", "IncidentCommand redo restores Active");

    DispatchUnitCommand* dispatch = new DispatchUnitCommand(&unit, &incident, "Engineering");
    invoker.submit(dispatch);
    check(unit.getStatus() == "Dispatched to Engineering" && incident.getStateName() == "Active", "Dispatch execute");
    invoker.submit(new CancelActionCommand(dispatch));
    check(unit.getStatus() == "Unavailable", "Cancel execute calls dispatch undo");
    invoker.undoLast();
    check(unit.getStatus() == "Dispatched to Engineering", "Cancel undo restores dispatch");
    invoker.redoLast();
    check(unit.getStatus() == "Unavailable", "Cancel redo");

    // Check securing and undoing every supported starting state.
    string states[] = {"UNLOCKED", "RESTRICTED", "LOCKED"};
    for (int i = 0; i < 3; ++i) {
        if (i == 0) adapter.unlockArea("Engineering");
        if (i == 1) adapter.restrictArea("Engineering");
        if (i == 2) adapter.lockArea("Engineering");
        invoker.submit(new SecureAreaCommand(&adapter, "Engineering"));
        check(adapter.getAreaState("Engineering") == "LOCKED", "Secure execute from " + states[i]);
        invoker.undoLast();
        check(adapter.getAreaState("Engineering") == states[i], "Secure undo restores " + states[i]);
        invoker.redoLast();
        check(adapter.getAreaState("Engineering") == "LOCKED", "Secure redo from " + states[i]);
    }
    invoker.submit(new SecureAreaCommand(&access, "Library"));
    invoker.undoLast();
    check(access.getAreaState("Library") == "Restricted", "Secure undo restores modern Restricted state");
    invoker.showHistory(); // Includes nonempty redo stack.
    invoker.submit(new IssueEvacuationCommand(&alerts, "Engineering", "Evacuate now"));
    invoker.redoLast(); // New submission must have cleared redo stack.
    invoker.undoLast(); // Cancels evacuation.
    invoker.redoLast(); // Broadcasts evacuation again.
    invoker.showHistory(); // Calls getDescription() on every concrete command.
    cout << "[MANUAL] Check descriptions, evacuation/cancellation and 'Nothing to redo' above.\n";

    cout << "\n--- INVALID COMMAND INPUTS ---\n";
    testNull([&]() { IncidentCommand c(nullptr, "Invalid"); }, "Null incident");
    testNull([&]() { DispatchUnitCommand c(nullptr, &incident, "Engineering"); }, "Null responder");
    testNull([&]() { DispatchUnitCommand c(&unit, nullptr, "Engineering"); }, "Null dispatch incident");
    testNull([&]() { SecureAreaCommand c(nullptr, "Engineering"); }, "Null access system");
    testNull([&]() { IssueEvacuationCommand c(nullptr, "Engineering", "Test"); }, "Null alert service");
    testNull([&]() { CancelActionCommand c(nullptr); }, "Null cancelled command");

    cout << "\n--- FACADE ---\n";
    LockdownProcedures facade;
    try {
        facade.activeShooterLockdown();
        cout << "[MANUAL] Verify shooter workflow coordinates at least three subsystem operations.\n";
    } catch (const char* error) { check(false, string("Shooter facade: ") + error); }
    catch (const exception& error) { check(false, string("Shooter facade: ") + error.what()); }
    try {
        facade.chemicalLeakLockdown("Engineering");
        cout << "[MANUAL] Verify chemical workflow coordinates at least three subsystem operations.\n";
    } catch (const char* error) { check(false, string("Chemical facade: ") + error); }
    catch (const exception& error) { check(false, string("Chemical facade: ") + error.what()); }

    cout << "\nPassed: " << passed << " | Failed: " << failed << endl;
    cout << "Manual checks and the skipped function are not counted as passes.\n";
    return failed == 0 ? 0 : 1;
} // Stack objects and invoker-owned commands are destroyed automatically.
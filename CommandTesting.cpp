#include <iostream>
#include "CommandInvoker.h"
#include "IncidentCommand.h"
#include "DispatchUnitCommand.h"
#include "SecureAreaCommand.h"
#include "IssueEvacuationCommand.h"
#include "CancelActionCommand.h"
#include "Incident.h"
#include "ResponseUnit.h"
#include "AccessControlSystem.h"
#include "AlertService.h"

using namespace CampusGuard;

int main() {
    std::cout << "========================================\n";
    std::cout << "        Command Pattern Testing\n";
    std::cout << "========================================\n\n";

    Incident* incident = new Incident("INC-001", "Fire", "Science Building", "Smoke detected on 3rd floor");
    ResponseUnit* fireTeam = new ResponseUnit("RU-101", "Fire Department");
    ResponseUnit* securityTeam = new ResponseUnit("RU-102", "Security");
    AccessControlSystem* accessSystem = new AccessControlSystem();
    AlertService* alertService = new AlertService();

    CommandInvoker invoker;

    // 1. Report/Activate the incident
    std::cout << "\n--- 1. Activating Incident ---\n";
    Command* activateIncident = new IncidentCommand(incident, "Activate fire incident INC-001");
    invoker.submit(activateIncident);

    // 2. Dispatch fire team
    std::cout << "\n--- 2. Dispatching Fire Team ---\n";
    Command* dispatchFire = new DispatchUnitCommand(fireTeam, incident, "Science Building - Floor 3");
    invoker.submit(dispatchFire);

    // 3. Secure the area
    std::cout << "\n--- 3. Securing Area ---\n";
    Command* secureArea = new SecureAreaCommand(accessSystem, "SCI-301");
    invoker.submit(secureArea);

    // 4. Issue evacuation
    std::cout << "\n--- 4. Issuing Evacuation ---\n";
    Command* evacuate = new IssueEvacuationCommand(alertService, "Science Building", 
        "EVACUATE IMMEDIATELY - Fire on 3rd floor");
    invoker.submit(evacuate);

    // Show history
    invoker.showHistory();

    // 5. Undo last action (evacuation)
    std::cout << "\n--- 5. Undoing Evacuation ---\n";
    invoker.undoLast();

    // 6. Cancel the dispatch (using CancelActionCommand)
    std::cout << "\n--- 6. Cancelling Fire Dispatch ---\n";
    Command* cancelDispatch = new CancelActionCommand(dispatchFire);
    invoker.submit(cancelDispatch);

    // Show history
    invoker.showHistory();

    // 7. Redo the evacuation
    std::cout << "\n--- 7. Redoing Evacuation ---\n";
    invoker.redoLast();

    // Show final history
    invoker.showHistory();

    delete incident;
    delete fireTeam;
    delete securityTeam;
    delete accessSystem;
    delete alertService;

    return 0;
}
#include <iostream>
#include <stdexcept>
#include "LockdownProcedures.h"
#include "CommandInvoker.h"
#include "IncidentCommand.h"
#include "DispatchUnitCommand.h"
#include "SecureAreaCommand.h"
#include "IssueEvacuationCommand.h"
#include "CancelActionCommand.h"

using namespace std;
using namespace CampusGuard;

void chemicalLeakStory(CampusIncidentCoordinator& campus, LockdownProcedures& facade) {
    cout << "\n=== STORY 1: CHEMICAL LEAK IN ENGINEERING ===\n";
    Incident incident("INC-001", "Chemical leak", "Engineering", "A laboratory spill has injured a student.");
    incident.attach(campus.getMedical());
    incident.attach(campus.getSecurity());
    incident.attach(campus.getFacilities());
    CommandInvoker commands; // Owns commands; receivers outlive this invoker.

    cout << "\n1. Report and activate the incident.\n";
    cout << incident.getDescription() << " State: " << incident.getStateName() << "\n";
    commands.submit(new IncidentCommand(&incident, "Activate Engineering chemical incident"));

    cout << "\n2. Run the containment workflow.\n";
    facade.chemicalLeakLockdown(incident.getLocation());

    cout << "\n3. Assist the student and inspect the cleared laboratory.\n";
    campus.getMedical()->stretcherAway("Student A");
    campus.getFacilities()->maintenanceCheck("Engineering");

    cout << "\n4. All clear: cancel the warning, reopen Engineering and resolve.\n";
    campus.getAlerts()->cancelAlert("Engineering");
    campus.getFacilities()->unlockAreaRequest("Engineering");
    incident.resolve();
    cout << "Result: " << incident.getId() << " = " << incident.getStateName()
         << "; Engineering = " << campus.getAccessSystem("Engineering")->getAreaState("Engineering") << "\n";
}

void activeShooterStory(CampusIncidentCoordinator& campus, LockdownProcedures& facade) {
    cout << "\n=== STORY 2: ACTIVE SHOOTER AT SCIENCE BUILDING ===\n";
    Incident incident("INC-002", "Active shooter", "Science Building", "An armed intruder has been reported.");
    // Security is dispatched by command; the other teams respond as observers.
    incident.attach(campus.getMedical());
    incident.attach(campus.getFacilities());
    CommandInvoker commands;

    cout << "\n1. Dispatch security and activate the incident.\n";
    cout << incident.getDescription() << " State: " << incident.getStateName() << "\n";
    commands.submit(new DispatchUnitCommand(campus.getSecurity(), &incident, "Science Building"));

    cout << "\n2. Start the campus lockdown through one facade call.\n";
    facade.activeShooterLockdown();

    cout << "\n3. Secure the Library as an additional precaution.\n";
    commands.submit(new SecureAreaCommand(campus.getAccessSystem("Library"), "Library"));

    cout << "\n4. Threat contained: reopen exits for a controlled evacuation.\n";
    campus.getSecurity()->arrestPerson("Suspect B");
    campus.getAccessSystem("Science Building")->unlockArea("Science Building");
    campus.getAccessSystem("Campus Perimeter")->unlockArea("Campus Perimeter");
    IssueEvacuationCommand* evacuation = new IssueEvacuationCommand(
        campus.getAlerts(), "Science Building", "Follow security to the assembly point.");
    commands.submit(evacuation);

    cout << "\n5. Evacuation complete: withdraw instructions and end lockdown.\n";
    commands.submit(new CancelActionCommand(evacuation));
    campus.getAlerts()->cancelAlert("Campus-Wide");
    campus.getFacilities()->unlockAreaRequest("Library");
    campus.getFacilities()->unlockAreaRequest("Engineering");
    campus.getSecurity()->markUnavailable(); // Security was not an observer.
    incident.resolve();

    cout << "\n6. Reject an attempt to reactivate the resolved incident.\n";
    incident.activate();
    cout << "Result: " << incident.getId() << " = " << incident.getStateName()
         << "; Science Building = " << campus.getAccessSystem("Science Building")->getAreaState("Science Building") << "\n";
}

void runStories(const string& choice) {
    // Each menu run starts with fresh objects and empty command histories.
    CampusIncidentCoordinator campus;
    LockdownProcedures facade(campus);
    if (choice == "1" || choice == "3") chemicalLeakStory(campus, facade);
    if (choice == "2" || choice == "3") activeShooterStory(campus, facade);
    cout << "\n=== SELECTED STORIES COMPLETE ===\n";
}

int main(int argc, char* argv[]) {
    try {
        // Automatic mode for Docker demonstrations and captured output.
        if (argc == 2 && string(argv[1]) == "--demo") {
            runStories("3");
            return 0;
        }
        if (argc != 1) {
            cerr << "Usage: " << argv[0] << " [--demo]\n";
            return 1;
        }

        string choice;
        while (true) {
            cout << "\n=== CAMPUSGUARD ===\n"
                 << "1. Engineering chemical leak\n"
                 << "2. Science Building active shooter\n"
                 << "3. Run both stories\n"
                 << "0. Exit\n"
                 << "Choice: ";
            if (!getline(cin, choice) || choice == "0") break;
            if (choice == "1" || choice == "2" || choice == "3") {
                runStories(choice);
            } else {
                cout << "Invalid choice. Enter 0, 1, 2 or 3.\n";
            }
        }
    } catch (const exception& error) {
        cerr << "CampusGuard error: " << error.what() << "\n";
        return 1;
    }
    return 0;

}
#include "Incident.h"

#include "AccessControlSystem.h"
#include "AccessControlAdapter.h"

#include "CommandInvoker.h"
#include "SecureAreaCommand.h"

#include "CampusIncidentCoordinator.h"
#include "MedicalTeam.h"
#include "SecurityTeam.h"
#include "FacilitiesTeam.h"
#include "AlertService.h"

#include <iostream>

using namespace CampusGuard;

int main()
{
    std::cout << "=====================================\n";
    std::cout << "CAMPUSGUARD INTEGRATION TEST\n";
    std::cout << "State + Command + Adapter\n";
    std::cout << "=====================================\n\n";


    // =====================================================
    // 1. STATE PATTERN
    // =====================================================

    std::cout << "----- STATE PATTERN -----\n";

    Incident incident(
        "I001",
        "Active Shooter",
        "Engineering",
        "Active shooter reported in Engineering"
    );

    std::cout << "Incident state: "
              << incident.getStateName()
              << "\n";

    std::cout << "Activating incident...\n";

    incident.activate();

    std::cout << "Incident state: "
              << incident.getStateName()
              << "\n\n";


    // =====================================================
    // 2. ADAPTER
    // =====================================================

    std::cout << "----- ADAPTER -----\n";

    // Concrete adapter
    AccessControlAdapter adapter;

    // Command only knows the Target interface
    AccessControlSystem* accessSystem = &adapter;

    // Give Engineering a starting state
    accessSystem->unlockArea("Engineering");

    std::cout << "Engineering initial state: "
              << accessSystem->getAreaState("Engineering")
              << "\n\n";


    // =====================================================
    // 3. COMMAND + ADAPTER
    // =====================================================

    std::cout << "----- COMMAND + ADAPTER -----\n";

    // IMPORTANT:
    // adapter was created BEFORE invoker.
    // Therefore invoker is destroyed first.
    CommandInvoker invoker;

    // CommandInvoker owns submitted commands,
    // therefore the command must be created with new.
    SecureAreaCommand* secureCommand =
        new SecureAreaCommand(
            accessSystem,
            "Engineering"
        );

    std::cout << "Submitting SecureAreaCommand...\n";

    invoker.submit(secureCommand);

    std::cout << "Engineering state after command: "
              << accessSystem->getAreaState("Engineering")
              << "\n\n";


    // =====================================================
    // 4. UNDO COMMAND
    // =====================================================

    std::cout << "----- UNDO -----\n";

    invoker.undoLast();

    std::cout << "Engineering state after undo: "
              << accessSystem->getAreaState("Engineering")
              << "\n\n";


    // =====================================================
    // 5. REDO COMMAND
    // =====================================================

    std::cout << "----- REDO -----\n";

    invoker.redoLast();

    std::cout << "Engineering state after redo: "
              << accessSystem->getAreaState("Engineering")
              << "\n\n";


    // =====================================================
    // 6. COMMAND HISTORY
    // =====================================================

    std::cout << "----- COMMAND HISTORY -----\n";

    invoker.showHistory();


    // =====================================================
    // 7. ADAPTER INVALID AREA
    // =====================================================

    std::cout << "----- INVALID AREA TEST -----\n";

    bool result = accessSystem->lockArea("Unknown");

    std::cout << "Lock unknown area result: "
              << result
              << "\n";

    std::cout << "Unknown area state: "
              << accessSystem->getAreaState("Unknown")
              << "\n\n";


    // =====================================================
    // 8. FINISH INCIDENT
    // =====================================================

    std::cout << "----- RESOLVE INCIDENT -----\n";

    incident.resolve();

    std::cout << "Incident state: "
              << incident.getStateName()
              << "\n";

    // Test invalid state transition
    std::cout << "Trying to activate resolved incident...\n";
    incident.activate();


    // =====================================================
    // 9. MEDIATOR PATTERN
    // =====================================================

    std::cout << "\n----- MEDIATOR PATTERN -----\n";

    CampusIncidentCoordinator coordinator;

    AlertService alertService;
    alertService.setMediator(&coordinator);

    MedicalTeam medTeam;
    medTeam.setMediator(&coordinator);

    SecurityTeam secTeam;
    secTeam.setMediator(&coordinator);

    FacilitiesTeam facTeam;
    facTeam.setMediator(&coordinator);

    // 1. AlertService via Mediator
    std::cout << "\n1. AlertService broadcasting alert:\n";
    alertService.broadcastAlert("Engineering", "Chemical spill reported in Chemistry Lab");

    std::cout << "\n2. AlertService cancelling alert:\n";
    alertService.cancelAlert("Engineering");

    // 2. MedicalTeam via Mediator
    std::cout << "\n3. MedicalTeam handling casualty:\n";
    medTeam.stretcherAway("Student #101");

    // 3. SecurityTeam via Mediator
    std::cout << "\n4. SecurityTeam apprehending suspect:\n";
    secTeam.arrestPerson("Trespasser #42");

    // 4. FacilitiesTeam via Mediator
    std::cout << "\n5. FacilitiesTeam maintenance check:\n";
    facTeam.maintenanceCheck("Engineering Floor 2");

    std::cout << "\n6. FacilitiesTeam requesting area unlock via Mediator:\n";
    facTeam.unlockAreaRequest("Engineering Labs");

    // 5. Colleague base updates
    std::cout << "\n7. Testing base Colleague update notification:\n";
    alertService.changed();
    medTeam.changed();

    std::cout << "\n=====================================\n";
    std::cout << "ALL INTEGRATION TESTS COMPLETE\n";
    std::cout << "=====================================\n";

    // DO NOT:
    //
    // delete secureCommand;
    //
    // CommandInvoker owns it and will delete it.

    return 0;
}
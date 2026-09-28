#include "SecureAreaCommand.h"
#include <iostream>
#include <stdexcept>

namespace CampusGuard {

SecureAreaCommand::SecureAreaCommand(AccessControlSystem* accessSystem, std::string areaId)
    : accessSystem(accessSystem), areaID(areaId), previousState("UNKNOWN") {
    if (accessSystem == nullptr) {
        throw std::invalid_argument("SecureAreaCommand requires a valid AccessControlSystem pointer.");
    }
}

void SecureAreaCommand::execute() {
    // Save previous state for undo
    previousState = accessSystem->getAreaState(areaID);
    
    std::cout << "[SecureAreaCommand] Executing lockdown for area: " << areaID << "\n";
    std::cout << "  Previous state: " << previousState << "\n";
    
    accessSystem->lockArea(areaID);
    
    std::cout << "  New state: " << accessSystem->getAreaState(areaID) << "\n";
}

void SecureAreaCommand::undo() {
    std::cout << "[SecureAreaCommand] Undoing lockdown for area: " << areaID << "\n";
    std::cout << "  Restoring state to: " << previousState << "\n";
    
   if (previousState == "LOCKED" || previousState == "Locked") {
        accessSystem->lockArea(areaID);
    }
    else if (previousState == "RESTRICTED" ||
             previousState == "Restricted") {
        accessSystem->restrictArea(areaID);
    }
    else if (previousState == "UNLOCKED" ||
             previousState == "Unlocked") {
        accessSystem->unlockArea(areaID);
    }
    else {
        std::cout << "Cannot restore an unknown previous area state.\n";
    }
    
    std::cout << "  State after undo: " << accessSystem->getAreaState(areaID) << "\n";
}

std::string SecureAreaCommand::getDescription() {
    return "Lock down area: " + areaID;
}

}
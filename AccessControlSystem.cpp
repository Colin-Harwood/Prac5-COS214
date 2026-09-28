#include "AccessControlSystem.h"
#include <iostream>

namespace CampusGuard {

bool AccessControlSystem::lockArea(std::string areaId) {
    if (areaStates.find(areaId) == areaStates.end()) {
        areaStates[areaId] = "Unlocked";
    }
    std::cout << "[AccessControlSystem] Locking area: " << areaId << "\n";
    areaStates[areaId] = "Locked";
    return true;
}

bool AccessControlSystem::unlockArea(std::string areaId) {
    if (areaStates.find(areaId) == areaStates.end()) {
        areaStates[areaId] = "Unlocked";
    }
    std::cout << "[AccessControlSystem] Unlocking area: " << areaId << "\n";
    areaStates[areaId] = "Unlocked";
    return true;
}

bool AccessControlSystem::restrictArea(std::string areaId) {
    if (areaStates.find(areaId) == areaStates.end()) {
        areaStates[areaId] = "Unlocked";
    }
    std::cout << "[AccessControlSystem] Restricting area: " << areaId << "\n";
    areaStates[areaId] = "Restricted";
    return true;
}

std::string AccessControlSystem::getAreaState(std::string areaId) {
    auto it = areaStates.find(areaId);
    if (it != areaStates.end()) {
        return it->second;
    }
    return "Unknown";
}

} 
#include "LegacyDoorSystem.h"

void CampusGuard::LegacyDoorSystem::setBuildingMode(int code, std::string mode) {
	buildingStates[code] = mode;
}

std::string CampusGuard::LegacyDoorSystem::getBuildingMode(int code) {
	std::map<int, std::string>::iterator it;

    it = buildingStates.find(code);

    if (it == buildingStates.end())
    {
        return "UNKNOWN";
    }

    return it->second;
}

#include "AccessControlAdapter.h"

CampusGuard::AccessControlAdapter::AccessControlAdapter()
{
    areaMapping["Engineering"] = 101;
}

bool CampusGuard::AccessControlAdapter::lockArea(std::string areaId) {
	
	std::map<std::string, int>::iterator it;

    it = areaMapping.find(areaId);

    if (it == areaMapping.end())
    {
        return false;
    }

    legacySystem.setBuildingMode(it->second, "LOCKED");

    return true;
}

bool CampusGuard::AccessControlAdapter::unlockArea(std::string areaId) {
	std::map<std::string, int>::iterator it;

    it = areaMapping.find(areaId);

    if (it == areaMapping.end())
    {
        return false;
    }

    legacySystem.setBuildingMode(it->second, "UNLOCKED");

    return true;
}

bool CampusGuard::AccessControlAdapter::restrictArea(std::string areaId) {
	std::map<std::string, int>::iterator it;

    it = areaMapping.find(areaId);

    if (it == areaMapping.end())
    {
        return false;
    }

    legacySystem.setBuildingMode(it->second, "RESTRICTED");

    return true;
}

std::string CampusGuard::AccessControlAdapter::getAreaState(std::string areaId) {
	std::map<std::string, int>::iterator it;

    it = areaMapping.find(areaId);

    if (it == areaMapping.end())
    {
        return "UNKNOWN";
    }

    return legacySystem.getBuildingMode(it->second);
}

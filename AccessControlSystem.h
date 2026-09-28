#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include <string>
#include <map>

namespace CampusGuard {
	class AccessControlSystem{

	private:
        std::map<std::string, std::string> areaStates;

	public:
		AccessControlSystem() = default;
		
		bool lockArea(std::string areaId);

		bool unlockArea(std::string areaId);

		bool restrictArea(std::string areaId);

		std::string getAreaState(std::string areaId);
	};
}

#endif

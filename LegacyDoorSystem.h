#ifndef LEGACYDOORSYSTEM_H
#define LEGACYDOORSYSTEM_H

#include <map>
#include <string>

namespace CampusGuard
{
	class LegacyDoorSystem {

	private:
		std::map<int, std::string> buildingStates;

	public:
		void setBuildingMode(int code, std::string mode);

		std::string getBuildingMode(int code);
};
}

#endif

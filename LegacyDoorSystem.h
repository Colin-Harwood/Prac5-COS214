#ifndef LEGACYDOORSYSTEM_H
#define LEGACYDOORSYSTEM_H

namespace CampusGuard {
	class LegacyDoorSystem {

	private:
		map<int, string> buildingStates;

	public:
		void setBuildingMode(int code, string mode);

		void getBuildingMode(int code);
	};
}

#endif

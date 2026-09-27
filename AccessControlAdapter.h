#ifndef ACCESSCONTROLADAPTER_H
#define ACCESSCONTROLADAPTER_H

namespace CampusGuard {
	class AccessControlAdapter : CampusGuard::AccessControlSystem {

	private:
		LegacyDoorSystem legacySystem;
		map<string, int> areaMapping;

	public:
		bool lockArea(string areaID);

		bool unlockArea(string areaId);

		bool restrictArea(string areaId);

		string getAreaState(string areaId);
	};
}

#endif

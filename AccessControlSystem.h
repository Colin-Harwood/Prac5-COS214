#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

namespace CampusGuard {
	class AccessControlSystem : CampusGuard::Colleague {


	public:
		bool lockArea(string areaId);

		bool unlockArea(string areaId);

		bool restrictArea(string areaId);

		string getAreaState(string areaId);
	};
}

#endif

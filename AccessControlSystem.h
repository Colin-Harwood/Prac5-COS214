#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include "Colleague.h"

class AccessControlSystem : Colleague {

	public:
		bool lockArea(string areaId);

		bool unlockArea(string areaId);

		bool restrictArea(string areaId);

		string getAreaState(string areaId);
};

#endif
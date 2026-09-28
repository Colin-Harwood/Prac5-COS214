#include "AccessControlSystem.h"

bool AccessControlSystem::lockArea(string areaId) {
	cout << "Locking " << areaId << endl;
	mediator->notify(this, "Locking area", areaId);
}

bool AccessControlSystem::unlockArea(string areaId) {
	cout << "Unlocking " << areaId << endl;
	mediator->notify(this, "Unlocking area", areaId);
}

bool AccessControlSystem::restrictArea(string areaId) {
	cout << "Restricting " << areaId << endl;
	mediator->notify(this, "Restricting area", areaId);
}

string AccessControlSystem::getAreaState(string areaId) {
	cout << "Getting the state of " << areaId << endl;
	return "Good";
}

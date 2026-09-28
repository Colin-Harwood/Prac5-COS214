#include "AccessControlSystem.h"

bool AccessControlSystem::lockArea(string areaId) {
	cout << "Locking " << areaId << endl;
	mediator->notify(this, "Locking area", areaId);
	return true;
}

bool AccessControlSystem::unlockArea(string areaId) {
	cout << "Unlocking " << areaId << endl;
	mediator->notify(this, "Unlocking area", areaId);
	return true;
}

bool AccessControlSystem::restrictArea(string areaId) {
	cout << "Restricting " << areaId << endl;
	mediator->notify(this, "Restricting area", areaId);
	return true;
}

string AccessControlSystem::getAreaState(string areaId) {
	cout << "Getting the state of " << areaId << endl;
	return "Good";
}

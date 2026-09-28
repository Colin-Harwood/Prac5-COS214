#include "AlertService.h"

void AlertService::broadcastAlert(string BuildingId, string message) {
	cout << "Alert from " << BuildingId << ": " << message << endl;
	mediator->notify(this, "New alert", BuildingId);
}

void AlertService::cancelAlert(string buildingId) {
	cout << "Alert for building " << buildingId << " has been cancelled" << endl;
	mediator->notify(this, "Alert cancelled", buildingId);
}
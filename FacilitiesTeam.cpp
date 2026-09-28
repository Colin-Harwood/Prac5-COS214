#include "FacilitiesTeam.h"

void FacilitiesTeam::unlockAreaRequest(string area) {
    cout << "Facility team " << id << " requesting area " << area << " to be unlocked." << endl;
    mediator->notify(this, "unlockRequest", area);
}

void FacilitiesTeam::maintenanceCheck(string area) {
    cout << "Facility team " << id << " checking area " << area << endl;
    cout << "Check complete by " << id << ". Area is good" << endl;
}
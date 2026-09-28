#include "FacilitiesTeam.h"

void FacilitiesTeam::lockAreaRequest(std::string area) {
    std::cout << "Facility team " << id << " requesting area " << area << " to be locked.\n";
    if (mediator != nullptr) {
        mediator->notify(this, "lockRequest", area);
    }
}

void FacilitiesTeam::unlockAreaRequest(string area) {
    cout << "Facility team " << id << " requesting area " << area << " to be unlocked." << endl;
    mediator->notify(this, "unlockRequest", area);
}

void FacilitiesTeam::maintenanceCheck(string area) {
    cout << "Facility team " << id << " checking area " << area << endl;
    cout << "Check complete by " << id << ". Area is good" << endl;
}
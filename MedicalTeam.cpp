#include "MedicalTeam.h"

void MedicalTeam::stretcherAway(string person) {
    cout << "Taking person " << person << " to an ambulance" << endl;
    mediator->notify(this, "Stretcher", person);
};
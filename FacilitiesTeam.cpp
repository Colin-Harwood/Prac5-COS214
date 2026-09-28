#include "FacilitiesTeam.h"
#include "Incident.h"
#include <iostream>

namespace CampusGuard
{

    void FacilitiesTeam::update(Incident *incident)
    {
        std::cout << "[FacilitiesTeam " << getId() << "] Incident "
                  << incident->getId() << " is " << incident->getStateName() << "\n";
        if (incident->getStateName() == "Active")
        {
            std::cout << "Shutting off utilities / HVAC in "
                      << incident->getLocation() << ".\n";
        }
    }

}
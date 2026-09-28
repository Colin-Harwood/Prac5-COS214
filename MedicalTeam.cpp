#include "MedicalTeam.h"
#include "Incident.h"
#include <iostream>

namespace CampusGuard
{

    void MedicalTeam::update(Incident *incident)
    {
        std::cout << "[MedicalTeam " << getId() << "] check for incident "
                  << incident->getId() << " (" << incident->getStateName() << ")\n";
        if (incident->getStateName() == "Active")
        {
            std::cout << "Preparing medical supplies and stretchers.\n";
        }
    }

}
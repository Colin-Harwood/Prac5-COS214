#include "SecurityTeam.h"
#include "Incident.h"
#include <iostream>

namespace CampusGuard {

void SecurityTeam::update(Incident* incident) {
    std::cout << "[SecurityTeam " << getId() << "] Incident "
              << incident->getId() << " is " << incident->getStateName() << "\n";
    if (incident->getStateName() == "Active") {
        std::cout << "Securing perimeter around " << incident->getLocation() << ".\n";
    }
}

}
#include "ResponseUnit.h"
#include "Incident.h"
#include <iostream>

namespace CampusGuard {

void ResponseUnit::dispatchTo(std::string destination) {
    std::cout << "[ResponseUnit " << id << " (" << type << ")] Dispatching to: "
              << destination << "\n";
    status = "Dispatched to " + destination;
}

void ResponseUnit::markUnavailable() {
    std::cout << "[ResponseUnit " << id << " (" << type << ")] Marked as unavailable.\n";
    status = "Unavailable";
}

void ResponseUnit::update(Incident* incident) {
    std::cout << "[ResponseUnit " << id << " (" << type << ")] Received notification:\n"
              << "    Incident " << incident->getId()
              << " (" << incident->getType() << ") at " << incident->getLocation()
              << " is now " << incident->getStateName() << "\n";

    if (incident->getStateName() == "Active") {
        std::cout << "    → " << type << " responding automatically.\n";
        dispatchTo(incident->getLocation());
    } else if (incident->getStateName() == "Resolved") {
        std::cout << "    → " << type << " standing down.\n";
        markUnavailable();
    }
}

} 
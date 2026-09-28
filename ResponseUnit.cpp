#include "ResponseUnit.h"
#include <iostream>

void CampusGuard::ResponseUnit::dispatchTo(std::string destination) {
	std::cout << "[ResponseUnit " << id << " (" << type << ")] Dispatching to: " << destination << "\n";
    status = "Dispatched to " + destination;
}

void CampusGuard::ResponseUnit::markUnavailable() {
	std::cout << "[ResponseUnit " << id << " (" << type << ")] Marked as unavailable.\n";
    status = "Unavailable";
}

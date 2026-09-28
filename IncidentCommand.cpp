#include "IncidentCommand.h"
#include <iostream>
namespace CampusGuard {
	IncidentCommand::IncidentCommand(Incident* incident, std::string description)
		: incident(incident), description(description) {
		if (incident == nullptr) {
			throw std::invalid_argument("IncidentCommand requires a valid Incident pointer.");
		}
	}

	void IncidentCommand::execute() {
		std::cout << "[IncidentCommand] Executing: " << description << "\n";
		std::cout << "  Incident ID: " << incident->getId() << "\n";
		std::cout << "  Current state: " << incident->getStateName() << "\n";
		incident->activate();
		std::cout << "  New state: " << incident->getStateName() << "\n";
	}

	void IncidentCommand::undo() {
		std::cout << "[IncidentCommand] Undoing: " << description << "\n";
		std::cout << "  Incident ID: " << incident->getId() << "\n";
		incident->resolve();
		std::cout << "  State after undo: " << incident->getStateName() << "\n";
	}

	std::string IncidentCommand::getDescription() {
		return this->description;
	}
}
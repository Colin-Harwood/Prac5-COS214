#include "DispatchUnitCommand.h"
#include <iostream>

namespace CampusGuard
{

	DispatchUnitCommand::DispatchUnitCommand(ResponseUnit *responder, Incident *incident, std::string destination)
		: responder(responder), incident(incident), destination(destination)
	{
		if (responder == nullptr || incident == nullptr)
		{
			throw std::invalid_argument("DispatchUnitCommand requires valid responder and incident pointers.");
		}
	}

	void DispatchUnitCommand::execute()
	{
		std::cout << "[DispatchUnitCommand] Executing dispatch\n";
		std::cout << "  Incident: " << incident->getId() << " at " << incident->getLocation() << "\n";
		std::cout << "  Unit: " << responder->getId() << " (" << responder->getType() << ")\n";
		std::cout << "  Destination: " << destination << "\n";

		responder->dispatchTo(destination);
		incident->activate();

		std::cout << "  Incident state: " << incident->getStateName() << "\n";
	}

	void DispatchUnitCommand::undo()
	{
		std::cout << "[DispatchUnitCommand] Undoing dispatch\n";
		std::cout << "  Recalling unit " << responder->getId() << " from " << destination << "\n";

		responder->markUnavailable();

		std::cout << "  Incident state after undo: " << incident->getStateName() << "\n";
	}

	std::string DispatchUnitCommand::getDescription()
	{
		return "Dispatch unit " + responder->getId() + " to " + destination +
			   " for incident " + incident->getId();
	}

}
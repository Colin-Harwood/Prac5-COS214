#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include "Incident.h"
#include "ResponseUnit.h"
#include <string>

namespace CampusGuard {
	class DispatchUnitCommand : public Command {

	private:
		ResponseUnit* responder;
		Incident* incident;
		std::string destination;

	public:
		DispatchUnitCommand(ResponseUnit* responder, Incident* incident, std::string destination);
		~DispatchUnitCommand() override = default;

		void execute();
		void undo();
		std::string getDescription();
	};
}

#endif

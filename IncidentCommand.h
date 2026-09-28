#ifndef INCIDENTCOMMAND_H
#define INCIDENTCOMMAND_H

#include "Command.h"
#include "Incident.h"
#include <string>

namespace CampusGuard {
	class IncidentCommand : CampusGuard::Command {

	protected:
		Incident* incident;
		std::string description;

	public:
		IncidentCommand(Incident* incident, std::string description);
		~IncidentCommand() override = default;

		void execute() override;

		void undo() override;

		std::string getDescription() override;
	};
}

#endif

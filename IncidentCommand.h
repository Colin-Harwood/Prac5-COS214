#ifndef INCIDENTCOMMAND_H
#define INCIDENTCOMMAND_H

namespace CampusGuard {
	class IncidentCommand : CampusGuard::Command {

	protected:
		Incident* incident;
		string description;

	public:
		IncidentCommand(Incident* incident, string description);

		void execute();

		void undo();

		string getDescription();
	};
}

#endif

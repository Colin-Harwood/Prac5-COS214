#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

namespace CampusGuard {
	class DispatchUnitCommand : CampusGuard::Command {

	private:
		ResponseUnit* responder;
		Incident* incident;
		string destination;

	public:
		DispatchUnitCommand(ResponseUnit* responder, incident* incident, string destination);

		void execute();

		void undo();

		string getDescription();
	};
}

#endif

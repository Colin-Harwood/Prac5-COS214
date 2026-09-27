#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

namespace CampusGuard {
	class CancelActionCommand : CampusGuard::Command {

	public:
		CampusGuard::Command* commandToCancel;

		CancelActionCommand(CampusGuard::Command* commandToCancel);

		void execute();

		void undo();

		string getDescription();
	};
}

#endif

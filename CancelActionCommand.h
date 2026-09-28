#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

#include "Command.h"
#include <string>

namespace CampusGuard
{
	class CancelActionCommand : public Command
	{
	private:
		Command *commandToCancel;

	public:
		CancelActionCommand(Command *commandToCancel);
		~CancelActionCommand() override = default;

		void execute() override;

		void undo() override;

		std::string getDescription() override;
	};
}

#endif

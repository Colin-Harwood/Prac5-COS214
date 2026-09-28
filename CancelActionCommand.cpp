#include "CancelActionCommand.h"
#include <iostream>

namespace CampusGuard
{

	CancelActionCommand::CancelActionCommand(Command *commandToCancel)
		: commandToCancel(commandToCancel)
	{
		if (commandToCancel == nullptr)
		{
			throw std::invalid_argument("CancelActionCommand requires a valid Command pointer.");
		}
	}

	void CancelActionCommand::execute()
	{
		std::cout << "[CancelActionCommand] Cancelling action: "
				  << commandToCancel->getDescription() << "\n";
		commandToCancel->undo();
	}

	void CancelActionCommand::undo()
	{
		std::cout << "[CancelActionCommand] Restoring cancelled action: "
				  << commandToCancel->getDescription() << "\n";
		commandToCancel->execute();
	}

	std::string CancelActionCommand::getDescription()
	{
		return "Cancel: " + commandToCancel->getDescription();
	}

}
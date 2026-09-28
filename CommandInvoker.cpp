#include "CommandInvoker.h"
#include <iostream>
namespace CampusGuard
{

	CommandInvoker::~CommandInvoker()
	{
		for (Command *cmd : History)
		{
			delete cmd;
		}
		for (Command *cmd : redoStack)
		{
			delete cmd;
		}
	}

	void CommandInvoker::submit(Command *command)
	{
		if (command == nullptr)
		{
			std::cout << "[CommandInvoker] Cannot submit null command.\n";
			return;
		}

		command->execute();
		History.push_back(command);

		// Clear redo stack since a new command was executed
		for (Command *cmd : redoStack)
		{
			delete cmd;
		}
		redoStack.clear();

		std::cout << "[CommandInvoker] Executed: " << command->getDescription() << "\n";
	}

	void CommandInvoker::undoLast()
	{
		if (History.empty())
		{
			std::cout << "[CommandInvoker] Nothing to undo.\n";
			return;
		}

		Command *lastCommand = History.back();
		History.pop_back();

		lastCommand->undo();
		redoStack.push_back(lastCommand);

		std::cout << "[CommandInvoker] Undone: " << lastCommand->getDescription() << "\n";
	}

	void CommandInvoker::redoLast()
	{
		if (redoStack.empty())
		{
			std::cout << "[CommandInvoker] Nothing to redo.\n";
			return;
		}

		Command *command = redoStack.back();
		redoStack.pop_back();

		command->execute();
		History.push_back(command);

		std::cout << "[CommandInvoker] Redone: " << command->getDescription() << "\n";
	}

	void CommandInvoker::showHistory()
	{
		std::cout << "\n=== Command History ===\n";
		if (History.empty())
		{
			std::cout << "  (no commands executed)\n";
		}
		else
		{
			for (size_t i = 0; i < History.size(); ++i)
			{
				std::cout << "  " << (i + 1) << ". " << History[i]->getDescription() << "\n";
			}
		}

		std::cout << "\n=== Redo Stack ===\n";
		if (redoStack.empty())
		{
			std::cout << "  (empty)\n";
		}
		else
		{
			for (size_t i = 0; i < redoStack.size(); ++i)
			{
				std::cout << "  " << (i + 1) << ". " << redoStack[i]->getDescription() << "\n";
			}
		}
		std::cout << "======================\n\n";
	}
}

#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H

#include <vector>
#include <string>
#include "Command.h"

namespace CampusGuard
{
	class CommandInvoker
	{
	private:
		std::vector<Command *> History;
		std::vector<Command *> redoStack;

	public:
		CommandInvoker() = default;

		~CommandInvoker();

		void submit(Command *command);

		void undoLast();

		void redoLast();

		void showHistory();
	};
}

#endif

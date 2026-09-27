#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H

namespace CampusGuard {
	class CommandInvoker {

	private:
		vector<Command*> History;
		vector<Command*> redoStack;

	public:
		void submit(Command* command);

		void undoLast();

		void redoLast();

		void showHistory();
	};
}

#endif

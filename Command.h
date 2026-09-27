#ifndef COMMAND_H
#define COMMAND_H

namespace CampusGuard {
	class Command {


	public:
		void execute();

		void undo();

		string getDescription();
	};
}

#endif

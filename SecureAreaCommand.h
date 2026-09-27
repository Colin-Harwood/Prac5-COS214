#ifndef SECUREAREACOMMAND_H
#define SECUREAREACOMMAND_H

namespace CampusGuard {
	class SecureAreaCommand : CampusGuard::Command {

	private:
		AccessControlSystem* accessSystem;
		string areaID;
		string previousState;

	public:
		SecureAreaCommand(AccessControlSystem* accessSystem, string areaId);

		void execute();

		void undo();

		string getDescription();
	};
}

#endif

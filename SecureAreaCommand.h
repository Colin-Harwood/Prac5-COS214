#ifndef SECUREAREACOMMAND_H
#define SECUREAREACOMMAND_H

#include "Command.h"
#include "AccessControlSystem.h"
#include <string>

namespace CampusGuard {
	class SecureAreaCommand : public Command {

	private:
		AccessControlSystem* accessSystem;
		std::string areaID;
		std::string previousState;

	public:
		SecureAreaCommand(AccessControlSystem* accessSystem, std::string areaId);
		~SecureAreaCommand() override = default;

		void execute() override;

		void undo() override;

		std::string getDescription() override;
	};
}

#endif

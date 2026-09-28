#ifndef ISSUEEVACUATIONCOMMAND_H
#define ISSUEEVACUATIONCOMMAND_H

#include "Command.h"
#include "AlertService.h"
#include <string>

namespace CampusGuard {
	class IssueEvacuationCommand : public Command {

	private:
		AlertService* alertService;
		std::string buildingId;
		std::string message;

	public:
		IssueEvacuationCommand(AlertService* alertService, std::string buildingId, std::string message);

		~IssueEvacuationCommand() override = default;

		void execute() override;

		void undo() override;

		std::string getDescription() override;
	};
}

#endif

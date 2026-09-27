#ifndef ISSUEEVACUATIONCOMMAND_H
#define ISSUEEVACUATIONCOMMAND_H

namespace CampusGuard {
	class IssueEvacuationCommand : CampusGuard::Command {

	private:
		AlertService* alertService;
		string buildingId;
		string message;

	public:
		IssueEvacuationCommand(AlertService* alertService, string buildingId, string message);

		void execute();

		void undo();

		string getDescription();
	};
}

#endif

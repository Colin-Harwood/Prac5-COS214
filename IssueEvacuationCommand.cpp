#include "IssueEvacuationCommand.h"
#include <iostream>

namespace CampusGuard {

IssueEvacuationCommand::IssueEvacuationCommand(AlertService* alertService, std::string buildingId, std::string message)
    : alertService(alertService), buildingId(buildingId), message(message) {
    if (alertService == nullptr) {
        throw std::invalid_argument("IssueEvacuationCommand requires a valid AlertService pointer.");
    }
}

void IssueEvacuationCommand::execute() {
    std::cout << "[IssueEvacuationCommand] Issuing evacuation for building: " << buildingId << "\n";
    alertService->broadcastAlert(buildingId, message);
}

void IssueEvacuationCommand::undo() {
    std::cout << "[IssueEvacuationCommand] Cancelling evacuation for building: " << buildingId << "\n";
    alertService->cancelAlert(buildingId);
}

std::string IssueEvacuationCommand::getDescription() {
    return "Issue evacuation for building " + buildingId + ": " + message;
}

}
#include "AlertService.h"
#include <iostream>

namespace CampusGuard {

void AlertService::broadcastAlert(std::string buildingId, std::string message) {
    std::cout << "[AlertService] Broadcasting to building " << buildingId << ":\n";
    std::cout << "  >>> " << message << " <<<\n";
}

void AlertService::cancelAlert(std::string buildingId) {
    std::cout << "[AlertService] Cancelling alert for building " << buildingId << "\n";
}

}
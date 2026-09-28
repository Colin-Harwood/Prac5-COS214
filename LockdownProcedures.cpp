#include "LockdownProcedures.h"
#include <iostream>

namespace CampusGuard {
LockdownProcedures::LockdownProcedures()
    : accessControl(new AccessControlSystem()),
      alertService(new AlertService()),
      coordinator(new CampusIncidentCoordinator()),
      ownsResources(true)
{
    alertService->setMediator(coordinator);
    accessControl->setMediator(coordinator);
}

LockdownProcedures::LockdownProcedures(AccessControlSystem* ac, AlertService* as, CampusIncidentCoordinator* coord)
    : accessControl(ac),
      alertService(as),
      coordinator(coord),
      ownsResources(false)
{
}

LockdownProcedures::LockdownProcedures(
    CampusIncidentCoordinator& campus
)
    : accessControl(campus.getAccessSystem("Science Building")),
      alertService(campus.getAlerts()),
      coordinator(&campus),
      ownsResources(false) {
}

LockdownProcedures::~LockdownProcedures() {
    if (ownsResources) {
        delete accessControl;
        delete alertService;
        delete coordinator;
    }
}
void LockdownProcedures::activeShooterLockdown() {
    std::cout << "[LockdownFacade] === INITIATING ACTIVE SHOOTER LOCKDOWN ===\n";
    alertService->broadcastAlert("Campus-Wide", "EMERGENCY: Active Shooter reported! Seek shelter immediately.");
    std::cout << "[LockdownFacade] Locking all critical campus access points...\n";
    accessControl->lockArea("Campus Perimeter");
    accessControl->lockArea("Engineering");
    accessControl->lockArea("Science Building");
    std::cout << "[LockdownFacade] Active shooter lockdown protocols completed.\n";
}
void LockdownProcedures::chemicalLeakLockdown(std::string areaId) {
    std::cout << "[LockdownFacade] === INITIATING CHEMICAL LEAK LOCKDOWN FOR: " << areaId << " ===\n";
    alertService->broadcastAlert(areaId, "HAZMAT ALERT: Toxic chemical leak detected. Evacuate immediately.");
    std::cout << "[LockdownFacade] Sealing and restricting hazardous area: " << areaId << "...\n";
    accessControl->restrictArea(areaId);
    accessControl->lockArea(areaId);
    std::cout << "[LockdownFacade] Chemical leak containment protocols completed.\n";
}

}
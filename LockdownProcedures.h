#ifndef LOCKDOWNPROCEDURES_H
#define LOCKDOWNPROCEDURES_H
#include <string>
#include "AccessControlSystem.h"
#include "AlertService.h"
#include "CampusIncidentCoordinator.h"
namespace CampusGuard {
	class LockdownProcedures {
	private:
		AccessControlSystem* accessControl;
		AlertService* alertService;
		CampusIncidentCoordinator* coordinator;
		bool ownsResources;
	public:
		LockdownProcedures();
		LockdownProcedures(AccessControlSystem* ac, AlertService* as, CampusIncidentCoordinator* coord);
		~LockdownProcedures();
		void activeShooterLockdown();
		void chemicalLeakLockdown(std::string areaId);
	};
}
#endif
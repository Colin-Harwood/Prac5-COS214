#ifndef CAMPUSINCIDENTCOORDINATOR_H
#define CAMPUSINCIDENTCOORDINATOR_H

#include "IncidentCoordinator.h"
#include "ResponseUnit.h"
#include "MedicalTeam.h"
#include "SecurityTeam.h"
#include "FacilitiesTeam.h"
#include "AccessControlSystem.h"
#include "AlertService.h"
#include <string>

using namespace CampusGuard;
using namespace std;

class CampusIncidentCoordinator : public IncidentCoordinator {
    private:
        ResponseUnit** teams;
        AccessControlSystem* accessSystem;
        AlertService* alertService;
        AccessControlSystem* legacyAccessSystem;
    public:
        void notify(Colleague* team, string type, string location);
        CampusIncidentCoordinator();
        ~CampusIncidentCoordinator();

        MedicalTeam* getMedical();
    SecurityTeam* getSecurity();
    FacilitiesTeam* getFacilities();
    AlertService* getAlerts();
    AccessControlSystem* getAccessSystem(string area);
};

#endif
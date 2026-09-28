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

class CampusIncidentCoordinator : public IncidentCoordinator {
    private:
        ResponseUnit** teams;
        AccessControlSystem* accessSystem;
        AlertService* alertService;
    public:
        void notify(Colleague* team, string type, string location);
        CampusIncidentCoordinator();
        ~CampusIncidentCoordinator();
};

#endif
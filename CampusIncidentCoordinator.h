#ifndef CAMPUSINCIDENTCOORDINATOR_H
#define CAMPUSINCIDENTCOORDINATOR_H

#include "IncidentCoordinator.h"

class CampusIncidentCoordinator : IncidentCoordinator {
    private:
        Colleague** teams;
    public:
        void notify(Colleague* team, string type, string location);
};

#endif
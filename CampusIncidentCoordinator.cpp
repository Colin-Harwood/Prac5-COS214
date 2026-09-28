#include "CampusIncidentCoordinator.h"
#include "AccessControlAdapter.h"

void CampusIncidentCoordinator::notify(Colleague* team, string type, string location) {
	if (type == "New alert") {
		cout << "New alert for " << location << endl;
	} else if (type == "Alert cancelled") {
		cout << "Alert cancellation for " << location << endl;
	} else if (type == "Locking area") {
		teams[2]->dispatchTo(location);
		cout << "Area " << location << " is locked" << endl;
	} else if (type == "Unlocking area") {
		teams[2]->dispatchTo(location);
		cout << "Area " << location << " is unlocked" << endl;
	} else if (type == "Restricting area") {
		teams[1]->dispatchTo(location);
		cout << "Area " << location << " is restricted" << endl;
	} else if (type == "unlockRequest") {
		accessSystem->unlockArea(location);
	} else if (type == "Arresting") {
		cout << "Person " << location << " was arrested" << endl;
	} else if (type == "Stretcher") {
		cout << "Person " << location << " was taken out on a stretcher" << endl;
	}
}

CampusIncidentCoordinator::CampusIncidentCoordinator() {
	teams = new ResponseUnit*[3];
	teams[0] = new MedicalTeam();
	teams[1] = new SecurityTeam();
	teams[2] = new FacilitiesTeam();

	accessSystem = new AccessControlSystem();
	legacyAccessSystem = new AccessControlAdapter();
	alertService = new AlertService();

	teams[0]->setMediator(this);
	teams[1]->setMediator(this);
	teams[2]->setMediator(this);
	accessSystem->setMediator(this);
	legacyAccessSystem->setMediator(this);
	alertService->setMediator(this);
}

CampusIncidentCoordinator::~CampusIncidentCoordinator() {
    if (teams) {
        delete teams[0];
        delete teams[1];
        delete teams[2];
        delete[] teams;
    }
    delete accessSystem;
	delete legacyAccessSystem;
    delete alertService;
}

MedicalTeam* CampusIncidentCoordinator::getMedical() {
    return static_cast<MedicalTeam*>(teams[0]);
}

SecurityTeam* CampusIncidentCoordinator::getSecurity() {
    return static_cast<SecurityTeam*>(teams[1]);
}

FacilitiesTeam* CampusIncidentCoordinator::getFacilities() {
    return static_cast<FacilitiesTeam*>(teams[2]);
}

AlertService* CampusIncidentCoordinator::getAlerts() {
    return alertService;
}

AccessControlSystem*
CampusIncidentCoordinator::getAccessSystem(string area) {
    if (area == "Engineering") {
        return legacyAccessSystem;
    }

    return accessSystem;
}

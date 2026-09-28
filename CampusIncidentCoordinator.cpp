#include "CampusIncidentCoordinator.h"

void CampusIncidentCoordinator::notify(Colleague* team, string type, string location) {
	if (type == "New alert") {
		cout << "New alert for " << location;
	} else if (type == "Alert cancelled") {
		cout << "Alert cancellation for " << location;
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
	alertService = new AlertService();
}

CampusIncidentCoordinator::~CampusIncidentCoordinator() {
    if (teams) {
        delete teams[0];
        delete teams[1];
        delete teams[2];
        delete[] teams;
    }
    delete accessSystem;
    delete alertService;
}
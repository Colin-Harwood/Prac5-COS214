#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

namespace CampusGuard {
	class MedicalTeam : CampusGuard::ResponseUnit {

	private:
		string id;
		string type;
		string available;
	};
}

#endif

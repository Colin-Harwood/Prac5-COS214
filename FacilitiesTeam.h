#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H

#include "ResponseUnit.h"

using namespace std;

class FacilitiesTeam : public ResponseUnit {
	public:
	FacilitiesTeam()
        : ResponseUnit("FAC-01", "Facilities") {
    }
		void lockAreaRequest(string area);
		void unlockAreaRequest(string area);
		void maintenanceCheck(string area);
};

#endif

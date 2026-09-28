#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H

#include "ResponseUnit.h"

class FacilitiesTeam : public ResponseUnit {
	public:
		void lockAreaRequest(string area);
		void unlockAreaRequest(string area);
		void maintenanceCheck(string area);
};

#endif

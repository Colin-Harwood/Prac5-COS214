#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "ResponseUnit.h"

using namespace std;

class MedicalTeam : public ResponseUnit {
	public:
	MedicalTeam()
        : ResponseUnit("MED-01", "Medical") {
    }
		void stretcherAway(string person);
};

#endif

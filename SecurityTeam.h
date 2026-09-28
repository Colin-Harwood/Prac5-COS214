#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseUnit.h"

using namespace std;

class SecurityTeam : public ResponseUnit {
	public:
	SecurityTeam()
        : ResponseUnit("SEC-01", "Security") {
    }

		void arrestPerson(string person);
};

#endif

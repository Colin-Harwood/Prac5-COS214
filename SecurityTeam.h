#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseUnit.h"

using namespace std;

class SecurityTeam : public ResponseUnit {
	public:
		void arrestPerson(string person);
};

#endif

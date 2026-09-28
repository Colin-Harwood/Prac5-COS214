#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseUnit.h"

class SecurityTeam : public ResponseUnit {
	public:
		void arrestPerson(string person);
};

#endif

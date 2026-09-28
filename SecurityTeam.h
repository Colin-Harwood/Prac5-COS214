#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseUnit.h"

namespace CampusGuard
{
	class SecurityTeam : public ResponseUnit
	{
	public:
		SecurityTeam(std::string id)
			: ResponseUnit(id, "Security Team") {}

		void update(Incident *incident) override;
	};
}
#endif
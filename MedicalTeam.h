#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "ResponseUnit.h"

namespace CampusGuard
{
	class MedicalTeam : public ResponseUnit
	{
	public:
		MedicalTeam(std::string id)
			: ResponseUnit(id, "Medical Team") {}

		void update(Incident *incident) override;
	};
}
#endif
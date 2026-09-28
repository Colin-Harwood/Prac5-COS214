#ifndef ACCESSCONTROLADAPTER_H
#define ACCESSCONTROLADAPTER_H

#include "AccessControlSystem.h"
#include "LegacyDoorSystem.h"

#include <map>
#include <string>

namespace CampusGuard
{
	class AccessControlAdapter : public AccessControlSystem {

	private:
		LegacyDoorSystem legacySystem;
		std::map<std::string, int> areaMapping;
	public:
		AccessControlAdapter();
		bool lockArea(std::string areaId) override;

		bool unlockArea(std::string areaId) override;

		bool restrictArea(std::string areaId) override;

		std::string getAreaState(std::string areaId) override;
	};

}
	
#endif

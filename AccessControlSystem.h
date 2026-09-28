#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include <string>
#include <map>
#include "Colleague.h"

namespace CampusGuard
{
	class AccessControlSystem : public Colleague{

	private:
        std::map<std::string, std::string> areaStates;

	public:
		AccessControlSystem() = default;
		
		virtual bool lockArea(std::string areaId);

		virtual bool unlockArea(std::string areaId);

		virtual bool restrictArea(std::string areaId);

		virtual std::string getAreaState(std::string areaId);
		virtual ~AccessControlSystem() {}
	};
}
#endif
#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include <string>

namespace CampusGuard
{
	class AccessControlSystem{
	public:
		AccessControlSystem() = default;
		
		virtual bool lockArea(std::string areaId) = 0;

		virtual bool unlockArea(std::string areaId) = 0;

		virtual bool restrictArea(std::string areaId) = 0;

		virtual std::string getAreaState(std::string areaId) =0;
		virtual ~AccessControlSystem() {}
	};
}
#endif

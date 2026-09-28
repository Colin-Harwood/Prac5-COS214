#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include <string>
#include <map>

namespace CampusGuard
{
	class AccessControlSystem{

	private:
        std::map<std::string, std::string> areaStates;

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

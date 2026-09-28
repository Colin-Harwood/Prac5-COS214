#ifndef ALERTSERVICE_H
#define ALERTSERVICE_H

#include <string>

namespace CampusGuard {
	class AlertService{


	public:
		AlertService() = default;

		void broadcastAlert(std::string BuildingId, std::string message);

		void cancelAlert(std::string buildingId);
	};
}

#endif

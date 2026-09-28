#ifndef ALERTSERVICE_H
#define ALERTSERVICE_H

#include <string>
#include "Colleague.h"
using namespace std;

namespace CampusGuard {
	class AlertService : public Colleague{

	public:
		AlertService() = default;

		void broadcastAlert(std::string BuildingId, std::string message);

		void cancelAlert(std::string buildingId);
	};
}

#endif

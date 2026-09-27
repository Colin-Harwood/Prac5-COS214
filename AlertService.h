#ifndef ALERTSERVICE_H
#define ALERTSERVICE_H

namespace CampusGuard {
	class AlertService : CampusGuard::Colleague {


	public:
		void broadcastAlert(string BuildingId, string message);

		void cancelAlert(string buildingId);
	};
}

#endif

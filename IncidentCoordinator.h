#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

namespace CampusGuard {
	class IncidentCoordinator {


	public:
		virtual void notify(Colleauge* team, string type, string location) = 0;
	};
}

#endif

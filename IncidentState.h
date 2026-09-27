#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

namespace CampusGuard {
	class IncidentState {


	public:
		void activate(CampusGuard::Incident* incident);

		void resolve(CampusGuard::Incident* incident);

		string getName();
	};
}

#endif

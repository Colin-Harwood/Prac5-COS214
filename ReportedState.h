#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

namespace CampusGuard {
	class ReportedState : CampusGuard::IncidentState {


	public:
		void activate(CampusGuard::Incident* incident);

		void resolve(CampusGuard::Incident* incident);

		string getName();
	};
}

#endif

#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

namespace CampusGuard {
	class ActiveState : CampusGuard::IncidentState {


	public:
		void activate(CampusGuard::Incident* incident);

		void resolve(CampusGuard::Incident* incident);

		string getName();
	};
}

#endif

#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

namespace CampusGuard {
	class ResolvedState : CampusGuard::IncidentState {


	public:
		void activate(CampusGuard::Incident* incident);

		void resolve(CampusGuard::Incident* incident);

		string getName();
	};
}

#endif

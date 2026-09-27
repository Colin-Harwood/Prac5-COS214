#ifndef COLLEAGUE_H
#define COLLEAGUE_H

namespace CampusGuard {
	class Colleague {

	private:
		CampusGuard::IncidentCoordinator* mediator;

	public:
		void changed();
	};
}

#endif

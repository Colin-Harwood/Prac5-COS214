#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "IncidentCoordinator.h"

#include <iostream>

class Colleague {

protected:
	IncidentCoordinator* mediator;

public:
	Colleague(IncidentCoordinator* mediator = nullptr) : mediator(mediator) {}
	void setMediator(IncidentCoordinator* m) { mediator = m; }
	void changed();
};

#endif

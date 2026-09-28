#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "IncidentCoordinator.h"

class Colleague {

private:
	IncidentCoordinator* mediator;

public:
	void changed();
};

#endif

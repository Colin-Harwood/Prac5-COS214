#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "IncidentCoordinator.h"

#include <iostream>

class Colleague {

protected:
	IncidentCoordinator* mediator;

public:
	void changed();
};

#endif

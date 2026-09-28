#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class IncidentCoordinator;

#include <iostream>

class Colleague {

protected:
	IncidentCoordinator* mediator;

public:
	void changed();
};

#endif

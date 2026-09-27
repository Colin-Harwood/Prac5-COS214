#include "ActiveState.h"
#include "Incident.h"
#include "ResolvedState.h"

#include <iostream>

void ActiveState::activate(Incident* incident)
{
    std::cout << "Incident is already active" << std::endl;
}

void ActiveState::resolve(Incident* incident)
{
    incident->setState(new ResolvedState());
}

std::string ActiveState::getName()
{
    return "Active";
}

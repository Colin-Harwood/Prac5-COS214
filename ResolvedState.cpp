#include "ResolvedState.h"
#include "Incident.h"

#include <iostream>

void ResolvedState::activate(Incident* incident)
{
    std::cout << "Resolved incident cannot be active" << std::endl;
}

void ResolvedState::resolve(Incident* incident)
{
    std::cout << "Incident is already resolved" << std::endl;
}
    
std::string ResolvedState::getName()
{
    return "Resolved";
}

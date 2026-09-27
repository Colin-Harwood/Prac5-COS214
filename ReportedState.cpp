#include "ReportedState.h"
#include "Incident.h"
#include "ActiveState.h"

#include <iostream>

void ReportedState::activate(Incident* incident) 
{
    incident->setState(new ActiveState());
}    

void ReportedState::resolve(Incident* incident)
{
    std::cout << "Incidents that have not been activated cannot be resolved" << std::endl;
}    

std::string ReportedState::getName()
{
    return "Reported";
}
#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"

Incident::Incident(std::string id, std::string type, std::string location,std::string description) :
id(id), type(type), location(location), description(description) {
    state = new ReportedState();
} // every new incident starts as a reported state

Incident::~Incident() 
{
    delete state;
}

void Incident::activate()
{
    state->activate(this);
}
    
void Incident::resolve()
{
    state->resolve(this);
}    

void Incident::setState(IncidentState* newState)
{
    // reassign state then delete old state
    IncidentState* oldState = state;
    state = newState;
    delete oldState;
}    

std::string Incident::getStateName()
{
    return state->getName();
}
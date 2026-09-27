#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>

class Incident;

class IncidentState
{
public:
    virtual void activate(Incident* incident) = 0;
    virtual void resolve(Incident* incident) = 0;
    virtual std::string getName() = 0;

    virtual ~IncidentState() {}
};

#endif

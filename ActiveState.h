#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

#include "IncidentState.h"

class ActiveState : public IncidentState
{
public:
    void activate(Incident* incident) override;
    void resolve(Incident* incident) override;

    std::string getName() override;
};

#endif

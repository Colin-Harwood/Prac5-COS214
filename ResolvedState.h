#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"

#include <iostream>

class ResolvedState : public IncidentState
{
public:
    void activate(Incident* incident) override;
    void resolve(Incident* incident) override;
    std::string getName() override;
};

#endif
#ifndef OBSERVER_H
#define OBSERVER_H

class Incident;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(Incident* incident) = 0;
};

#endif
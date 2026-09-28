#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

#endif
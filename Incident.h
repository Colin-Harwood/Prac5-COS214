#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include <vector>
#include "Subject.h"

class IncidentState;

class Incident : public Subject
{
private:
    std::string id;
    std::string type;
    std::string location;
    std::string description;

    IncidentState* state;
    std::vector<Observer*> observers; 

public:
    Incident(std::string id, std::string type, std::string location,std::string description);
    ~Incident();

    void activate();
    void resolve();
    void setState(IncidentState* state);
    std::string getStateName();

    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notifyObservers() override;

    std::string getId() const { return id; }
    std::string getType() const { return type; }
    std::string getLocation() const { return location; }
    std::string getDescription() const { return description; }
};

#endif
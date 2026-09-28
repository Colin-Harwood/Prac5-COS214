#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class IncidentState;

class Incident
{
private:
    std::string id;
    std::string type;
    std::string location;
    std::string description;

    IncidentState* state;

public:
    Incident(std::string id, std::string type, std::string location,std::string description);
    ~Incident();
    void activate();
    void resolve();
    void setState(IncidentState* state);
    std::string getStateName();
    
    std::string getId() const { return id; }
    std::string getType() const { return type; }
    std::string getLocation() const { return location; }
    std::string getDescription() const { return description; }
};

#endif
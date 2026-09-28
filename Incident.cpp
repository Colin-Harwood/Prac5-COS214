#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include "Observer.h"
#include <iostream>
#include <algorithm>

Incident::Incident(std::string id, std::string type, std::string location, std::string description)
    : id(id), type(type), location(location), description(description) {
    state = new ReportedState();
}

Incident::~Incident() {
    delete state;
}

void Incident::activate() {
    state->activate(this);
}

void Incident::resolve() {
    state->resolve(this);
}

void Incident::setState(IncidentState* newState) {
    IncidentState* oldState = state;
    state = newState;
    delete oldState;

    notifyObservers();
}

std::string Incident::getStateName() {
    return state->getName();
}

// ===== Observer pattern implementation =====

void Incident::attach(Observer* observer) {
    if (observer == nullptr) return;
    // Avoid duplicates
    if (std::find(observers.begin(), observers.end(), observer) == observers.end()) {
        observers.push_back(observer);
        std::cout << "[Incident " << id << "] Attached observer.\n";
    }
}

void Incident::detach(Observer* observer) {
    observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
        observers.end()
    );
    std::cout << "[Incident " << id << "] Detached observer.\n";
}

void Incident::notifyObservers() {
    std::cout << "[Incident " << id << "] Notifying " << observers.size()
              << " observer(s) of state: " << getStateName() << "\n";
    for (Observer* obs : observers) {
        obs->update(this);
    }
}
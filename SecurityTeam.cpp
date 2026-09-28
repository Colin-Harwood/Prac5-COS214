#include "SecurityTeam.h"

void SecurityTeam::arrestPerson(string person) {
    cout << "Person " << person << " is under arrest" << endl;
    mediator->notify(this, "Arresting", person);
}
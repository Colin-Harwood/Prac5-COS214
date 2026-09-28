#include <iostream>
#include "Incident.h"
#include "ResponseUnit.h"
#include "MedicalTeam.h"
#include "SecurityTeam.h"
#include "FacilitiesTeam.h"

using namespace CampusGuard;

int main()
{
    std::cout << "========================================\n";
    std::cout << "     Observer Pattern Demo\n";
    std::cout << "========================================\n\n";

    Incident *incident = new Incident("INC-001", "Fire", "Science Building", "Smoke detected on 3rd floor");

    MedicalTeam *medic = new MedicalTeam("RU-201");
    SecurityTeam *security = new SecurityTeam("RU-202");
    FacilitiesTeam *fac = new FacilitiesTeam("RU-203");

    incident->attach(medic);
    incident->attach(security);
    incident->attach(fac);

    std::cout << "\n--- Activating incident (Reported -> Active) ---\n";
    incident->activate();

    std::cout << "\n--- Resolving incident (Active -> Resolved) ---\n";
    incident->resolve();

    std::cout << "\n--- Detaching Security Team ---\n";
    incident->detach(security);

    std::cout << "\n--- Trying another activate on a resolved incident ---\n";
    incident->activate();

    delete incident;
    delete medic;
    delete security;
    delete fac;

    return 0;
}
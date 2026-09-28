#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

#include <string>
class Colleague;

using namespace std;

class IncidentCoordinator {
	public:
		virtual void notify(Colleague* team, string type, string location) = 0;
		virtual ~IncidentCoordinator() = default;

};

#endif

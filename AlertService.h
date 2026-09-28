#ifndef ALERTSERVICE_H
#define ALERTSERVICE_H

#include "Colleague.h"

#include <string>
using namespace std;

class AlertService : Colleague {

public:
	void broadcastAlert(string BuildingId, string message);

	void cancelAlert(string buildingId);
};

#endif

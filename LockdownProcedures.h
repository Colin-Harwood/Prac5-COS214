#ifndef LOCKDOWNPROCEDURES_H
#define LOCKDOWNPROCEDURES_H

#include <string>
using namespace std;

namespace CampusGuard {
	class LockdownProcedures {


	public:
		void activeShooterLockdown();

		void chemicalLeakLockdown(string areaId);
	};
}

#endif

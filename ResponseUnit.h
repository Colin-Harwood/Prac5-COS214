#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include "Colleague.h"
#include <string>
#include <iostream>

using namespace std;

class ResponseUnit : Colleague {
    protected:
        string id;
        string type;
        string available;
    public:
        void dispatchTo(string Destination);
        void markUnavailable();
};

#endif
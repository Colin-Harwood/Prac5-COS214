#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>
#include "Colleague.h"

namespace CampusGuard
{
    class ResponseUnit : public Colleague
    {
    protected:
        std::string id;
        std::string type;
        std::string status;

    public:
        ResponseUnit() : id(""), type(""), status("Available") {}
        ResponseUnit(std::string id, std::string type)
            : id(id), type(type), status("Available") {}

        void dispatchTo(std::string destination);
        void markUnavailable();

        std::string getId() const { return id; }
        std::string getType() const { return type; }
        std::string getStatus() const { return status; }
    };
}

using CampusGuard::ResponseUnit;

#endif
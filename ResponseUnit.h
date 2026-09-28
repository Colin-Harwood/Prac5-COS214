#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>

namespace CampusGuard
{
    class ResponseUnit
    {
    private:
        std::string id;
        std::string type;
        std::string status;

    public:
        ResponseUnit(std::string id, std::string type)
            : id(id), type(type), status("Available") {}

        void dispatchTo(std::string destination);
        void markUnavailable();

        std::string getId() const { return id; }
        std::string getType() const { return type; }
        std::string getStatus() const { return status; }
    };
}

#endif
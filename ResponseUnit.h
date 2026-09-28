#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>
#include "Observer.h"

namespace CampusGuard
{
    class ResponseUnit : public Observer
    {
    private:
        std::string id;
        std::string type;
        std::string status;

    public:
        ResponseUnit(std::string id, std::string type)
            : id(id), type(type), status("Available") {}
        
        virtual ~ResponseUnit() = default;

        void dispatchTo(std::string destination);
        void markUnavailable();

        void update(Incident* incident) override;

        std::string getId() const { return id; }
        std::string getType() const { return type; }
        std::string getStatus() const { return status; }
    };
}

#endif
#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H

#include "ResponseUnit.h"

namespace CampusGuard {
    class FacilitiesTeam : public ResponseUnit {
    public:
        FacilitiesTeam(std::string id)
            : ResponseUnit(id, "Facilities Team") {}

        void update(Incident* incident) override;
    };
}
#endif
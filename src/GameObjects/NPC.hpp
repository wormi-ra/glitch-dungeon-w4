#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class NPC : public Entity<Data::NPC> {
    public:
        NPC(const Data::NPC *data);

        virtual uint16_t getDrawColor() const;
        virtual void update();
};

#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Checkpoint : public Entity<Data::Checkpoint> {
    public:
        Checkpoint(const Data::Checkpoint *data);

        virtual uint16_t getDrawColor() const;
        virtual void update();
};

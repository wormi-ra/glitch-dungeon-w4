#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Door : public Entity<Data::Door> {
    public:
        Door(const Data::Door *data);

        virtual uint16_t getDrawColor() const;
        virtual void update();
};

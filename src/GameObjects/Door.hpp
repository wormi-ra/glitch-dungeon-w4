#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Door : public Entity<Data::Door> {
    public:
        bool locked = false;

        Door(const Data::Door *data);

        virtual IEntity::Type getType() const override;
        virtual uint16_t getDrawColor() const override;
        virtual void update() override;
};

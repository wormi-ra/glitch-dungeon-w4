#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Checkpoint : public Entity<Data::Checkpoint> {
    public:
        Vector2<uint8_t> room {};
        bool active = false;

        Checkpoint(const Data::Checkpoint *data);

        void deactivate();
        void activate();
        virtual IEntity::Type getType() const override;
        virtual uint16_t getDrawColor() const override;
        virtual void update() override;
};

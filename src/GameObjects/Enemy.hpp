#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Enemy : public Entity<Data::Enemy> {
    public:
        Enemy(const Data::Enemy *data);

        virtual IEntity::Type getType() const override;
        virtual uint16_t getDrawColor() const override;
        virtual void update() override;
};

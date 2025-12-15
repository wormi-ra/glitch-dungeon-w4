#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Enemy : public Entity<Data::Enemy> {
    public:
        Enemy(const Data::Enemy *data);

        virtual uint16_t getDrawColor() const;
        virtual void update();
};

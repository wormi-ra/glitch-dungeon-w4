#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Collection : public Entity<Data::Collection> {
    public:
        Collection(const Data::Collection *data);

        virtual uint16_t getDrawColor() const;
        virtual void update();
};

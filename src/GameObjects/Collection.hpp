#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Collection : public Entity<Data::Collection> {
    public:
        Collection(const Data::Collection *data);

        virtual IEntity::Type getType() const override;
        virtual uint16_t getDrawColor() const override;
        virtual void update() override;
};

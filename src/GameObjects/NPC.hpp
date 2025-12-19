#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class NPC : public Entity<Data::NPC> {
    public:
        NPC(const Data::NPC *data);

        virtual IEntity::Type getType() const override;
        virtual uint16_t getDrawColor() const override;
        virtual void update() override;
        const char *getText() const;
};

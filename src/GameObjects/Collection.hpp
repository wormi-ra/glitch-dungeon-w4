#pragma once

#include "Entity.hpp"
#include "../Data/EntityData.hpp"

class Collection : public Entity<Data::Collection> {
    public:
        enum Item : uint8_t {
            GRIMOIRE = 0,
            GREEN_SPELL = 1,
            RED_SPELL = 2,
            BLUE_SPELL = 3,
            GOLD_SPELL = 4,
            ZERO_SPELL = 5,
            NEGATIVE_SPELL = 6,
            PINK_SPELL = 7,
            CAT = 8,
            DOG = 9,
            BROOM = 10,
            MONKEY = 11,
            CREATURE1 = 12,
            EVIL_CAT = 13,
            FISH = 14,
            CREATURE2 = 15,
            CHICKEN = 16,
        };

        Collection(const Data::Collection *data);

        virtual IEntity::Type getType() const override;
        virtual uint16_t getDrawColor() const override;
        virtual void update() override;
        virtual void draw(const Viewport &view) const override;
        const char *getName() const;
        void onCollect();
};

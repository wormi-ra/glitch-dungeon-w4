#pragma once

#include "GameObject.hpp"
#include "../Glitch/Glitch.hpp"

class Player : public GameObject {
    public:
        enum State : uint8_t {
            HAS_GRIMOIRE =  0b00000001,
            IS_GROUNDED =   0b00000010,
        };

        DynamicArray<Glitch::Glitch *> spellbook {};
        Glitch::Glitch *glitch = Glitch::SPELLS[0];
        uint16_t artifacts = 0;
        uint8_t state = 0;

        Player();

        Glitch::Glitch &setSpell(Glitch::Type spell);
        Glitch::Glitch &nextSpell();
        void giveSpell(Glitch::Type spell);
        virtual uint16_t getDrawColor() const;
        virtual void update();

    private:
        void applyOffscreenLogic();
};

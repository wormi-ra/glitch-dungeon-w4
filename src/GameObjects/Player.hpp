#pragma once

#include "GameObject.hpp"
#include "../Glitch/Glitch.hpp"

class Player : public GameObject {
    public:
        Glitch::Glitch *glitch = Glitch::SPELLS[0];
        DynamicArray<Glitch::Glitch *> spellbook {};

        Player();

        Glitch::Glitch &setSpell(Glitch::Type spell);
        Glitch::Glitch &nextSpell();
        virtual uint16_t getDrawColor() const;
        virtual void update();

    private:
        void applyOffscreenLogic();
};

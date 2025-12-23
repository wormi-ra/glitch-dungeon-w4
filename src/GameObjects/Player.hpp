#pragma once

#include "Checkpoint.hpp"
#include "GameObject.hpp"
#include "../Glitch/Glitch.hpp"

class Player : public GameObject {
    public:
        enum State : uint8_t {
            HAS_GRIMOIRE =      0b00000001,
            ON_GROUND =         0b00000010,
            IS_JUMPING =        0b00000100,
            HORIZONTAL_INPUT =  0b00001000,
        };

        DynamicArray<Glitch::Glitch *> spellbook {};
        Checkpoint *customCheckpoint = nullptr;
        Glitch::Glitch *glitch = Glitch::SPELLS[0];
        Vector2<uint8_t> respawnRoom = {0, 0};
        float gravAcc = 0.8f;
        int32_t jumpTimer = 0;
        uint16_t artifacts = 0;
        uint8_t state = 0;
        uint8_t checkpointId = 0;

        Player();

        Glitch::Glitch &setSpell(Glitch::Type spell);
        Glitch::Glitch &nextSpell();
        void giveSpell(Glitch::Type spell);
        void normalize();
        void die();
        void setCheckpoint(Checkpoint &checkpoint);
        const Data::Checkpoint *getCheckpoint() const;
        virtual uint16_t getDrawColor() const;
        virtual void update();

    protected:
        void processInputs();
        void moveHorizontal(float direction);
        void stopMove();
        void startJump();
        void jump();
        void stopJump();
        bool tileCollide(Vector2<uint32_t> tile, FloatRect bbox) const;
        void applyCollisions();
        void applyGravity();
        void applyPhysics();
        void applyOffscreenLogic();
        void applyAnimationFromState();
};

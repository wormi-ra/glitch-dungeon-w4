#pragma once

#include "Checkpoint.hpp"
#include "GameObject.hpp"
#include "../Glitch/Glitch.hpp"
#include "../DynamicArray.hpp"

class Player : public GameObject {
    public:
        enum State : uint16_t {
            HAS_GRIMOIRE =          (1 << 0),
            ON_GROUND =             (1 << 1),
            IS_JUMPING =            (1 << 2),
            HORIZONTAL_INPUT =      (1 << 3),
            HORIZONTAL_COLLISION =  (1 << 4),
            CLIMBING =              (1 << 5),
            PRESSED_DOWN =          (1 << 6),
            TOUCHING_DOOR =         (1 << 7),
            IS_STUCK =              (1 << 8),
            CHECK_STUCK =           (1 << 9),
        };

        DynamicArray<Glitch::Glitch *> spellbook {};
        Checkpoint *customCheckpoint = nullptr;
        Glitch::Glitch *glitch = Glitch::SPELLS[0];
        Vector2<uint8_t> respawnRoom = {0, 0};
        float gravAcc = 0.8f;
        int32_t jumpTimer = 0;
        uint16_t artifacts = 0;
        uint16_t state = 0;
        uint8_t checkpointId = 0;

        Player();

        Glitch::Glitch &setSpell(Glitch::Type spell, bool forced = false);
        Glitch::Glitch &nextSpell();
        bool canUseSpellbook() const;
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
        void checkStuck();
        void applyCollisions();
        void applyGravity();
        void applyPhysics();
        void applyOffscreenLogic();
        void applyAnimationFromState();
};

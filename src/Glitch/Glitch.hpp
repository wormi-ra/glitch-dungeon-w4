#pragma once

#include "../Room.hpp"

namespace Glitch {
    static constexpr uint8_t SPELL_COUNT = 8;

    enum class Type : uint8_t {
        GREY = 0,
        RED = 1,
        GREEN = 2,
        ZERO = 3,
        BLUE = 4,
        GOLD = 5,
        NEGATIVE = 6,
        PINK = 7,
    };

    struct Physics {
        float jumpVelocity = 4.5f;
        float terminalVelocity = 7.0f;
        float originalGravAcc = 0.8f;
        float floatGravAcc = 0.4f;
        int32_t jumpTimeLimit = 30;
        float maxRunVelocity = 2.0f;
        float gndRunAcc = maxRunVelocity / 3.0f;
        float gndRunDec = maxRunVelocity / 3.0f;
        float airRunAcc = maxRunVelocity / 3.0f;
        float airRunDec = maxRunVelocity / 3.0f;
    };

    class Glitch {
        public:
            virtual ~Glitch() = default;

            virtual Type getType() const = 0;
            virtual const char *getName() const = 0;
            virtual const uint32_t *getPalette() const = 0;
            virtual const Physics &getPhysics() const;
            virtual bool collidesWith(Tile::Type collision) const;
            virtual bool isFallthrough(Tile::Type collision) const;

        protected:
            Physics m_physics{};
            // void transformPlayer(Player &player, Room &room, bool normalize = true, bool onlyVisual = false);
    };

    extern Glitch *const SPELLS[SPELL_COUNT];
}

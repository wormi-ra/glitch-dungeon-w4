#pragma once

#include <cstdint>

class Tile {
    public:
        enum class Type : uint8_t {
            GHOST = 0,
            SOLID = 1,
            FALLTHROUGH = 2,
            KILL_PLAYER = 3,
            SUPER_SOLID = 4
        };

        static inline Type getCollision(uint8_t tileData) {
            return (Tile::Type((tileData >> 4) & 0b0111));
        }

        static inline bool isVisible(uint8_t tileData) {
            return (tileData & 0b10000000);
        }

        static inline uint8_t getId(uint8_t tileData) {
            return (tileData & 0x0F);
        }
};

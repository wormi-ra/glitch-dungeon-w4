#pragma once

#include "DynamicArray.hpp"
#include "GameObjects/GameObject.hpp"
#include <cstdint>

class Tile {
    public:
        enum class Type {
            GHOST = 0,
            SOLID = 1,
            FALLTHROUGH = 2,
            KILL_PLAYER = 3,
            SUPER_SOLID = 4
        };

        static Type getCollision(uint8_t tileData);
        static uint8_t getId(uint8_t tileData);
};

class RoomData {
    public:
        struct TileData {
            uint16_t len = 0;
            const uint8_t *data = nullptr;
        };

        uint16_t width = 20;
        uint16_t height = 15;
        uint8_t glitch_type = 0;
        uint8_t glitch_sequence[1] = {0};
        uint16_t glitch_time_limit = 120;
        bool can_use_spellbook = true;
        const char *bg_code = nullptr;
        DynamicArray<uint8_t> entities {};
        TileData data {};
};

class Room {
    public:
        const RoomData *data;

        Room(const RoomData *data);
        ~Room();

        DynamicArray<uint8_t> decodeTiles(const RoomData::TileData &data) const;
        uint8_t getTile(uint32_t x, uint32_t y) const;
        void update();
        void draw() const;

    private:
        DynamicArray<GameObject *> entities {};
        DynamicArray<uint8_t> m_tiles {};
};

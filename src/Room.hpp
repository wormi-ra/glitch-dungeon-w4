#pragma once

#include "DynamicArray.hpp"
#include "GameObjects/IEntity.hpp"

class RoomData {
    public:
        struct TileData {
            uint16_t len = 0;
            const uint8_t *data = nullptr;
        };

        uint16_t width = 20;
        uint16_t height = 15;
        uint8_t glitch_sequence[3] = {0, 0, 0};
        uint16_t glitch_time_limit = 120;
        bool can_use_spellbook = true;
        DynamicArray<uint8_t> entities {};
        TileData data {};
};

class Room {
    public:
        DynamicArray<IEntity *> entities {};

        DynamicArray<uint8_t> tiles {};
        const RoomData *data;
        uint16_t glitchTime = 0;
        uint8_t glitchIndex = 0;

        Room(const RoomData *data);
        ~Room();

        DynamicArray<uint8_t> decodeTiles(const RoomData::TileData &data) const;
        uint8_t getTile(uint32_t x, uint32_t y) const;
        void onEnter();
        void update();
        void draw() const;
};

# pragma once

#include "../Graphics/Sheet.hpp"

namespace Data {
    extern const Sheet CHECKPOINT_SHEET;
    extern const Sheet COLLECTION_SHEET;
    extern const Sheet DOOR_SHEET;
    extern const Sheet ENEMY_SHEET;
    extern const Sheet NPC_SHEET;
    extern const Sheet PLAYER_SHEET;
    extern const Sheet SPELL_ICONS;
    extern const Sheet TILE_BLUE;
    extern const Sheet TILE_GOLD;
    extern const Sheet TILE_GREEN;
    extern const Sheet TILE_GREY;
    extern const Sheet TILE_NEGATIVE;
    extern const Sheet TILE_PINK;
    extern const Sheet TILE_RED;
    extern const Sheet TILE_ZERO;
    constexpr uint8_t TILESHEET_COUNT = 8;
    extern const Sheet *TILESHEETS[];
}
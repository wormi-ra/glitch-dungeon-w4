#include "Room.hpp"
#include "Game.hpp"
#include "DynamicArray.hpp"
#include "Data/Sheets.hpp"
#include "Data/Entities.hpp"
#include "Glitch/Glitch.hpp"
#include "wasm4.hpp"
#include <cstdint>

DynamicArray<uint8_t> Room::decodeTiles(const RoomData::TileData &data) const {
    DynamicArray<uint8_t> tiles {};

    tiles.reserve(this->data->width * this->data->height);
    for (uint16_t i = 0 ; i < data.len ; i += 2) {
        uint8_t size = data.data[i];
        uint8_t value = data.data[i + 1];
        for (uint8_t j = 0 ; j < size ; j++) {
            tiles.emplace_back(value);
        }
    }
    return tiles;
}

uint8_t Room::getTile(uint32_t x, uint32_t y) const {
    return this->tiles[y * this->data->width + x];
}

Room::Room(const RoomData *data)
    : data(data) {
    this->entities.reserve(data->entities.size());
    this->tiles = this->decodeTiles(data->data);
    for (const auto &id : this->data->entities) {
        auto &entity = Data::ENTITIES[id];
        this->entities.emplace_back(entity->instantiate());
    }
}

Room::~Room() {
    for (auto &entity : this->entities) {
        delete entity;
    }
}

void Room::onEnter() {
    if (!Game::player.canUseSpellbook()) {
        Game::player.setSpell(static_cast<Glitch::Type>(this->data->glitch_sequence[0]), true);
    }
}

void Room::update() {
    for (auto &entity : this->entities) {
        entity->update();
    }
    if (!Game::player.canUseSpellbook()) {
        this->glitchTime++;        
        if (this->glitchTime >= this->data->glitch_time_limit){
            this->glitchTime = 0;
            
            do {
                this->glitchIndex++;
                if (this->glitchIndex >= 3){
                    this->glitchIndex = 0;
                    break;
                }
            } while (this->data->glitch_sequence[this->glitchIndex] == 0);
            auto spell = static_cast<Glitch::Type>(this->data->glitch_sequence[this->glitchIndex]);
            Game::player.setSpell(spell, true);
            if (spell != Glitch::Type::GREY) {
                // TODO Play change spell sound
            }
        }
    }
}

void Room::draw() const {
    // if (this->data->bg_code != nullptr) {
    //     *DRAW_COLORS = 0x0014;
    //     w4::text(this->data->bg_code, 16, 16);
    // }
    *DRAW_COLORS = 0x1234;
    uint8_t glitch_id = static_cast<uint8_t>(Game::player.glitch->getType());
    for (uint16_t y = 0; y < this->data->height; y++) {
        for (uint16_t x = 0; x < this->data->width; x++) {
            auto tile = this->getTile(x, y);
            auto id = Tile::getId(tile);
            if (Tile::isVisible(tile)) {
                Data::TILESHEETS[glitch_id]->blitSub(Game::gameView, id, {x * 8, y * 8});
            }
        }
    }
    for (const auto &entity : this->entities) {        
        entity->draw(Game::gameView);
    }
}

#include "Room.hpp"
#include "Game.hpp"
#include "DynamicArray.hpp"
#include "Data/Sheets.hpp"
#include "Data/Entities.hpp"
#include <cstdint>

Tile::Type Tile::getCollision(uint8_t tileData) {
    return Tile::Type((tileData >> 4) & 0x0F);
}

uint8_t Tile::getId(uint8_t tileData) {
    return (tileData & 0x0F);
}

DynamicArray<uint8_t> Room::decodeTiles(const RoomData::TileData &data) const {
    DynamicArray<uint8_t> tiles {};

    tiles.reserve(15*20);
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
    return this->m_tiles[y * this->data->width + x % this->data->width];
}

Room::Room(const RoomData *data)
    : data(data) {
    this->entities.reserve(16);
    this->m_tiles = this->decodeTiles(data->data);
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

void Room::update() {
    for (auto &entity : this->entities) {
        entity->update();
    }
}

void Room::draw() const {
    if (this->data->bg_code != nullptr) {
        *DRAW_COLORS = 0x0014;
        w4::text(this->data->bg_code, 16, 16);
    }
    *DRAW_COLORS = 0x1234;
    uint8_t glitch_id = static_cast<uint8_t>(Game::player.glitch->getType());
    for (uint16_t x = 0; x < this->data->width; x++) {
        for (uint16_t y = 0; y < this->data->height; y++) {
            auto tile = this->getTile(x, y);
            auto id = Tile::getId(tile);
            auto collision = Tile::getCollision(tile);
            if (collision != Tile::Type::GHOST || id != 0) {
                Data::TILESHEETS[glitch_id]->blitSub(Game::gameView, id, {x * 8, y * 8});
            }
        }
    }
    for (const auto &entity : this->entities) {        
        entity->draw(Game::gameView);
    }
}

#include "Game.hpp"
#include "Data/Entities.hpp"
#include "Data/Rooms.hpp"
#include "DynamicArray.hpp"
#include "Glitch/Glitch.hpp"
#include "Graphics/TextBox.hpp"
#include "Vector2.hpp"
#include "utils.hpp"
#include "wasm4.hpp"

Viewport Game::gameView{
    {0, 0},
     {SCREEN_SIZE, SCREEN_SIZE - 40}
};

Viewport Game::hudView{
    {0, SCREEN_SIZE - 40},
     {SCREEN_SIZE, 40}
};

TextBox Game::textBox{
    "Hello World",
    {4, 4},
    {hudView.size.x - 8, hudView.size.y - 8}
};

Room *Game::currentRoom = nullptr;

Vector2<uint8_t> Game::roomPosition {0, 0};

Player Game::player {};

DynamicArray<GameObject *> Game::entities {};

void Game::start() {
    w4::trace("start");
    Game::setPalette(Game::player.glitch->getPalette());
    Game::loadRoom(0, 0);
}

void Game::setPalette(const uint32_t *palette) {
    for (uint8_t i = 0 ; i < 4 ; i++)
        PALETTE[i] = palette[i];
}

void Game::update() {
    Game::player.update();
    Game::currentRoom->update();
}

void Game::draw() {
    if (Game::currentRoom != nullptr) {
        Game::currentRoom->draw();
    }
    Game::textBox.draw(Game::hudView);
    Game::player.draw(Game::gameView);
}

void Game::loadRoom(uint8_t x, uint8_t y) {
    Game::roomPosition = {x, y};
    if (Game::currentRoom != nullptr) {
        delete Game::currentRoom;
    }
    w4::tracef("room %d %d", x, y);
    Game::currentRoom = new Room(&Data::DUNGEON[y][x]);
}

void Game::moveRoom(int8_t x, int8_t y) {
    Vector2<int8_t> pos = Vector2<int8_t>(static_cast<int8_t>(Game::roomPosition.x) + x, static_cast<int8_t>(Game::roomPosition.y) + y);

    pos.x = mod(pos.x, 6);
    pos.y = mod(pos.y, 6);
    Game::loadRoom(
        static_cast<uint8_t>(pos.x),
        static_cast<uint8_t>(pos.y)
    );
}


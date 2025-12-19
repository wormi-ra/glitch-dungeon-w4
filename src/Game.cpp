#include "Game.hpp"
#include "Data/Rooms.hpp"
#include "Glitch/Glitch.hpp"
#include "Graphics/Spellbar.hpp"
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
    nullptr,
    {2, 2},
    {hudView.size.x - 4, hudView.size.y - 4}
};

Spellbar Game::spellbar{
    {2, 2},
    {hudView.size.x - 4, hudView.size.y - 4}
};

Room *Game::currentRoom = nullptr;

Vector2<uint8_t> Game::roomPosition {0, 0};

Player Game::player {};

static Function<void()> loadCallback = nullptr;

void Game::start() {
    w4::trace("start");
    Game::setPalette(Game::player.glitch->getPalette());
    Game::loadRoom(0, 0);
}

void Game::setPalette(const uint32_t *palette) {
    for (uint8_t i = 0 ; i < 4 ; i++)
        PALETTE[i] = palette[i];
}

static void applyLoadRoom() {
    if (Game::currentRoom->data != &Data::DUNGEON[Game::roomPosition.y][Game::roomPosition.x]) {
        if (Game::currentRoom != nullptr) {
            delete Game::currentRoom;
        }
        Game::currentRoom = new Room(&Data::DUNGEON[Game::roomPosition.y][Game::roomPosition.x]);
        if (loadCallback != nullptr) {
            loadCallback();
            loadCallback = nullptr;
        }
    }
}

void Game::update() {
    Game::player.update();
    Game::currentRoom->update();
    Game::textBox.update();
    applyLoadRoom();
}

void Game::draw() {
    if (Game::currentRoom != nullptr) {
        Game::currentRoom->draw();
    }
    if (Game::textBox.text != nullptr) {
        Game::textBox.draw(Game::hudView);
    } else {
        Game::spellbar.draw(Game::hudView);
    }
    Game::player.draw(Game::gameView);
}

const RoomData &Game::loadRoom(uint8_t x, uint8_t y, Function<void()> callback) {
    Vector2<uint8_t> newPosition = {x, y};
    if (Game::currentRoom != nullptr && newPosition == Game::roomPosition) {
        callback();
        return *Game::currentRoom->data;
    }
    Game::roomPosition = newPosition;
    if (Game::currentRoom == nullptr) {
        Game::currentRoom = new Room(&Data::DUNGEON[Game::roomPosition.y][Game::roomPosition.x]);
    }
    loadCallback = callback;
    return Data::DUNGEON[Game::roomPosition.y][Game::roomPosition.x];
}

const RoomData &Game::moveRoom(int8_t x, int8_t y, Function<void()> callback) {
    Vector2<int8_t> pos = Vector2<int8_t>(static_cast<int8_t>(Game::roomPosition.x) + x, static_cast<int8_t>(Game::roomPosition.y) + y);

    pos.x = mod(pos.x, 6);
    pos.y = mod(pos.y, 6);
    return Game::loadRoom(
        static_cast<uint8_t>(pos.x),
        static_cast<uint8_t>(pos.y),
        callback
    );
}


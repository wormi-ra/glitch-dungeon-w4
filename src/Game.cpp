#include "Game.hpp"
#include "Data/Entities.hpp"
#include "Data/Rooms.hpp"
#include "Glitch/Glitch.hpp"
#include "Graphics/Spellbar.hpp"
#include "Graphics/TextBox.hpp"
#include "Vector2.hpp"
#include "utils.hpp"
#include "wasm4.hpp"
#include "Input.hpp"

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

Game::Stats Game::stats {};

static Function<void()> loadCallback = nullptr;

void Game::start() {
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

void Game::dismissTextbox() {
    IntRect rect = hudView.transform({textBox.position, textBox.size});
    if (rect.contains(Vector2<int32_t>(Input::getMouse()))
        && Input::mouseDelta() != Vector2<int16_t>(0, 0)) {
            textBox.setText(nullptr, 0);
    }
}

void Game::update() {
    Game::stats.frames++;
    Game::player.update();
    Game::currentRoom->update();
    Game::textBox.update();
    Game::dismissTextbox();
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

void Game::save() {

}

void Game::load() {
    
}

void Game::reset() {
    Game::player = Player();
    if (Game::currentRoom != nullptr) {
        delete Game::currentRoom;
        Game::currentRoom = nullptr;
    }
    Data::interactedEntities = {};
    Game::roomPosition = {0, 0};
    Game::stats = {};
    Game::textBox.setText(nullptr, 0);
    loadCallback = nullptr;
}

const RoomData &Game::loadRoom(uint8_t x, uint8_t y, Function<void()> callback) {
    Vector2<uint8_t> newPosition = {x, y};
    w4::tracef("%d %d", newPosition.x, newPosition.y);
    if (Game::currentRoom != nullptr && newPosition == Game::roomPosition) {
        callback();
        return *Game::currentRoom->data;
    }
    Game::roomPosition = newPosition;
    if (Game::currentRoom == nullptr) {
        Game::currentRoom = new Room(&Data::DUNGEON[Game::roomPosition.y][Game::roomPosition.x]);
    }
    loadCallback = callback;
    Game::textBox.setText(nullptr, 0);
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


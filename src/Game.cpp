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
#include "Time.hpp"
#include <cstdint>
#include <cstring>

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

char Game::statsText[128] {0};

uint8_t Game::state = 0;

static Function<void()> loadCallback = nullptr;

static const uint32_t GRAYSCALE_PALETTE[] = {
    0x000000,
    0x676767,
    0xb6b6b6,
    0xffffff,
};

void Game::start() {
    Game::setPalette(Game::player.glitch->getPalette());
    Game::loadRoom(0, 0);

    // Game::player.state |= Player::HAS_GRIMOIRE;
    // Game::state |= Game::GLITCHED;
    // Game::player.spellbook = {
    //     Glitch::SPELLS[1],
    //     Glitch::SPELLS[2],
    //     Glitch::SPELLS[3],
    //     Glitch::SPELLS[4],
    //     Glitch::SPELLS[5],
    //     Glitch::SPELLS[6],
    //     Glitch::SPELLS[7],
    //  };
    //  Game::loadRoom(4, 2);
}

void Game::update() {
    Game::stats.frames++;
    Game::player.update();
    Game::currentRoom->update();
    Game::textBox.update();
    Game::dismissTextbox();
    Game::applyLoadRoom();
    updateCamera();
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

void Game::setPalette(const uint32_t *palette) {
    for (uint8_t i = 0 ; i < 4 ; i++)
        PALETTE[i] = palette[i];
}

void Game::applyLoadRoom() {
    if (Game::currentRoom->data != Game::getRoomData(Game::roomPosition.x, Game::roomPosition.y)) {
        if (Game::currentRoom != nullptr) {
            delete Game::currentRoom;
        }
        Game::currentRoom = new Room(Game::getRoomData(Game::roomPosition.x, Game::roomPosition.y));
        Game::currentRoom->onEnter();
        if (loadCallback != nullptr) {
            loadCallback();
            loadCallback = nullptr;
        }
        Game::setPalette(Game::player.glitch->getPalette());
        if (Game::roomPosition == Vector2<uint8_t> {5, 5}) {
            Game::win();
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

void Game::updateCamera() {
    Vector2<int32_t> cameraMin = {0, 0};
    Vector2<int32_t> cameraMax = {
        Game::currentRoom->data->width * 8 - static_cast<int32_t>(Game::gameView.size.x),
        Game::currentRoom->data->height * 8 - static_cast<int32_t>(Game::gameView.size.y)
    };
    Game::gameView.offset.x = -std::clamp(static_cast<int32_t>(std::round((Game::player.position.x + static_cast<float>(Game::player.sheet->tileWidth) / 2.0f))) - (SCREEN_SIZE / 2), cameraMin.x, cameraMax.x);
}

void Game::win() {
    Game::player.position.x = 16;
    Game::player.setSpell(Glitch::Type::GREY, 1);
    Game::setPalette(GRAYSCALE_PALETTE);
    if (Game::state & BEAT_GAME)
        return;
    Game::state |= BEAT_GAME;
    Game::state |= UNLOCKED_HAT;
    Time time = Time::fromFrameCount(Game::stats.frames);
    strcpy(Game::statsText, "deaths:");
    strcat(Game::statsText, itoa(Game::stats.deaths));
    strcat(Game::statsText, "\nspells:");
    strcat(Game::statsText, itoa(Game::stats.spells));
    strcat(Game::statsText, "\ntime:");
    if (time.hours > 0) {
        strcat(Game::statsText, itoa(time.hours));
        strcat(Game::statsText, "h ");
    }
    if (time.hours > 0 || time.minutes > 0) {
        strcat(Game::statsText, itoa(time.minutes, 10, 2));
        strcat(Game::statsText, "m ");
    }
    strcat(Game::statsText, itoa(time.seconds, 10, 2));
    strcat(Game::statsText, "s ");
    if (time.hours == 0) {
        strcat(Game::statsText, itoa(time.milliseconds, 10, 3));
        strcat(Game::statsText, "ms");
    }
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
    Game::state = Game::state & Game::UNLOCKED_HAT;
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
        Game::currentRoom = new Room(Game::getRoomData(Game::roomPosition.x, Game::roomPosition.y));
    }
    loadCallback = callback;
    Game::textBox.setText(nullptr, 0);
    return *Game::currentRoom->data;
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

const RoomData *Game::getRoomData(uint8_t x, uint8_t y) {
    if (Game::state & Game::GLITCHED)
        return Data::DUNGEON_GLITCHED[y][x];
    if (Game::player.state & Player::State::HAS_GRIMOIRE) {
        if (y == 0 && x <= 1)
            return Data::DUNGEON_GLITCHED[y][x];
    }
    return Data::DUNGEON[y][x];
}

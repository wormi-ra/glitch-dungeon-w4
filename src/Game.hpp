#pragma once

#include "Data/Entities.hpp"
#include "Glitch/Glitch.hpp"
#include "Graphics/TextBox.hpp"
#include "Graphics/Viewport.hpp"
#include "Graphics/Spellbar.hpp"
#include "GameObjects/Player.hpp"
#include "Room.hpp"

namespace func {
    template <typename>
    class function;
}

template <typename T>
using Function = func::function<T>;

namespace Game {
    struct Stats {
        uint32_t frames = 0;
        uint32_t deaths = 0;
        uint32_t spells = 0;
    };

    enum State : uint8_t {
        BEAT_GAME = 0b00000001,
        GLITCHED = 0b00000010,
        UNLOCKED_HAT = 0b00000100,
    };

    struct Save {
        static constexpr uint16_t MAGIC_NUMBER = 0xCACA;

        struct Header {
            uint16_t magicNumber;
            uint16_t size;
        } header;
        typeof(Data::interactedEntities) interactedEntities {};
        Game::Stats stats {};
        Glitch::Type spells[8] {};
        Vector2<float> playerPosition {20,72};
        Vector2<uint8_t> roomPosition {};
        Vector2<uint8_t> respawnRoom {};
        uint16_t artifacts = 0;
        uint8_t checkpointId = 0;
        uint8_t gameState = 0;
        Glitch::Type currentGlitch = Glitch::Type::GREY;
        bool hasGrimoire = false;
    };

    void start();
    void update();
    void draw();
    void save();
    bool load();
    void reset();
    void clearSave();
    void setPalette(const uint32_t *palette);
    void dismissTextbox();
    void win();
    void updateCamera();
    void applyLoadRoom();
    const RoomData *getRoomData(uint8_t x, uint8_t y);
    const RoomData &loadRoom(uint8_t x, uint8_t y);
    const RoomData &moveRoom(int8_t x, int8_t y);
    const RoomData &loadRoom(uint8_t x, uint8_t y, Function<void()> callback);
    const RoomData &moveRoom(int8_t x, int8_t y, Function<void()> callback);
    
    extern Viewport gameView;
    extern Viewport hudView;
    extern TextBox textBox;
    extern Spellbar spellbar;
    extern Player player;
    extern Vector2<uint8_t> roomPosition;
    extern Room *currentRoom;
    extern Stats stats;
    extern uint8_t state;
    extern char statsText[128];
    extern const uint32_t GRAYSCALE_PALETTE[4];
};

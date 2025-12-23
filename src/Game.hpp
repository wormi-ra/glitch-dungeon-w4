#pragma once

#include "Graphics/TextBox.hpp"
#include "Graphics/Viewport.hpp"
#include "Graphics/Spellbar.hpp"
#include "GameObjects/Player.hpp"
#include "Function.hpp"

namespace Game {
    struct Stats {
        uint32_t frames = 0;
        uint32_t deaths = 0;
        uint32_t spells = 0;
    };

    void start();
    void update();
    void draw();
    void save();
    void load();
    void reset();
    void setPalette(const uint32_t *palette);
    void dismissTextbox();
    const RoomData &loadRoom(uint8_t x, uint8_t y, Function<void()> callback = nullptr);
    const RoomData &moveRoom(int8_t x, int8_t y, Function<void()> callback = nullptr);
    
    extern Viewport gameView;
    extern Viewport hudView;
    extern TextBox textBox;
    extern Spellbar spellbar;
    extern Player player;
    extern Vector2<uint8_t> roomPosition;
    extern Room *currentRoom;
    extern Stats stats;
};

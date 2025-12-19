#pragma once

#include "Graphics/TextBox.hpp"
#include "Graphics/Viewport.hpp"
#include "Graphics/Spellbar.hpp"
#include "GameObjects/Player.hpp"
#include "Function.hpp"

namespace Game {
    void start();
    void update();
    void draw();
    void setPalette(const uint32_t *palette);
    const RoomData &loadRoom(uint8_t x, uint8_t y, Function<void()> callback = nullptr);
    const RoomData &moveRoom(int8_t x, int8_t y, Function<void()> callback = nullptr);
    
    extern Viewport gameView;
    extern Viewport hudView;
    extern TextBox textBox;
    extern Spellbar spellbar;
    extern Player player;
    extern Vector2<uint8_t> roomPosition;
    extern Room *currentRoom;
};

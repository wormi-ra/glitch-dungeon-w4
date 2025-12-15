#pragma once

#include "DynamicArray.hpp"
#include "GameObjects/GameObject.hpp"
#include "Graphics/TextBox.hpp"
#include "Graphics/Viewport.hpp"
#include "GameObjects/Player.hpp"

namespace Game {
    void start();
    void update();
    void draw();
    void setPalette(const uint32_t *palette);
    void loadRoom(uint8_t x, uint8_t y);
    void moveRoom(int8_t x, int8_t y);
    
    extern Viewport gameView;
    extern Viewport hudView;
    extern TextBox textBox;
    extern Player player;
    extern DynamicArray<GameObject *> entities;
    extern Vector2<uint8_t> roomPosition;
    extern Room *currentRoom;
};

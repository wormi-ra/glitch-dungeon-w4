#include "Input.hpp"
#include "Game.hpp"
#include <cstring>

void clearFramebuffer(uint8_t color = 0) {
    memset(FRAMEBUFFER, color | (color << 2) | (color << 4) | (color << 6), SCREEN_SIZE * SCREEN_SIZE / 4);
}

void start() {
    Game::start();
}

void update() {
    clearFramebuffer(0x0);
    Input::update();
    Game::update();
    Game::draw();
}

#include "Data/Sheets.hpp"
#include "Graphics/Viewport.hpp"
#include "Input.hpp"
#include "Game.hpp"
#include "Audio/Queue.hpp"
#include "Scene.hpp"
#include "wasm4.hpp"

uint8_t Scene::currentScene = 0;

#define TEXT_CENTER(str, x, y) (w4::text(str, SCREEN_SIZE / 2 - (FONT_SIZE / 2) * (sizeof(str) - 1) + (x), (y)))

static void clearFramebuffer(uint8_t color = 0) {
    memset(FRAMEBUFFER, color | (color << 2) | (color << 4) | (color << 6), SCREEN_SIZE * SCREEN_SIZE / 4);
}

static void updateMainMenu() {
    static uint8_t frame = 0;
    Viewport view = Viewport();

    *DRAW_COLORS = 0x41;
    w4::rect(4, 4, SCREEN_SIZE - 8, SCREEN_SIZE - 8);
    *DRAW_COLORS = 0x14;
    TEXT_CENTER("GLITCH DUNGEON", 0, 16);
    TEXT_CENTER("by jakeonaut", 0, 28);
    TEXT_CENTER("ported to WASM4", 0, SCREEN_SIZE - 20 - 12);
    TEXT_CENTER("by Wormi", 0, SCREEN_SIZE - 20);
    *DRAW_COLORS = (frame / 30) % 2 ? 0x14 : 0x13;
    TEXT_CENTER("press X to start", 0, SCREEN_SIZE / 2 + 8+16);
    *DRAW_COLORS = 0x1034;
    Data::PLAYER_SHEET.blitSub(view, 0, {
        SCREEN_SIZE / 2 - 8,
        SCREEN_SIZE / 2 - 8,
    });
    if (Input::isPressedDown(BUTTON_1)) {
        Scene::currentScene = Scene::GAME;
        Game::setPalette(Game::player.glitch->getPalette());
    }
    frame++;
}

static void updateResetMenu() {
    static bool selection = false;
    Viewport view = Viewport();

    *DRAW_COLORS = 0x41;
    w4::rect(4, 4, SCREEN_SIZE - 8, SCREEN_SIZE - 8);
    *DRAW_COLORS = 0x14;
    TEXT_CENTER("RESET ALL", 0, 24);
    TEXT_CENTER("PROGRESS?", 0, 36);
    *DRAW_COLORS = selection ? 0x14 : 0x13;
    w4::text(selection ? "> yes <" : "  yes  ", (SCREEN_SIZE / 2 - SCREEN_SIZE / 4) - (3 * FONT_SIZE), SCREEN_SIZE - 40);
    *DRAW_COLORS = !selection ? 0x14 : 0x13;
    w4::text(!selection ? " > no <" : "   no  ", (SCREEN_SIZE / 2 + SCREEN_SIZE / 4) - (4 * FONT_SIZE), SCREEN_SIZE - 40);
    if (Input::isPressedDown(BUTTON_LEFT | BUTTON_RIGHT)) {
        selection = !selection;
    }
    if (Input::isPressedDown(BUTTON_1)) {
        if (selection) {
            Game::reset();
            Game::save();
        }
        Scene::currentScene = Scene::GAME;
        Game::setPalette(Game::player.glitch->getPalette());
        selection = false;
    }
}

void start() {
    Game::start();
    Game::setPalette(Game::GRAYSCALE_PALETTE);
}

void update() {
    clearFramebuffer(0x0);
    Input::update();
    switch (Scene::currentScene) {
        case Scene::MAIN_MENU:
            updateMainMenu();
            break;
        case Scene::GAME:
            Game::update();
            Game::draw();
            break;
        case Scene::RESET_MENU:
            updateResetMenu();
        break;
    }
    Audio::update();
}

#pragma once

#include <cstdint>

namespace Scene {
    enum : uint8_t {
        MAIN_MENU = 0,
        GAME = 1,
        RESET_MENU = 2,
    };
    extern uint8_t currentScene;
};

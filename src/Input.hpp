#pragma once

#include <cstdint>
#include "Rect.hpp"

enum class Gamepad : uint8_t {
    gamepad1 = 0,
    gamepad2 = 1,
    gamepad3 = 2,
    gamepad4 = 3,
};

struct MouseData {
    union {
        uint32_t position;
        struct {
            int16_t mouseX;
            int16_t mouseY;
        };
    };
    uint8_t buttons;
};

class Input {
    public:
        static void update();
        static bool isPressed(uint8_t key, Gamepad gamepad = Gamepad::gamepad1);
        static bool isPressedDown(uint8_t key, Gamepad gamepad = Gamepad::gamepad1);
        static bool isPressedUp(uint8_t key, Gamepad gamepad = Gamepad::gamepad1);
        static bool isHoldingDown(uint8_t key, uint16_t time, Gamepad gamepad = Gamepad::gamepad1);
        static Vector2<int16_t> getMouse();
        static bool isClicked(IntRect rect, uint8_t buttons);
        static bool isClickedDown(IntRect rect, uint8_t buttons);
        static bool isClickedUp(IntRect rect, uint8_t buttons);
        static Vector2<int16_t> mouseDelta();

        static constexpr uint8_t GAMEPAD_COUNT = 4;

    private:
        static uint8_t m_gamepad[GAMEPAD_COUNT];
        static uint8_t m_previousGamepad[GAMEPAD_COUNT];
        static uint16_t m_holdTimer[GAMEPAD_COUNT];
        static MouseData m_mouse;
        static MouseData m_previousMouse;

        static uint8_t pressedThisFrame(Gamepad gamepad = Gamepad::gamepad1);
        static uint8_t unpressedThisFrame(Gamepad gamepad = Gamepad::gamepad1);
        static uint8_t clickedThisFrame();
        static uint8_t unclickedThisFrame();
};

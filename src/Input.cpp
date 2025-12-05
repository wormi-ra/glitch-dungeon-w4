#include "Input.hpp"
#include "wasm4.hpp"
#include <cstdint>


uint8_t Input::m_gamepad[GAMEPAD_COUNT] = {0, 0, 0, 0};
uint8_t Input::m_previousGamepad[GAMEPAD_COUNT] = {0, 0, 0, 0};
MouseData Input::m_mouse = {{0}, 0};
MouseData Input::m_previousMouse = {{0}, 0};

void Input::update() {
    for (uint8_t i = 0; i < GAMEPAD_COUNT ; i++) {
        Input::m_previousGamepad[i] = Input::m_gamepad[i];
    }
    Input::m_previousMouse = Input::m_mouse;
    Input::m_gamepad[0] = *GAMEPAD1;
    Input::m_gamepad[1] = *GAMEPAD2;
    Input::m_gamepad[2] = *GAMEPAD3;
    Input::m_gamepad[3] = *GAMEPAD4;
    Input::m_mouse.mouseX = *MOUSE_X;
    Input::m_mouse.mouseY = *MOUSE_Y;
    Input::m_mouse.buttons = *MOUSE_BUTTONS;
}

bool Input::isPressed(uint8_t key, Gamepad gamepad) {
    return key & Input::m_gamepad[static_cast<uint8_t>(gamepad)];
}

bool Input::isPressedDown(uint8_t key, Gamepad gamepad) {
    return key & Input::pressedThisFrame(gamepad);
}

bool Input::isPressedUp(uint8_t key, Gamepad gamepad) {
    return key & Input::unpressedThisFrame(gamepad);
}

uint8_t Input::pressedThisFrame(Gamepad gamepad) {
    auto id = static_cast<uint8_t>(gamepad);
    return Input::m_gamepad[id] & (Input::m_gamepad[id] ^ Input::m_previousGamepad[id]);
}

uint8_t Input::unpressedThisFrame(Gamepad gamepad) {
    auto id = static_cast<uint8_t>(gamepad);
    return Input::m_previousGamepad[id] & (Input::m_gamepad[id] ^ Input::m_previousGamepad[id]);
}

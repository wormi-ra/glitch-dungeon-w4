#include "Input.hpp"
#include "Vector2.hpp"
#include "wasm4.hpp"
#include <cstdint>


uint8_t Input::m_gamepad[GAMEPAD_COUNT] = {0, 0, 0, 0};
uint8_t Input::m_previousGamepad[GAMEPAD_COUNT] = {0, 0, 0, 0};
uint16_t Input::m_holdTimer[GAMEPAD_COUNT] = {0, 0, 0, 0};
MouseData Input::m_mouse = {{0}, 0};
MouseData Input::m_previousMouse = {{0}, 0};


void Input::update() {
    for (uint8_t i = 0; i < GAMEPAD_COUNT ; i++) {
        if (Input::m_previousGamepad[i] == Input::m_gamepad[i]) {
            Input::m_holdTimer[i]++;
        } else {
            Input::m_previousGamepad[i] = Input::m_gamepad[i];
            Input::m_holdTimer[i] = 0;
        }
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

Vector2<int16_t> Input::getMouse() {
    return {Input::m_mouse.mouseX, Input::m_mouse.mouseY};
}

Vector2<int16_t> Input::mouseDelta() {
    return Vector2<int16_t > {
        Input::m_mouse.mouseX,
        Input::m_mouse.mouseY,
    } - Vector2<int16_t > {
        Input::m_previousMouse.mouseX,
        Input::m_previousMouse.mouseY,
    };
}

bool Input::isPressed(uint8_t key, Gamepad gamepad) {
    return key & Input::m_gamepad[uint8_t(gamepad)];
}

bool Input::isPressedDown(uint8_t key, Gamepad gamepad) {
    return key & Input::pressedThisFrame(gamepad);
}

bool Input::isPressedUp(uint8_t key, Gamepad gamepad) {
    return key & Input::unpressedThisFrame(gamepad);
}

bool Input::isHoldingDown(uint8_t key, uint16_t time, Gamepad gamepad) {
    auto result = Input::isPressed(key, gamepad)
        && ((Input::m_previousGamepad[uint8_t(gamepad)] & key) == (Input::m_gamepad[uint8_t(gamepad)] & key))
        && Input::m_holdTimer[uint8_t(gamepad)] >= time;
    if (result)
        Input::m_holdTimer[uint8_t(gamepad)] = 0;
    return result;
}

bool Input::isClicked(IntRect rect, uint8_t buttons) {
    return (buttons & Input::m_mouse.buttons)
    && rect.contains({Input::m_mouse.mouseX, Input::m_mouse.mouseY});
}

bool Input::isClickedDown(IntRect rect, uint8_t buttons) {
    return (buttons & Input::clickedThisFrame())
    && rect.contains({Input::m_mouse.mouseX, Input::m_mouse.mouseY});
}

bool Input::isClickedUp(IntRect rect, uint8_t buttons) {
    return (buttons & Input::unclickedThisFrame())
    && rect.contains({Input::m_mouse.mouseX, Input::m_mouse.mouseY});
}

uint8_t Input::clickedThisFrame() {
    return Input::m_mouse.buttons & (Input::m_mouse.buttons ^ Input::m_previousMouse.buttons);
}

uint8_t Input::unclickedThisFrame() {
    return Input::m_previousMouse.buttons & (Input::m_mouse.buttons ^ Input::m_previousMouse.buttons);
}

uint8_t Input::pressedThisFrame(Gamepad gamepad) {
    auto id = uint8_t(gamepad);
    return Input::m_gamepad[id] & (Input::m_gamepad[id] ^ Input::m_previousGamepad[id]);
}

uint8_t Input::unpressedThisFrame(Gamepad gamepad) {
    auto id = uint8_t(gamepad);
    return Input::m_previousGamepad[id] & (Input::m_gamepad[id] ^ Input::m_previousGamepad[id]);
}

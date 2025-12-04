#include "wasm4.h"
#include "Data/Sounds.hpp"
#include "Data/Sheets.hpp"
#include "strutils.hpp"

static const uint8_t smiley[] = {
    0b11000011,
    0b10000001,
    0b00100100,
    0b00100100,
    0b00000000,
    0b00100100,
    0b10011001,
    0b11000011,
};

static uint8_t gamepad = 0;
static int32_t currentSound = 2;
static uint32_t frame = 0;

static constexpr int32_t N_SOUNDS = 4;
static const Audio::ISound *sounds[N_SOUNDS] = {
    &Sounds::BLIP,
    &Sounds::JUMP,
    &Sounds::CHECKPOINT,
    &Sounds::LFO,
};

void update () {
    *DRAW_COLORS = 0x1234;
    for (int i = 0; i < 7 ; i++)
        Data::TILESHEETS[i]->blitSub(0, 16 + i*8, 16);
    *DRAW_COLORS = 2;
    w4::text(
        sounds[currentSound]->name(),
        SCREEN_SIZE / 2 - (int32_t)strlen(sounds[currentSound]->name()) / 2 * FONT_SIZE,
        48
    );
    uint8_t previous = gamepad;
    gamepad = *GAMEPAD1;
    uint8_t pressed = gamepad & (previous ^ gamepad);
    if (pressed & BUTTON_LEFT) {
        currentSound = (currentSound - 1) % N_SOUNDS;
        if (currentSound < 0)
            currentSound += N_SOUNDS;
    }
    if (pressed & BUTTON_RIGHT) {
        currentSound = (currentSound + 1) % N_SOUNDS;
    }
    if (pressed & BUTTON_UP) {
        frame++;
    }
    if (pressed & BUTTON_DOWN) {
        frame--;
    }
    if (pressed & BUTTON_1) {
        *DRAW_COLORS = 4;
        frame = 0;
    }
    sounds[currentSound]->play(frame, 0.5f);
    if (!(gamepad & BUTTON_2)) {
        frame++;
    } else {
        *DRAW_COLORS = 4;
    }
    w4::blit(smiley, 76, 76, 8, 8, BLIT_1BPP);
    w4::text("Press X to play", 16, 90);
    w4::text("Hold Z to freeze", 16, 104);
    w4::text(itoa(frame), 16, 160 - 8 - 16);
}

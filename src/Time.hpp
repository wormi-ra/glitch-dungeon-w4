#pragma once

#include <cstdint>

struct Time {
    uint32_t hours = 0;
    uint16_t milliseconds = 0;
    uint8_t minutes = 0;
    uint8_t seconds = 0;

    static Time fromFrameCount(uint32_t frames);
};

#pragma once

#include <cstdint>
#include "wasm4.hpp"

struct Sheet {
    uint32_t width;
    uint32_t height;
    uint32_t tileWidth;
    uint32_t tileHeight;
    const uint8_t *data;
    uint32_t flags = BLIT_2BPP;

    void blitSub(uint32_t tileId, int32_t x, int32_t y, uint32_t flags = 0) const;
};

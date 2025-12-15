#pragma once

#include <cstdint>
#include "../Graphics/Viewport.hpp"
#include "../wasm4.hpp"

struct Sheet {
    uint32_t width;
    uint32_t height;
    uint32_t tileWidth;
    uint32_t tileHeight;
    const uint8_t *data;
    uint32_t flags = BLIT_2BPP;

    void blitSub(const Viewport &view, uint32_t tileId, Vector2<int32_t> position, uint32_t flags = 0) const;
};

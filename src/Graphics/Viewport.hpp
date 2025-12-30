#pragma once

#include "../Vector2.hpp"
#include "../Rect.hpp"
#include "../wasm4.hpp"

class Viewport {
    public:
        Vector2<int32_t> position{};
        Vector2<uint32_t> size{SCREEN_SIZE, SCREEN_SIZE};
        Vector2<int32_t> offset{};

        Viewport()
            : position(), size({SCREEN_SIZE, SCREEN_SIZE}), offset()
        {}

        Viewport(Vector2<int32_t> position, Vector2<uint32_t> size)
            : position(position), size(size)
        {}

        IntRect transform(const IntRect &rect) const;
        FloatRect transform(const FloatRect &rect) const;
};

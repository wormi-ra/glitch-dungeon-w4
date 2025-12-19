#pragma once

#include "IDrawable.hpp"

struct Spellbar : public IDrawable {
    public:
        Vector2<int32_t> position{};
        Vector2<uint32_t> size{1,1};
        uint16_t rectColor = 0x41;
        uint16_t textColor = 0x04;

        Spellbar() = default;
        Spellbar(Vector2<int32_t> position, Vector2<uint32_t> size)
            : position(position), size(size)
        {}

        virtual void draw(const Viewport &view) const override;
};

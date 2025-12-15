#pragma once

#include "IDrawable.hpp"

struct TextBox : public IDrawable {
    public:
        const char *text = nullptr;
        Vector2<int32_t> position{};
        Vector2<uint32_t> size{1,1};
        Vector2<int32_t> padding{4,4};
        uint16_t rectColor = 0x41;
        uint16_t textColor = 0x04;

        TextBox() = default;
        TextBox(const char *text, Vector2<int32_t> position, Vector2<uint32_t> size)
            : text(text), position(position), size(size)
        {}

        virtual void draw(const Viewport &view) const;
};

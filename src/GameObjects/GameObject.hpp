#pragma once

#include "../Vector2.hpp"
#include "../Graphics/IDrawable.hpp"
#include "../Graphics/Sheet.hpp"
#include "../DynamicArray.hpp"

class GameObject : public IDrawable {
    public:
        Vector2<float> position {};
        IntRect bbox {};
        DynamicArray<uint8_t> animation {0};
        uint32_t animSpeed = 1;
        uint32_t currentFrame = 0;

        GameObject(const Sheet *sheet)
            : m_sheet(sheet)
        {}

        virtual uint16_t getDrawColor() const = 0;
        virtual void update();
        virtual void draw(const Viewport &view) const;

    protected:
        const Sheet *m_sheet;
        uint32_t m_animTimer = 0;
};

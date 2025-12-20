#pragma once

#include "../Vector2.hpp"
#include "../Graphics/IDrawable.hpp"
#include "../Graphics/Sheet.hpp"

typedef const int8_t anim_t;

class GameObject : public IDrawable {
    public:
        Vector2<float> position {};
        Vector2<float> velocity {};
        IntRect bbox {};
        anim_t *animation {};
        const Sheet *sheet {};
        uint32_t flags = 0;
        uint8_t animLength = 0;
        uint8_t animSpeed = 1;
        uint8_t currentFrame = 0;

        GameObject(const Sheet *sheet)
            : sheet(sheet)
        {}

        bool collidesWith(const GameObject &other) const;
        virtual uint16_t getDrawColor() const = 0;
        virtual void update();
        virtual void draw(const Viewport &view) const;

    protected:
        uint8_t m_animTimer = 0;
};

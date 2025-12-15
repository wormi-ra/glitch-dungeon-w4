#pragma once

#include "Viewport.hpp"

class IDrawable
{
    public:
        virtual ~IDrawable() = default;

        virtual void draw(const Viewport &view) const = 0;
};

#include "Negative.hpp"

Glitch::Type Glitch::Negative::getType() const {
    return Type::NEGATIVE;
}

const uint32_t *Glitch::Negative::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0xb1433e, // tmp
        0x4d999d, // tmp
        0xffffff,
    };
    return palette;
}

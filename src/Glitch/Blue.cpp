#include "Blue.hpp"

Glitch::Type Glitch::Blue::getType() const {
    return Type::BLUE;
}

const uint32_t *Glitch::Blue::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x884079,
        0xc16ac1,
        0xd5c0ff,
    };
    return palette;
}

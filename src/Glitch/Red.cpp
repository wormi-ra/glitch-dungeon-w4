#include "Red.hpp"

Glitch::Type Glitch::Red::getType() const {
    return Type::RED;
}

const char *Glitch::Red::getName() const {
    return "floor";
}

const uint32_t *Glitch::Red::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x571a0b,
        0xb1433e,
        0x4d999d,
    };
    return palette;
}

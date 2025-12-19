#include "Pink.hpp"

Glitch::Type Glitch::Pink::getType() const {
    return Type::PINK;
}

const char *Glitch::Pink::getName() const {
    return "memory";
}

const uint32_t *Glitch::Pink::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x08368d,
        0xe2dd75,
        0x88f0a9,
    };
    return palette;
}

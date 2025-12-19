#include "Gold.hpp"

Glitch::Type Glitch::Gold::getType() const {
    return Type::GOLD;
}

const char *Glitch::Gold::getName() const {
    return "wall";
}

const uint32_t *Glitch::Gold::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x6d6504,
        0xc1b40c,
        0xeae096,
    };
    return palette;
}

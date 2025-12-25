#include "Negative.hpp"

bool Glitch::Negative::isFallthrough(Tile::Type collision) const {
    return (collision == Tile::Type::FALLTHROUGH)
        || (collision == Tile::Type::KILL_PLAYER)
        || (collision == Tile::Type::SOLID);
}


Glitch::Type Glitch::Negative::getType() const {
    return Type::NEGATIVE;
}

const char *Glitch::Negative::getName() const {
    return "undefined";
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

#include "Grey.hpp"

Glitch::Type Glitch::Grey::getType() const {
    return Type::GREY;
}

const char *Glitch::Grey::getName() const {
    return nullptr;
}

const uint32_t *Glitch::Grey::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x403438,
        0x5c4e40,
        0x807870,
    };
    return palette;
}

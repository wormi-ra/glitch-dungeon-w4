#include "Zero.hpp"

Glitch::Zero::Zero()
{
    this->m_physics = {
        .flags = Physics::IS_INVISIBLE
    };
}

Glitch::Type Glitch::Zero::getType() const {
    return Type::ZERO;
}

const char *Glitch::Zero::getName() const {
    return "invisible";
}

const uint32_t *Glitch::Zero::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x822512,
        0x3e44b3,
        0xed9e3b,
    };
    return palette;
}

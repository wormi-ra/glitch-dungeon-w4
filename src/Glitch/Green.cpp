#include "Green.hpp"

Glitch::Green::Green()
{
    this->m_physics = {
        .jumpVelocity = 3.3f,
        .terminalVelocity = 1.0f,
        .originalGravAcc = 0.2f,
        .floatGravAcc = 0.2f,
        .jumpTimeLimit = 60,
        .maxRunVelocity = 2.0f,
	    .gndRunAcc = 2.0f / 5.0f,
	    .gndRunDec = 2.0f / 15.0f,
	    .airRunAcc = 2.0f / 10.0f,
	    .airRunDec = 2.0f / 30.0f,
    };
}

const char *Glitch::Green::getName() const {
    return "feather";
}

Glitch::Type Glitch::Green::getType() const {
    return Type::GREEN;
}

const uint32_t *Glitch::Green::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x183c5c,
        0x4b8636,
        0xf9e0a2,
    };
    return palette;
}

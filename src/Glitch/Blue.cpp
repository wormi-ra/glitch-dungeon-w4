#include "Blue.hpp"
#include "../GameObjects/Player.hpp"

Glitch::Blue::Blue()
{
    this->m_physics = {
        .jumpVelocity = -4.5f,
        .terminalVelocity = -7.0f,
        // .originalGravAcc = 0.8f,
        // .floatGravAcc = 0.4f,
    };
}

Glitch::Type Glitch::Blue::getType() const {
    return Type::BLUE;
}

const char *Glitch::Blue::getName() const {
    return "gravity";
}

const uint32_t *Glitch::Blue::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x884079,
        0xc16ac1,
        // 0xc0daff,
        0xd5c0ff,
    };
    return palette;
}

void Glitch::Blue::transformPlayer(Player &player, Room &) {
    player.bbox.position.y = 0;
    player.position.y += 2;
    player.flags |= BLIT_FLIP_Y;
}

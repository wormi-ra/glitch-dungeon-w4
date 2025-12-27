#include "Negative.hpp"
#include "../GameObjects/Player.hpp"

bool Glitch::Negative::isFallthrough(Tile::Type collision) const {
    return (collision == Tile::Type::FALLTHROUGH)
        || (collision == Tile::Type::KILL_PLAYER)
        || (collision == Tile::Type::SOLID);
}

bool Glitch::Negative::collidesWith(Tile::Type collision) const {
    return (collision == Tile::Type::SOLID 
        || collision == Tile::Type::SUPER_SOLID
        || collision == Tile::Type::FALLTHROUGH
        || collision == Tile::Type::KILL_PLAYER);
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

void Glitch::Negative::transformPlayer(Player &player, Room &) {
    player.state &= ~Player::IS_STUCK;
    player.state &= ~Player::CHECK_STUCK;
}

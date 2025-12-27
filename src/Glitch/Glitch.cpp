#include "Grey.hpp"
#include "Green.hpp"
#include "Red.hpp"
#include "Zero.hpp"
#include "Blue.hpp"
#include "Gold.hpp"
#include "Negative.hpp"
#include "Pink.hpp"
#include "../GameObjects/Player.hpp"
#include "../Room.hpp"

const Glitch::Physics &Glitch::Glitch::getPhysics() const {
    return this->m_physics;
}

bool Glitch::Glitch::collidesWith(Tile::Type collision) const {
    return (collision == Tile::Type::SOLID 
        || collision == Tile::Type::SUPER_SOLID
        || collision == Tile::Type::FALLTHROUGH);
}

bool Glitch::Glitch::isFallthrough(Tile::Type collision) const {
    return (collision == Tile::Type::FALLTHROUGH);
}

void Glitch::Glitch::transformPlayer(Player &, Room &) {
    return;
}

static auto GLITCH_GREY = Glitch::Grey();
static auto GLITCH_RED = Glitch::Red();
static auto GLITCH_GREEN = Glitch::Green();
static auto GLITCH_ZERO = Glitch::Zero();
static auto GLITCH_BLUE = Glitch::Blue();
static auto GLITCH_GOLD = Glitch::Gold();
static auto GLITCH_NEGATIVE = Glitch::Negative();
static auto GLITCH_PINK = Glitch::Pink();

Glitch::Glitch *const Glitch::SPELLS[SPELL_COUNT] = {
    &GLITCH_GREY,
    &GLITCH_RED,
    &GLITCH_GREEN,
    &GLITCH_ZERO,
    &GLITCH_BLUE,
    &GLITCH_GOLD,
    &GLITCH_NEGATIVE,
    &GLITCH_PINK
};

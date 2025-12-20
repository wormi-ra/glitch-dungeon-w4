#include "Player.hpp"
#include "../Input.hpp"
#include "../wasm4.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"
#include "../utils.hpp"
#include <cstdint>

Player::Player()
    : GameObject(&Data::PLAYER_SHEET)
{
    this->position = {20,72};
    this->bbox = {{2, 2}, {14, 16}};
    // this->spellbook = {
    //     Glitch::SPELLS[1],
    //     Glitch::SPELLS[2],
    //     Glitch::SPELLS[3],
    //     Glitch::SPELLS[4],
    //     Glitch::SPELLS[5],
    //     Glitch::SPELLS[6],
    //     Glitch::SPELLS[7],
    //  };
}

Glitch::Glitch &Player::setSpell(Glitch::Type spell) {
    if (spell != this->glitch->getType()) {
        this->glitch = Glitch::SPELLS[static_cast<uint8_t>(spell)];
        Game::setPalette(this->glitch->getPalette());
        Game::stats.spells++;
    }
    return *this->glitch;
}

Glitch::Glitch &Player::nextSpell() {
    if (!(this->state & HAS_GRIMOIRE) || this->spellbook.empty()) {
        return *this->glitch;
    }
    int32_t index = -1;
    int32_t i = 0;
    for (const auto &glitch : this->spellbook) {
        if (glitch->getType() == this->glitch->getType()) {
            index = i;
            break;
        }
        i++;
    }
    auto idx = mod(static_cast<uint32_t>(index + 1), this->spellbook.size());
    return this->setSpell(this->spellbook[idx]->getType());
}

void Player::giveSpell(Glitch::Type spell) {
    for (const auto &glitch : this->spellbook) {
        if (glitch->getType() == spell) {
            return;
        }
    }
    this->spellbook.emplace_back(Glitch::SPELLS[static_cast<uint8_t>(spell)]);
}

void Player::applyOffscreenLogic() {
    constexpr auto tileSize = 8.0f;

    if (this->position.y + static_cast<float>(this->bbox.size.y) <= 0) {
        auto &room = Game::moveRoom(0, -1);
        if (this->position.x <= tileSize)
            this->position.x += tileSize;
        if (this->position.x >= room.width * tileSize - tileSize)
            this->position.x -= tileSize;
        this->position.y = room.height * tileSize - tileSize - static_cast<float>(this->bbox.size.y);
    } else if (this->position.y + static_cast<float>(this->bbox.position.y) >= (static_cast<float>(Game::currentRoom->data->height) * tileSize)) {
        auto &room = Game::moveRoom(0, 1);
        if (this->position.x <= tileSize)
            this->position.x += tileSize;
        if (this->position.x >= room.width * tileSize - tileSize)
            this->position.x -= tileSize;
        this->position.y = (tileSize / 2.0f) + static_cast<float>(this->bbox.position.y);
    }
    if (this->position.x <= 0) {
        auto &room = Game::moveRoom(-1, 0);
        this->position.x = room.width * tileSize - (tileSize / 2.0f) - static_cast<float>(this->bbox.size.x);
    } else if (this->position.x + tileSize >= (Game::currentRoom->data->width * tileSize)) {
        Game::moveRoom(1, 0);
        this->position.x = (tileSize / 2.0f) - static_cast<float>(this->bbox.position.x);
    }
}

void Player::update() {
    if (Input::isPressed(BUTTON_LEFT))
        this->position.x -= 2.0f;
    if (Input::isPressed(BUTTON_RIGHT))
        this->position.x += 2.0f;
    if (Input::isPressed(BUTTON_UP))
        this->position.y -= 2.0f;
    if (Input::isPressed(BUTTON_DOWN))
        this->position.y += 2.0f;
    if (Input::isPressedDown(BUTTON_1))
        this->nextSpell();
    this->applyOffscreenLogic();
    this->state |= (IS_GROUNDED);
}

uint16_t Player::getDrawColor() const {
    switch (this->glitch->getType()) {
        case Glitch::Type::ZERO:
            return 0x3014;
        case Glitch::Type::NEGATIVE:
            return 0x4011;
        case Glitch::Type::BLUE:
            return 0x1043;
        case Glitch::Type::PINK:
            return 0x1043;
        default:
            return 0x1034;
    }
}

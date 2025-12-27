#include "Player.hpp"
#include "../Input.hpp"
#include "../wasm4.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"
#include "../utils.hpp"
#include "../Function.hpp"
#include "GameObject.hpp"
#include <cstdint>

static const anim_t PLAYER_IDLE[] {
    0
};

static const anim_t PLAYER_RUNNING[] {
    1, 2, 3, 2
};

static const anim_t PLAYER_JUMPING[] {
    1, 4
};

Player::Player()
    : GameObject(&Data::PLAYER_SHEET)
{
    this->position = {20,72};
    this->bbox = {IntRect::BBox {2, 2, 14, 16}};
    this->setAnimation(PLAYER_IDLE, 1);
}

uint16_t Player::getDrawColor() const {
    if (Game::roomPosition == Vector2<uint8_t>(5, 5))
        return 0x1023;
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

void Player::normalize() {
    this->bbox = {IntRect::BBox {2, 2, 14, 16}};
    this->state &= ~Player::State::CHECK_STUCK;
    if (this->glitch->getType() == Glitch::Type::NEGATIVE) {
        this->state |= Player::CHECK_STUCK;
    }
    this->flags &= ~BLIT_FLIP_Y;
    auto &physics = this->glitch->getPhysics();
    this->gravAcc = physics.originalGravAcc;
    if (this->state & IS_JUMPING) {
        this->gravAcc = physics.floatGravAcc;
    }
}

Glitch::Glitch &Player::setSpell(Glitch::Type spell, bool forced) {
    if (!this->canUseSpellbook() && !forced) {
        if (!Game::currentRoom->data->can_use_spellbook && Game::roomPosition != Vector2<uint8_t>(5, 5)) {
            Game::textBox.setText("a dark force\nprevents you from\ncasting spells here");
            // TODO Play denied spell sound
        }
        return *this->glitch;
    }
    if (spell != this->glitch->getType()) {
        this->normalize();
        if (spell != Glitch::Type::RED)
            this->state &= ~ON_GROUND;
        Glitch::SPELLS[uint8_t(spell)]->transformPlayer(*this, *Game::currentRoom);
        this->glitch = Glitch::SPELLS[uint8_t(spell)];
        this->gravAcc = this->glitch->getPhysics().originalGravAcc;
        Game::setPalette(this->glitch->getPalette());
        if (!forced) {
            // TODO Play change spell sound
            Game::stats.spells++;
        }
    }
    return *this->glitch;
}

bool Player::canUseSpellbook() const {
    return (this->state & HAS_GRIMOIRE) 
        && !this->spellbook.empty()
        && Game::currentRoom->data->can_use_spellbook;
}

Glitch::Glitch &Player::nextSpell() {
    if (!this->canUseSpellbook()) {
        return this->setSpell(this->glitch->getType());
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
    auto idx = mod(uint32_t(index + 1), this->spellbook.size());
    return this->setSpell(this->spellbook[idx]->getType());
}

void Player::giveSpell(Glitch::Type spell) {
    for (const auto &glitch : this->spellbook) {
        if (glitch->getType() == spell) {
            return;
        }
    }
    this->spellbook.emplace_back(Glitch::SPELLS[uint8_t(spell)]);
}

void Player::applyOffscreenLogic() {
    constexpr auto tileSize = 8.0f;
    auto bbox = this->bbox.bbox();

    if (this->position.y + float(bbox.bb) <= 0) {
        Game::moveRoom(0, -1, [this, bbox]() {
            auto &room = Game::currentRoom->data;
            if (this->position.x <= tileSize)
                this->position.x += tileSize;
            if (this->position.x >= ((room->width - 1) * tileSize))
                this->position.x -= tileSize;
            this->position.y = ((room->height - 1 ) * tileSize) - float(bbox.bb);
        });
    } else if (this->position.y + float(bbox.tb) >= (float(Game::currentRoom->data->height) * tileSize)) {
        Game::moveRoom(0, 1, [this, bbox]() {
            auto &room = Game::currentRoom->data;
            if (this->position.x <= tileSize)
                this->position.x += tileSize;
            if (this->position.x >= ((room->width - 1) * tileSize))
                this->position.x -= tileSize;
            this->position.y = (tileSize / 2.0f) + float(bbox.tb);
        });
    }
    if (this->position.x <= 0) {
        Game::moveRoom(-1, 0, [this, bbox]() {
            auto &room = Game::currentRoom->data;
            this->position.x = room->width * tileSize - (tileSize / 2.0f) - float(bbox.rb);
        });
    } else if (this->position.x + tileSize >= (Game::currentRoom->data->width * tileSize)) {
        Game::moveRoom(1, 0, [this, bbox]() {
            this->position.x = (tileSize / 2.0f) - float(bbox.lb);
        });
    }
}

void Player::update() {
    GameObject::update();
    this->processInputs();
    if (this->state & CHECK_STUCK)
        this->checkStuck();
    if (!(this->state & IS_STUCK))
        this->applyPhysics();
    else
        this->velocity = {0, 0};
    this->applyAnimationFromState();
    this->applyOffscreenLogic();
}

void Player::processInputs() {
    if (Input::isPressed(BUTTON_RIGHT)) {
        this->setFacing(Facing::RIGHT);
        this->moveHorizontal(1.0f);
    } else if (Input::isPressed(BUTTON_LEFT)) {
        this->setFacing(Facing::LEFT);
        this->moveHorizontal(-1.0f);
    }
    if (Input::isPressedDown(BUTTON_UP))
        this->startJump();
    else if (Input::isPressed(BUTTON_UP))
        this->jump();
    if (Input::isPressedUp(BUTTON_UP))
        this->stopJump();
    this->state &= ~PRESSED_DOWN;
    if (Input::isPressedDown(BUTTON_DOWN)) {
        this->state |= PRESSED_DOWN;
        this->state &= ~ON_GROUND;
    }
    if (Input::isPressedDown(BUTTON_1))
        this->nextSpell();
    if (Input::isPressedDown(BUTTON_2))
        this->die();
    uint8_t spellIndex = 0xff;
    if (Input::isPressedDown(BUTTON_UP, Gamepad::gamepad2))
        spellIndex = 0;
    else if (Input::isPressedDown(BUTTON_LEFT, Gamepad::gamepad2))
        spellIndex = 1;
    else if (Input::isPressedDown(BUTTON_DOWN, Gamepad::gamepad2))
        spellIndex = 2;
    else if (Input::isPressedDown(BUTTON_RIGHT, Gamepad::gamepad2))
        spellIndex = 3;
    else if (Input::isPressedDown(BUTTON_1, Gamepad::gamepad2))
        spellIndex = 4;
    else if (Input::isPressedDown(BUTTON_2, Gamepad::gamepad2))
        spellIndex = 5;
    if (spellIndex < this->spellbook.size())
        this->setSpell(this->spellbook.at(spellIndex)->getType());
}

void Player::moveHorizontal(float direction) {
    auto &physics = this->glitch->getPhysics();
    auto acc = (this->state & ON_GROUND) ? physics.gndRunAcc : physics.airRunAcc;

    this->state |= HORIZONTAL_INPUT;
    if (std::abs(this->velocity.x) > physics.maxRunVelocity)
        acc = -acc;
    this->velocity.x = std::clamp(this->velocity.x + acc * direction, -physics.maxRunVelocity, physics.maxRunVelocity);
}

void Player::stopMove() {
    auto dec = (this->state & ON_GROUND) ? this->glitch->getPhysics().gndRunDec : this->glitch->getPhysics().airRunDec;

    if (this->velocity.x > 0.0f) {
        this->velocity.x = std::max(this->velocity.x - dec, 0.0f);
    } else if (this->velocity.x < 0.0f) {
        this->velocity.x = std::min(this->velocity.x + dec, 0.0f);
    }
}

void Player::startJump() {
    if (!(this->state & ON_GROUND))
        return;
    this->velocity.y = -this->glitch->getPhysics().jumpVelocity;
    this->jumpTimer = 0;
    this->state &= ~ON_GROUND;
    this->state |= IS_JUMPING;
}

void Player::jump() {
    if (this->state & IS_JUMPING) {
        auto &physics = this->glitch->getPhysics();
        this->jumpTimer += 1;
        if (this->jumpTimer >= physics.jumpTimeLimit) {
            this->stopJump();
        } else {
            this->gravAcc = physics.floatGravAcc;
            this->velocity.y += (-physics.jumpVelocity * ((float(physics.jumpTimeLimit) - (float(this->jumpTimer) / 2.0f)) / float(physics.jumpTimeLimit * 60)));
        }
    }

}

void Player::stopJump() {
    this->jumpTimer = 0;
    this->state &= ~IS_JUMPING;
    this->gravAcc = this->glitch->getPhysics().originalGravAcc;
}

bool Player::tileCollide(Vector2<uint32_t> tile, FloatRect bbox) const {
    FloatRect tileRect = {
        Vector2<float>(tile * 8u),
        {8, 8},
    };
    bbox.position += this->position;
    return bbox.intersects(tileRect);
}

void Player::checkStuck() {
    constexpr auto tileSize = 8u;
    constexpr auto q = 3;
    auto bbox = FloatRect(this->bbox).bbox();
    auto left_tile = uint32_t(std::floor(
        std::max(this->position.x + bbox.lb + this->velocity.x - 1, 0.0f) / tileSize
    ));
    auto right_tile = uint32_t(std::ceil(
        std::min((this->position.x + bbox.rb + this->velocity.x + 1) / tileSize, float(Game::currentRoom->data->width))
    ));
    auto top_tile = uint32_t(std::floor(
        std::max(this->position.y + bbox.tb + this->velocity.y - 1, 0.0f) / tileSize
    ));
    auto bottom_tile = uint32_t(std::ceil(
        std::min((this->position.y + bbox.bb + this->velocity.y + 1)  / tileSize, float(Game::currentRoom->data->height))  
    ));

    enum collision_t {
        TOP =   1 << 0,
        LEFT =  1 << 1,
        RIGHT = 1 << 2,
        BOTTOM =    1 << 3,
    };
    uint8_t collisionState = 0x0;

    this->state &= ~Player::CHECK_STUCK;
    for (auto y = top_tile; y < bottom_tile; y++) {
        for (auto x = left_tile; x < right_tile; x++) {
            auto collision = Tile::getCollision(Game::currentRoom->getTile(x, y));
            if (collision == Tile::Type::GHOST || collision == Tile::Type::FALLTHROUGH)
                continue;
            //left collisions
            if (this->tileCollide({x, y},
                FloatRect::BBox {bbox.lb, bbox.tb + q, bbox.lb, bbox.bb - q})) {
                collisionState |= LEFT;
                if (collisionState & RIGHT) {
                    this->state |= IS_STUCK;
                    return;
                }
            }
            // right collisions
            if (this->tileCollide({x, y},
                FloatRect::BBox {bbox.rb, bbox.tb + q, bbox.rb, bbox.bb - q})) {
                collisionState |= RIGHT;
                if (collisionState & LEFT) {
                    this->state |= IS_STUCK;
                    return;
                }
            }
            // top collisions
            if (this->tileCollide({x, y}, FloatRect::BBox {bbox.lb + q , bbox.tb, bbox.rb - q, bbox.tb})) {
                collisionState |= TOP;
                if (collisionState & BOTTOM) {
                    this->state |= IS_STUCK;
                    return;
                }
            }
            // bottom collisions
            if (this->tileCollide({x, y}, FloatRect::BBox {bbox.lb + q, bbox.bb, bbox.rb - q, bbox.bb})) {
                collisionState |= BOTTOM;
                if (collisionState & TOP) {
                    this->state |= IS_STUCK;
                    return;
                }
            }
        }
    }
}

void Player::applyCollisions() {
    constexpr auto tileSize = 8u;
    constexpr auto q = 3;
    auto bbox = FloatRect(this->bbox).bbox();
    auto left_tile = uint32_t(std::floor(
        std::max(this->position.x + bbox.lb + this->velocity.x - 1, 0.0f) / tileSize
    ));
    auto right_tile = uint32_t(std::ceil(
        std::min((this->position.x + bbox.rb + this->velocity.x + 1) / tileSize, float(Game::currentRoom->data->width))
    ));
    auto top_tile = uint32_t(std::floor(
        std::max(this->position.y + bbox.tb + this->velocity.y - 1, 0.0f) / tileSize
    ));
    auto bottom_tile = uint32_t(std::ceil(
        std::min((this->position.y + bbox.bb + this->velocity.y + 1)  / tileSize, float(Game::currentRoom->data->height))  
    ));
    bool wasOnGround = this->state & ON_GROUND;

    if (!(this->glitch->getPhysics().flags & Glitch::Physics::CAN_FLOAT)) {
        this->state &= ~ON_GROUND;
    }
    this->state &= ~CLIMBING;
    this->state &= ~HORIZONTAL_COLLISION;
    for (auto y = top_tile; y < bottom_tile; y++) {
        for (auto x = left_tile; x < right_tile; x++) {
            auto collision = Tile::getCollision(Game::currentRoom->getTile(x, y));
            if (collision == Tile::Type::KILL_PLAYER
                && !(Game::player.glitch->getPhysics().flags & Glitch::Physics::IS_INVISIBLE)
                && this->tileCollide({x, y}, FloatRect({bbox.lb + q, bbox.tb + q, bbox.rb - q, bbox.bb - q}))) {
                this->die();
                return;
            }
            if (!this->glitch->collidesWith(collision) || this->glitch->isFallthrough(collision))
                continue;
            //left collisions
            if (this->velocity.x < 0 && this->tileCollide({x, y},
                FloatRect::BBox {bbox.lb + this->velocity.x - 1, bbox.tb + q, bbox.lb, bbox.bb - q})) {
                this->position.x = float(x * tileSize + tileSize) - bbox.lb;
                this->velocity.x = 0;
                this->state |= HORIZONTAL_COLLISION;
            }
            // right collisions
            if (this->velocity.x > 0 && this->tileCollide({x, y},
                FloatRect::BBox {bbox.rb, bbox.tb + q, bbox.rb + this->velocity.x + 1, bbox.bb - q})) {
                this->position.x = float(x * tileSize) - bbox.rb;
                this->velocity.x = 0;
                this->state |= HORIZONTAL_COLLISION;
            }
        }
    }
    this->position.x += this->velocity.x;
    if ((this->state & HORIZONTAL_COLLISION) && (this->state & HORIZONTAL_INPUT) && (this->glitch->getPhysics().flags & Glitch::Physics::CAN_CLIMB)) {
        this->velocity.y = -1.0f;
        this->state |= CLIMBING;
    }
    for (auto y = top_tile; y < bottom_tile; y++) {
        for (auto x = left_tile; x < right_tile; x++) {
            auto collision = Tile::getCollision(Game::currentRoom->getTile(x, y));
            if (!this->glitch->collidesWith(collision))
                continue;
            // top collisions
            if (((this->isReverse() || (this->glitch->getType() == Glitch::Type::NEGATIVE)) ? this-> velocity.y <= 0 : this->velocity.y < 0)
                && !(!this->isReverse() && this->glitch->isFallthrough(collision))
                && this->tileCollide({x, y}, FloatRect::BBox {bbox.lb + q , bbox.tb + this->velocity.y - 1, bbox.rb - q, bbox.tb})) {
                if (this->isReverse() 
                    && this->glitch->isFallthrough(collision)
                    && (float(y * tileSize + tileSize) > this->position.y
                        || Input::isPressed(BUTTON_DOWN))) {
                    continue;
                }
                this->position.y = float(y * tileSize) + tileSize - bbox.tb;
                this->velocity.y = 0;
                if (this->isReverse())
                    this->state |= ON_GROUND;
            }
            // bottom collisions
            if (((!this->isReverse() || (this->glitch->getType() == Glitch::Type::NEGATIVE)) ? this-> velocity.y >= 0 : this->velocity.y > 0)
                && this->tileCollide({x, y}, FloatRect::BBox {bbox.lb + q, bbox.bb, bbox.rb - q, bbox.bb + this->velocity.y + 1})) {
                if (this->isReverse()) {
                    if (this->glitch->isFallthrough(collision)) {
                        continue;
                    }
                } else if (this->glitch->getType() == Glitch::Type::NEGATIVE) {
                    if ((float(y * tileSize) < this->position.y + bbox.bb)
                        || (Input::isPressed(BUTTON_DOWN)
                            && !((this->state & TOUCHING_DOOR) && (this->state & PRESSED_DOWN))
                            && this->glitch->isFallthrough(collision))) {
                        continue;
                    }
                } else if (this->glitch->isFallthrough(collision)
                    && (float(y * tileSize) < this->position.y + bbox.bb || Input::isPressed(BUTTON_DOWN))) {
                        continue;
                }
                this->position.y = float(y * tileSize) - bbox.bb;
                this->velocity.y = 0;
                if (!this->isReverse())
                    this->state |= ON_GROUND;
            }
        }
    }
    if (!wasOnGround) {
        if (this->state & ON_GROUND) {
            // Play fall sound
        } else {
            this->state &= ~PRESSED_DOWN;
        }
    }
    this->position.y += this->velocity.y;
}

void Player::applyGravity() {
    const auto &physics = this->glitch->getPhysics();

    if (!(this->state & ON_GROUND)){
        if (this->velocity.y < physics.terminalVelocity) {
            this->velocity.y = std::min(this->velocity.y + this->gravAcc, physics.terminalVelocity);
        } else if (this->velocity.y > physics.terminalVelocity) {
            this->velocity.y = std::max(this->velocity.y - this->gravAcc, physics.terminalVelocity);
        }
    } else {
        this->velocity.y = 0;
    }
}

void Player::setCheckpoint(Checkpoint &checkpoint) {
    // TODO Play checkpoint sound
    for (auto &entity : Game::currentRoom->entities) {
        if (entity->getId() == this->checkpointId) {
            static_cast<Checkpoint *>(entity)->deactivate();
            break;
        }
    }
    this->respawnRoom = Game::roomPosition;
    this->checkpointId = checkpoint.getId();
    if (this->customCheckpoint != nullptr) {
        delete this->customCheckpoint;
        this->customCheckpoint = nullptr;
    }
}

const Data::Checkpoint *Player::getCheckpoint() const {
    if (this->customCheckpoint != nullptr) {
        return this->customCheckpoint->data;
    } else if (this->checkpointId != 0)
        return static_cast<const Data::Checkpoint *>(Data::ENTITIES[this->checkpointId]);
    return nullptr;
}

void Player::die() {
    if (Game::state & Game::State::BEAT_GAME)
        return;
    Game::stats.deaths++;
    Game::textBox.setText(nullptr, 0);
    // TODO Play death sound
    Game::loadRoom(this->respawnRoom.x, this->respawnRoom.y, [this]() {
        auto checkpoint = this->getCheckpoint();

        if (checkpoint != nullptr) {
            this->position = Vector2<float>(checkpoint->position);
        } else {
            this->position = {20,72};
        }
        this->velocity = {0, 0};
        this->state &= ~CHECK_STUCK;
        this->state &= ~IS_STUCK;
    });
}

void Player::applyPhysics() {
    this->applyGravity();
    if (!(this->state & HORIZONTAL_INPUT)) {
        this->stopMove();
    }
    this->applyCollisions();
    this->state &= ~HORIZONTAL_INPUT;
    this->state &= ~TOUCHING_DOOR;
}

void Player::applyAnimationFromState() {
    if (this->state & State::CLIMBING) {
        this->setAnimation(PLAYER_RUNNING, sizeof(PLAYER_RUNNING) / sizeof(anim_t));
    } else if (this->velocity.y != 0.0f) {
        this->setAnimation(PLAYER_JUMPING, sizeof(PLAYER_JUMPING) / sizeof(anim_t));
    } else if (this->velocity.x != 0.0f) {
        this->setAnimation(PLAYER_RUNNING, sizeof(PLAYER_RUNNING) / sizeof(anim_t));
    } else {
        this->setAnimation(PLAYER_IDLE, sizeof(PLAYER_IDLE) / sizeof(anim_t));
    }
}


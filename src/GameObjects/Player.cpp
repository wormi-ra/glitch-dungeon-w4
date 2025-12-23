#include "Player.hpp"
#include "../Input.hpp"
#include "../wasm4.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"
#include "../utils.hpp"
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
    this->state |= HAS_GRIMOIRE; 
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
    auto bbox = this->bbox.bbox();

    if (this->position.y + static_cast<float>(bbox.bb) <= 0) {
        Game::moveRoom(0, -1, [this, bbox]() {
            auto &room = Game::currentRoom->data;
            if (this->position.x <= tileSize)
                this->position.x += tileSize;
            if (this->position.x >= ((room->width - 1) * tileSize))
                this->position.x -= tileSize;
            this->position.y = ((room->height - 1 ) * tileSize) - static_cast<float>(bbox.bb);
        });
    } else if (this->position.y + static_cast<float>(bbox.tb) >= (static_cast<float>(Game::currentRoom->data->height) * tileSize)) {
        Game::moveRoom(0, 1, [this, bbox]() {
            auto &room = Game::currentRoom->data;
            if (this->position.x <= tileSize)
                this->position.x += tileSize;
            if (this->position.x >= ((room->width - 1) * tileSize))
                this->position.x -= tileSize;
            this->position.y = (tileSize / 2.0f) + static_cast<float>(bbox.tb);
        });
    }
    if (this->position.x <= 0) {
        Game::moveRoom(-1, 0, [this, bbox]() {
            auto &room = Game::currentRoom->data;
            this->position.x = room->width * tileSize - (tileSize / 2.0f) - static_cast<float>(bbox.rb);
        });
    } else if (this->position.x + tileSize >= (Game::currentRoom->data->width * tileSize)) {
        Game::moveRoom(1, 0, [this, bbox]() {
            this->position.x = (tileSize / 2.0f) - static_cast<float>(bbox.lb);
        });
    }
}

void Player::update() {
    GameObject::update();
    this->processInputs();
    this->applyAnimationFromState();
    this->applyPhysics();
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
    // if (Input::isPressed(BUTTON_DOWN))
    //     this->position.y += 2.0f;
    if (Input::isPressedDown(BUTTON_1))
        this->nextSpell();
    if (Input::isPressedDown(BUTTON_2))
        this->die();
}

void Player::moveHorizontal(float direction) {
    this->state |= HORIZONTAL_INPUT;
    this->velocity.x = direction * this->glitch->getPhysics().maxRunVelocity;
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
            this->velocity.y += (-physics.jumpVelocity * ((static_cast<float>(physics.jumpTimeLimit) - (static_cast<float>(this->jumpTimer) / 2.0f)) / static_cast<float>(physics.jumpTimeLimit * 60)));
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

void Player::applyCollisions() {
    constexpr auto tileSize = 8u;
    constexpr auto q = 3;
    auto bbox = FloatRect(this->bbox).bbox();
    auto left_tile = static_cast<uint32_t>(std::floor(
        std::max(this->position.x + bbox.lb + this->velocity.x - 1, 0.0f) / tileSize
    ));
    auto right_tile = static_cast<uint32_t>(std::ceil(
        std::min((this->position.x + bbox.rb + this->velocity.x + 1) / tileSize, static_cast<float>(Game::currentRoom->data->width))
    ));
    auto top_tile = static_cast<uint32_t>(std::floor(
        std::max(this->position.y + bbox.tb + this->velocity.y - 1, 0.0f) / tileSize
    ));
    auto bottom_tile = static_cast<uint32_t>(std::ceil(
        std::min((this->position.y + bbox.bb + this->velocity.y + 1)  / tileSize, static_cast<float>(Game::currentRoom->data->height))  
    ));

    this->state &= ~ON_GROUND;
    for (auto y = top_tile; y < bottom_tile; y++) {
        for (auto x = left_tile; x < right_tile; x++) {
            auto collision = Tile::getCollision(Game::currentRoom->getTile(x, y));
            if (!this->glitch->collidesWith(collision) || this->glitch->isFallthrough(collision))
                continue;
            //left collisions
            if (this->velocity.x < 0 && this->tileCollide({x, y},
                FloatRect::BBox {bbox.lb + this->velocity.x - 1, bbox.tb + q, bbox.lb, bbox.bb - q})) {
                if (collision == Tile::Type::KILL_PLAYER) {
                    this->die();
                    return;
                }
                this->position.x = static_cast<float>(x * tileSize + tileSize) - bbox.lb;
                this->velocity.x = 0;
                break;
            }
            // right collisions
            if (this->velocity.x > 0 && this->tileCollide({x, y},
                FloatRect::BBox {bbox.rb, bbox.tb + q, bbox.rb + this->velocity.x + 1, bbox.bb - q})) {
                if (collision == Tile::Type::KILL_PLAYER) {
                    this->die();
                    return;
                }
                this->position.x = static_cast<float>(x * tileSize) - bbox.rb;
                this->velocity.x = 0;
                break;
            }
        }
    }
    this->position.x += this->velocity.x;
    for (auto y = top_tile; y < bottom_tile; y++) {
        for (auto x = left_tile; x < right_tile; x++) {
            auto collision = Tile::getCollision(Game::currentRoom->getTile(x, y));
            if (!this->glitch->collidesWith(collision))
                continue;
            // top collisions
            if (this->velocity.y <= 0
                && !(!this->isReverse() && this->glitch->isFallthrough(collision))
                && this->tileCollide({x, y}, FloatRect::BBox {bbox.lb + q , bbox.tb + this->velocity.y - 1, bbox.rb - q, bbox.tb})) {
                if (this->isReverse() 
                    && this->glitch->isFallthrough(collision)
                    && (static_cast<float>(y * tileSize + tileSize) > this->position.y || Input::isPressed(BUTTON_DOWN))) {
                    continue;
                }
                if (collision == Tile::Type::KILL_PLAYER) {
                    this->die();
                    return;
                }
                this->position.y = static_cast<float>(y * tileSize) + tileSize - bbox.tb;
                this->velocity.y = 0;
                if (this->isReverse())
                    this->state |= ON_GROUND;
                break;
            }
            // bottom collisions
            if (this->velocity.y >= 0
                && !(this->isReverse() && this->glitch->isFallthrough(collision))
                && this->tileCollide({x, y}, FloatRect::BBox {bbox.lb + q, bbox.bb, bbox.rb - q, bbox.bb + this->velocity.y + 1})) {
                if (!this->isReverse()
                    && this->glitch->isFallthrough(collision) 
                    && (static_cast<float>(y * tileSize) < this->position.y + bbox.bb || Input::isPressed(BUTTON_DOWN))) {
                    continue;
                }
                if (collision == Tile::Type::KILL_PLAYER) {
                    this->die();
                    return;
                }                    
                this->position.y = static_cast<float>(y * tileSize) - bbox.bb;
                this->velocity.y = 0;
                if (!this->isReverse())
                    this->state |= ON_GROUND;
                break;
            }
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
    // TODO Play death sound
    Game::stats.deaths++;
    Game::loadRoom(this->respawnRoom.x, this->respawnRoom.y, [this]() {
        auto checkpoint = this->getCheckpoint();

        if (checkpoint != nullptr) {
            this->position = Vector2<float>(checkpoint->position);
        } else {
            this->position = {20,72};
        }
        this->velocity = {0, 0};
    });
}

void Player::applyPhysics() {
    this->applyGravity();
    if (!(this->state & HORIZONTAL_INPUT)) {
        this->stopMove();
    }
    this->applyCollisions();
    this->state &= ~HORIZONTAL_INPUT;
}

void Player::applyAnimationFromState() {
    if (!(this->state & State::ON_GROUND)) {
        this->setAnimation(PLAYER_JUMPING, sizeof(PLAYER_JUMPING) / sizeof(*PLAYER_JUMPING));
    } else if (this->velocity.x != 0.0f) {
        this->setAnimation(PLAYER_RUNNING, sizeof(PLAYER_RUNNING) / sizeof(*PLAYER_RUNNING));
    } else {
        this->setAnimation(PLAYER_IDLE, sizeof(PLAYER_IDLE) / sizeof(*PLAYER_IDLE));
    }
}


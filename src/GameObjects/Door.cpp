#include "Door.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"
#include "../Input.hpp"
#include "../utils.hpp"
#include "Entity.hpp"
#include <cstring>

static const anim_t DOOR_ANIM[] {0};

static const anim_t DOOR_LOCKED_ANIM[] {1, 1};

Door::Door(const Data::Door *data)
    : GameObject(&Data::DOOR_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {4, 0, 12, 16},
    };
    if (this->locked()) {
        this->animation = DOOR_LOCKED_ANIM;
        this->animLength = sizeof(DOOR_LOCKED_ANIM) / sizeof(anim_t);
    } else {
        this->animation = DOOR_ANIM;
        this->animLength = sizeof(DOOR_ANIM) / sizeof(anim_t);
    }
    this->animSpeed = 8;
}

IEntity::Type Door::getType() const {
    return IEntity::Type::DOOR;
}

bool Door::locked() const {
    return (this->data->num_artifacts > 0) && !this->interacted();
}

void Door::unlock() {
    Data::interactedEntities[this->getId()] = true;
    this->animation = DOOR_ANIM;
    this->animLength = sizeof(DOOR_ANIM) / sizeof(anim_t);
    Game::textBox.setText("door unlocked");
    // TODO play unlock sound;
}

uint16_t Door::getDrawColor() const {
    if (this->locked()) {
        return this->currentFrame ? 0x0324 : 0x0231;
    }
    return 0x1204;
}

static void onEnter(const Data::Door *target) {
    Game::player.velocity.x = 0;
    for (auto &entity : Game::currentRoom->entities) {
        if (entity->getType() == IEntity::Type::DOOR) {
            auto door = static_cast<const Entity<Data::Door> *>(entity);
            if (door->data->door_id == target->door_id && door->data != target) {
                Game::player.position = Vector2<float>(door->position);
            }
        }
    }
}

void Door::update() {
    GameObject::update();
    if (this->collidesWith(Game::player)
        && (Game::player.state & Player::PRESSED_DOWN)
        && (Game::player.state & Player::ON_GROUND)) {
        if (this->locked()) {
            if (Game::player.artifacts >= this->data->num_artifacts) {
                this->unlock();
            } else {
                static char lockText[64] = "";
                strcpy(lockText, "door is locked\nneed ");
                strcat(lockText, itoa(this->data->num_artifacts - Game::player.artifacts));
                strcat(lockText, "\nspells more");
                // TODO play locked sound
                Game::textBox.setText(lockText);
            }
        } else {
            Game::player.state &= ~(Player::ON_GROUND);
            auto target = this->data;
            auto roomX = this->data->room.x;
            auto roomY = this->data->room.y;
            if (Game::state & Game::GLITCHED) {
                if (Game::roomPosition == Vector2<uint8_t>(1, 0)) {
                    if (this->data->door_id == 0) {
                        roomX = 1;
                        roomY = 0;
                    }
                    if (this->data->door_id == 2) {
                        roomX = 2;
                        roomY = 0;
                    }
                }
            }
            Game::loadRoom(roomX, roomY, [target]() {
                onEnter(target);
            });
        }
    }
}

#include "Door.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"
#include "../Input.hpp"
#include "Entity.hpp"

static const anim_t DOOR_ANIM[] {0};

static const anim_t DOOR_LOCKED_ANIM[] {1, 1};

Door::Door(const Data::Door *data)
    : GameObject(&Data::DOOR_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {4, 0},
        {12, 16},
    };
    this->locked = this->data->num_artifacts > 0;
    if (this->locked) {
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

uint16_t Door::getDrawColor() const {
    if (this->locked) {
        return this->currentFrame ? 0x0324 : 0x0231;
    }
    return 0x1204;
}

static void onEnter(uint8_t door_id) {
    // Game::player.velocity.x = 0;
    for (auto &entity : Game::currentRoom->entities) {
        if (entity->getType() == IEntity::Type::DOOR) {
            auto door = static_cast<const Entity<Data::Door> *>(entity);
            if (door->data->door_id == door_id) {
                Game::player.position = Vector2<float>(door->position);
            }
        }
    }
}

void Door::update() {
    GameObject::update();
    if (this->collidesWith(Game::player)) {
        if (Input::isPressedDown(BUTTON_DOWN)) { // && isGrounded
            auto door_id = this->data->door_id;
            Game::loadRoom(this->data->room.x, this->data->room.y, [door_id]() {
                onEnter(door_id);
            });
        }
    }
}

#include "Checkpoint.hpp"
#include "Entity.hpp"
#include "GameObject.hpp"
#include "../Data/Sheets.hpp"

static const anim_t CHECKPOINT_ANIM[] {1};

static const anim_t CHECKPOINT_ACTIVE_ANIM[] {0, 1};

Checkpoint::Checkpoint(const Data::Checkpoint *data)
    : GameObject(&Data::CHECKPOINT_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    if (this->active) {
        this->animation = CHECKPOINT_ACTIVE_ANIM;
        this->animLength = sizeof(CHECKPOINT_ACTIVE_ANIM) / sizeof(anim_t);
    } else {
        this->animation = CHECKPOINT_ANIM;
        this->animLength = sizeof(CHECKPOINT_ANIM) / sizeof(anim_t);
    }
    this->animSpeed = 8;
}

IEntity::Type Checkpoint::getType() const {
    return IEntity::Type::CHECKPOINT;
}

uint16_t Checkpoint::getDrawColor() const {
    return 0x0234;
}

void Checkpoint::update() {
    GameObject::update();
}

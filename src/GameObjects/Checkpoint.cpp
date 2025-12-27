#include "Checkpoint.hpp"
#include "Entity.hpp"
#include "GameObject.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"

static const anim_t CHECKPOINT_ANIM[] {1};

static const anim_t CHECKPOINT_ACTIVE_ANIM[] {0, 1};

Checkpoint::Checkpoint(const Data::Checkpoint *data)
    : GameObject(&Data::CHECKPOINT_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {4, 5, 12, 16},
    };
    this->active = Game::player.checkpointId == data->id;
    if (this->active) {
        this->setAnimation(CHECKPOINT_ACTIVE_ANIM, sizeof(CHECKPOINT_ACTIVE_ANIM) / sizeof(anim_t));
    } else {
        this->setAnimation(CHECKPOINT_ANIM, sizeof(CHECKPOINT_ANIM) / sizeof(anim_t));
    }
}

void Checkpoint::deactivate() {
    this->active = false;
    this->setAnimation(CHECKPOINT_ANIM, sizeof(CHECKPOINT_ANIM) / sizeof(anim_t));
}

IEntity::Type Checkpoint::getType() const {
    return IEntity::Type::CHECKPOINT;
}

uint16_t Checkpoint::getDrawColor() const {
    if (this->interacted())
        return 0x0000;
    return 0x0234;
}

void Checkpoint::update() {
    if (this->interacted())
        return;
    GameObject::update();
    if (this->collidesWith(Game::player)) {
        if (!this->active) {
            this->active = true;
            this->setAnimation(CHECKPOINT_ACTIVE_ANIM, sizeof(CHECKPOINT_ACTIVE_ANIM) / sizeof(anim_t));
            Game::player.setCheckpoint(*this);
            Game::save();
        }
    }
}

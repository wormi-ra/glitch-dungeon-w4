#include "Enemy.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"

static const anim_t FLOOR_ENEMY_ANIM[] {4, 5, 0, 6, 7, -4};

static const anim_t AIR_ENEMY_ANIM[] {0,1, 0, 2,3, static_cast<anim_t>(0xFF)};

Enemy::Enemy(const Data::Enemy *data)
    : GameObject(&Data::ENEMY_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2, 14, 16},
    };
    if (this->data->enemy_id == 1) {
        this->animation = FLOOR_ENEMY_ANIM;
        this->animLength = sizeof(FLOOR_ENEMY_ANIM) / sizeof(anim_t);
    } else {
        this->animation = AIR_ENEMY_ANIM;
        this->animLength = sizeof(AIR_ENEMY_ANIM) / sizeof(anim_t);
    }
    this->animSpeed = 8;
}

IEntity::Type Enemy::getType() const {
    return IEntity::Type::ENEMY;
}

uint16_t Enemy::getDrawColor() const {
    if (this->currentFrame == 2) {
        return this->data->enemy_id ? 0x4444 : 0x0000;
    }
    return 0x0234;
}

void Enemy::update() {
    GameObject::update();
    if (this->collidesWith(Game::player)) {
        Game::player.die();
    }
}

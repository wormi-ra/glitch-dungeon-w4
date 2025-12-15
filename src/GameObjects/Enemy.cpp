#include "Enemy.hpp"
#include "../Data/Sheets.hpp"

Enemy::Enemy(const Data::Enemy *data)
    : GameObject(&Data::COLLECTION_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    this->animation = {5};
    this->animSpeed = 1;
}

uint16_t Enemy::getDrawColor() const {
    return 0x1234;
}

void Enemy::update() {
    GameObject::update();
}

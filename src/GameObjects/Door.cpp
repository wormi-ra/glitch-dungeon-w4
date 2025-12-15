#include "Door.hpp"
#include "../Data/Sheets.hpp"

Door::Door(const Data::Door *data)
    : GameObject(&Data::COLLECTION_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    this->animation = {4};
    this->animSpeed = 1;
}

uint16_t Door::getDrawColor() const {
    return 0x1234;
}

void Door::update() {
    GameObject::update();
}

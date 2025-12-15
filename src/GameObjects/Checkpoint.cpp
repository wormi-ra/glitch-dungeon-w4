#include "Checkpoint.hpp"
#include "GameObject.hpp"
#include "../Data/Sheets.hpp"

Checkpoint::Checkpoint(const Data::Checkpoint *data)
    : GameObject(&Data::COLLECTION_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    this->animation = {2,3};
    this->animSpeed = 4;
}

uint16_t Checkpoint::getDrawColor() const {
    return 0x1234;
}

void Checkpoint::update() {
    GameObject::update();
}

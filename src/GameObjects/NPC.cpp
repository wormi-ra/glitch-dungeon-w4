#include "NPC.hpp"
#include "../Data/Sheets.hpp"

NPC::NPC(const Data::NPC *data)
    : GameObject(&Data::COLLECTION_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    this->animation = {6};
    this->animSpeed = 1;
}

uint16_t NPC::getDrawColor() const {
    return 0x1234;
}

void NPC::update() {
    GameObject::update();
}

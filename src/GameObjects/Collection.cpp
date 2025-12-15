#include "Collection.hpp"
#include "../Data/Sheets.hpp"

Collection::Collection(const Data::Collection *data)
    : GameObject(&Data::COLLECTION_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    this->animation = {data->collection_id};
}

uint16_t Collection::getDrawColor() const {
    return 0x1234;
}

void Collection::update() {
    GameObject::update();
}

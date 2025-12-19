#include "Collection.hpp"
#include "../Data/Sheets.hpp"

static const anim_t COLLECTION_ANIMS[17][2] {
    {0, 1},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {3, 3},
    {4 ,-4},
    {5 ,-5},
    {8 ,9},
    {6, -6},
    {10, 11},
    {12, 13},
    {14, 15},
    {7, -7},
};

Collection::Collection(const Data::Collection *data)
    : GameObject(&Data::COLLECTION_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    this->animation = COLLECTION_ANIMS[this->data->collection_id];
    this->animLength = 2;
    this->animSpeed = 8;
}

IEntity::Type Collection::getType() const {
    return IEntity::Type::COLLECTION;
}

uint16_t Collection::getDrawColor() const {
    switch (this->data->collection_id) {
    case 0:
        return 0x1340;
    case 1:
        return 0x1430;
    case 2:
        return 0x1130;
    case 5:
        return 0x1410;
    case 6:
        return 0x4410;
    case 7:
        return this->currentFrame ? 0x1140 : 0x1130;
    case 8:
        return 0x4320;
    default:
        return 0x1230;
    }
}

void Collection::update() {
    GameObject::update();
}

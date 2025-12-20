#include "EntityData.hpp"
#include "../GameObjects/Door.hpp"
#include "../GameObjects/Checkpoint.hpp"
#include "../GameObjects/Enemy.hpp"
#include "../GameObjects/NPC.hpp"
#include "../GameObjects/Collection.hpp"
#include <cstdint>

IEntity *Data::EntityData::instantiate() const {
    switch (this->type) {
    case Type::DOOR:
        return new ::Door(static_cast<const Data::Door *>(this));
    case Type::CHECKPOINT:
        return new ::Checkpoint(static_cast<const Data::Checkpoint *>(this));
    case Type::ENEMY:
        return new ::Enemy(static_cast<const Data::Enemy *>(this));
    case Type::NPC:
        return new ::NPC(static_cast<const Data::NPC *>(this));
    case Type::COLLECTION:
        return new ::Collection(static_cast<const Data::Collection *>(this));
    }
}

uint8_t Data::EntityData::getId() const {
    return this->id;
}

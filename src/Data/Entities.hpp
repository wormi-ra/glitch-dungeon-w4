#pragma once

#include "EntityData.hpp"
#include "../Bitfield.hpp"

namespace Data {
    constexpr uint8_t ENTITY_COUNT = 208;
    extern const Data::EntityData *ENTITIES[ENTITY_COUNT];

    static Bitfield<Data::ENTITY_COUNT> interactedEntities {};
}

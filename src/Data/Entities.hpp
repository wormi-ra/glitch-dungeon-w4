#pragma once

#include "EntityData.hpp"
#include "../Bitfield.hpp"

namespace Data {
    constexpr uint8_t ENTITY_COUNT = 213;
    extern const Data::EntityData *ENTITIES[ENTITY_COUNT];

    constexpr const uint8_t EVENT_CHECKPOINT_2_4 = 105;
    constexpr const uint8_t EVENT_NPC_2_4 = 106;
    constexpr const uint8_t EVENT_NPCS_0_5[3] = {37, 38, 39};

    extern Bitfield<Data::ENTITY_COUNT> interactedEntities;
}

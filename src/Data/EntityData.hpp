#pragma once

#include <cstdint>
#include "../GameObjects/IEntity.hpp"
#include "../Vector2.hpp"

namespace Data {
    struct EntityData {
        enum Type : uint8_t {
            DOOR,
            CHECKPOINT,
            ENEMY,
            NPC,
            COLLECTION,
        };

        Vector2<int16_t> position;
        Type type;
        uint8_t id;

        IEntity *instantiate() const;
        uint8_t getId() const;
    };

    struct Door : public EntityData {
        Vector2<uint8_t> room;
        uint8_t door_id;
        uint16_t num_artifacts;
    };

    struct Checkpoint : public EntityData {
    };

    struct Enemy : public EntityData {
        uint8_t enemy_id;
    };

    struct NPC : public EntityData {
        int8_t npc_id;
    };

    struct Collection : public EntityData {
        uint8_t collection_id;
    };
}

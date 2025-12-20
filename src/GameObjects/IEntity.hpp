#pragma once

#include "GameObject.hpp"

class IEntity : public virtual GameObject {
    public:
        enum class Type : uint8_t {
            DOOR,
            CHECKPOINT,
            ENEMY,
            NPC,
            COLLECTION,
        };

        virtual ~IEntity() = default;
        virtual bool interacted() const = 0;
        virtual Type getType() const = 0;
        virtual uint8_t getId() const = 0;
};


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
        virtual Type getType() const = 0;
};

template <class T>
class Entity : public IEntity {
    public:
        Entity(const T *data): data(data) {};
        const T *data;
};

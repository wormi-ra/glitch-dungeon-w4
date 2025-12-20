#pragma once 

#include "IEntity.hpp"
#include "../Data/Entities.hpp"

template <class T>
class Entity : public IEntity {
    public:
        Entity(const T *data): data(data) {};
        const T *data;

        virtual uint8_t getId() const override {
            return this->data->getId();
        }

        virtual bool interacted() const override {
            return Data::interactedEntities[this->getId()];
        };
};

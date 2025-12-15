#pragma once

#include "GameObject.hpp"

template <class T>
class Entity : public virtual GameObject {
    public:
        Entity(const T *data): data(data) {};
        const T *data;
};

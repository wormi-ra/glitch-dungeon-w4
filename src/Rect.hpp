#pragma once

#include <cstdint>
#include <cmath>
#include "Vector2.hpp"

template<typename T, typename U>
struct Rect {
    Vector2<T> position{};
    Vector2<U> size{};

    constexpr Rect() = default;
    constexpr Rect(Vector2<T> position, Vector2<U> size);

    constexpr bool intersects(const Rect<T, U> &other) const {
        return (static_cast<U>(abs((this->position.x + static_cast<T>(this->size.x)/2)
            - (other.position.x + static_cast<T>(other.size.x) / 2)) * 2) < (this->size.x + other.size.x))
            && (static_cast<U>(abs((this->position.y + static_cast<T>(this->size.y)/2)
            - (other.position.y + static_cast<T>(other.size.y) / 2)) * 2) < (this->size.y + other.size.y));
    }

    constexpr bool contains(Vector2<T> point) const {
        return (position.x <= point.x
            && point.x <= position.x + static_cast<T>(size.x)
            && position.y <= point.y
            && point.y <= position.y + static_cast<T>(size.y));
    }
};

template <typename T, typename U>
constexpr Rect<T, U>::Rect(Vector2<T> position, Vector2<U> size) : position(position), size(size)
{
}

typedef struct Rect<float, float> FloatRect;
typedef struct Rect<int32_t, uint32_t> IntRect;
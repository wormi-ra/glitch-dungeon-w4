#pragma once

#include <cstdint>
#include "Vector2.hpp"

template<typename T, typename U>
struct Rect {
    Vector2<T> position{};
    Vector2<U> size{};

    constexpr Rect() = default;
    constexpr Rect(Vector2<T> position, Vector2<U> size);
};

template <typename T, typename U>
constexpr Rect<T, U>::Rect(Vector2<T> position, Vector2<U> size) : position(position), size(size)
{
}

typedef struct Rect<float, float> FloatRect;
typedef struct Rect<int32_t, uint32_t> IntRect;
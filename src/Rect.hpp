#pragma once

#include <cstdint>
#include <cmath>
#include "Vector2.hpp"

template <typename T, typename U>
struct Rect;

using FloatRect = struct Rect<float, float>;
using IntRect = Rect<int32_t, uint32_t>;

template<typename T, typename U>
struct Rect {
    Vector2<T> position{};
    Vector2<U> size{};

    struct BBox {
        T lb;
        T tb;
        T rb;
        T bb;
    };

    constexpr BBox bbox() const {
        return BBox {
            position.x,
            position.y,
            position.x + static_cast<T>(size.x),
            position.y + static_cast<T>(size.y),
        };
    };

    constexpr Rect() = default;
    constexpr Rect(const BBox &);
    constexpr Rect(const Vector2<T> &position, const Vector2<U> &size);
    constexpr explicit operator FloatRect() const;
    constexpr explicit operator IntRect() const;

    constexpr bool intersects(const Rect<T, U> &other) const {
        return (static_cast<U>(std::abs((this->position.x + static_cast<T>(this->size.x)/2)
            - (other.position.x + static_cast<T>(other.size.x) / 2)) * 2) <= (this->size.x + other.size.x))
            && (static_cast<U>(std::abs((this->position.y + static_cast<T>(this->size.y)/2)
            - (other.position.y + static_cast<T>(other.size.y) / 2)) * 2) <= (this->size.y + other.size.y));
    }

    constexpr bool contains(const Vector2<T> &point) const {
        return (position.x <= point.x
            && point.x <= position.x + static_cast<T>(size.x)
            && position.y <= point.y
            && point.y <= position.y + static_cast<T>(size.y));
    }
};

template <typename T, typename U>
constexpr Rect<T, U>::Rect(const Vector2<T> &position, const Vector2<U> &size)
    : position(position), size(size)
{
}

template <typename T, typename U>
constexpr Rect<T, U>::Rect(const BBox &bbox)
    : position(bbox.lb, bbox.tb), size(static_cast<U>(bbox.rb - bbox.lb), static_cast<U>(bbox.bb - bbox.tb))
{
}

template <>
constexpr IntRect::operator FloatRect() const {
    return FloatRect {
        Vector2<float>(this->position),
        Vector2<float>(this->size),
    };
}

template <>
constexpr FloatRect::operator IntRect() const {
    return IntRect {
        Vector2<int32_t>(this->position),
        Vector2<uint32_t>(this->size),
    };
}

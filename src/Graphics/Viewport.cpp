#include "Viewport.hpp"
#include <algorithm>
#include <cstdint>

IntRect Viewport::transform(const IntRect &rect) const {
    Vector2<int32_t> pos = {
        std::clamp(rect.position.x + this->position.x + this->offset.x, this->position.x, this->position.x + static_cast<int32_t>(this->size.x)),
        std::clamp(rect.position.y + this->position.y + this->offset.y, this->position.y, this->position.y + static_cast<int32_t>(this->size.y)),
    };
    Vector2<uint32_t> size = {
        std::min(rect.size.x, this->size.x - static_cast<uint32_t>(rect.position.x + this->offset.x)),
        std::min(rect.size.y, this->size.y - static_cast<uint32_t>(rect.position.y + this->offset.y)),
    };
    if (((rect.position.x + this->offset.x) < -static_cast<int32_t>(rect.size.x)) || (rect.position.x + this->offset.x) > static_cast<int32_t>(this->size.x))
        size.x = 0;
    if (((rect.position.y + this->offset.y) < -static_cast<int32_t>(rect.size.y)) || (rect.position.y + this->offset.y) > static_cast<int32_t>(this->size.y))
        size.y = 0;
    return {
        pos,
        {
            std::min(size.x, rect.size.x + static_cast<uint32_t>(rect.position.x + this->offset.x)),
            std::min(size.y, rect.size.y + static_cast<uint32_t>(rect.position.y + this->offset.y)),
        }
    };
}

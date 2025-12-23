#include "GameObject.hpp"
#include "../utils.hpp"
#include <cmath>
#include <cstdlib>

bool GameObject::collidesWith(const GameObject &other) const {
    IntRect myRect = {
        Vector2<int32_t>{
            static_cast<int32_t>(std::roundf(this->position.x)), 
            static_cast<int32_t>(std::roundf(this->position.y))
        } + this->bbox.position,
        this->bbox.size,
    };
    IntRect otherRect = {
        Vector2<int32_t>{
            static_cast<int32_t>(std::roundf(other.position.x)), 
            static_cast<int32_t>(std::roundf(other.position.y))
        } + other.bbox.position,
        other.bbox.size,
    };
    return myRect.intersects(otherRect);
}

void GameObject::draw(const Viewport &view) const {
    uint8_t tileId = 0;
    uint32_t flags = this->flags;

    if (this->animation != nullptr) {
        if (this->animation[this->currentFrame] < 0) {
            flags = flags ^ BLIT_FLIP_X;
        }
        if (this->animation[this->currentFrame] == static_cast<anim_t>(0xFF)) {
            tileId = 0;
        } else {
            tileId = static_cast<uint8_t>(abs(this->animation[this->currentFrame]));
        }
    }
    *DRAW_COLORS = this->getDrawColor();
    this->sheet->blitSub(view, tileId, static_cast<Vector2<int32_t>>(this->position), flags);
}

void GameObject::update() {
    if (this->animation == nullptr) {
        return;
    }
    if (this->m_animTimer >= this->animSpeed) {
        this->m_animTimer = 0;
        this->currentFrame = mod(this->currentFrame + 1, this->animLength);
    }
    this->m_animTimer++;
}

void GameObject::setFacing(Facing facing) {
    if (facing == Facing::LEFT) {
        this->flags |= BLIT_FLIP_X;
    } else {
        this->flags &= ~BLIT_FLIP_X;
    }
}

void GameObject::setAnimation(const anim_t *anim, uint8_t len, uint8_t speed) {
    if (anim != this->animation) {
        this->animation = anim;
        this->animLength = len;
        this->m_animTimer = 0;
        this->currentFrame = 0;
    }
    this->animSpeed = speed;
}

bool GameObject::isReverse() const {
    return this->flags & BLIT_FLIP_Y;
}

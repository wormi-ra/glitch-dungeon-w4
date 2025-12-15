#include "GameObject.hpp"
#include "../utils.hpp"

void GameObject::draw(const Viewport &view) const {
    uint8_t tileId = 0;
    if (!this->animation.empty()) {
        tileId = this->animation[this->currentFrame];
    }
    *DRAW_COLORS = this->getDrawColor();
    this->m_sheet->blitSub(view, tileId, static_cast<Vector2<int32_t>>(this->position));
}

void GameObject::update() {
    if (this->animation.empty()) {
        return;
    }
    if (this->m_animTimer >= this->animSpeed) {
        this->m_animTimer = 0;
        this->currentFrame = mod(this->currentFrame + 1, this->animation.size());
    }
    this->m_animTimer++;
}

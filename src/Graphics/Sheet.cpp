#include "Sheet.hpp"
#include "Viewport.hpp"

void Sheet::blitSub(const Viewport &view, uint32_t tileId, Vector2<int32_t> position, uint32_t flags) const
{
    uint32_t tx = (tileId % (this->width / this->tileWidth) * this->tileWidth);
    uint32_t ty = (tileId / (this->width / this->tileWidth) * this->tileHeight);
    uint32_t stride = this->width;
    IntRect rect = view.transform(IntRect{
        position,
        {this->tileWidth, this->tileHeight}
    });
    if (rect.size.x == 0 || rect.size.y == 0)
        return;
    auto srcX = position.x + view.offset.x + int32_t(this->tileWidth) > int32_t(view.size.x) ? tx : tx + this->tileWidth - rect.size.x;
    auto srcY = position.y + view.offset.y + int32_t(this->tileHeight) > int32_t(view.size.y) ? ty : ty + this->tileHeight - rect.size.y;
    if (flags & BLIT_FLIP_X)
        srcX += this->tileWidth - rect.size.x;
    if (flags & BLIT_FLIP_Y)
        srcY += this->tileHeight - rect.size.y;
    w4::blitSub(
        this->data,
        rect.position.x,
        rect.position.y,
        rect.size.x,
        rect.size.y,
        srcX,
        srcY,
        stride,
        flags | this->flags
    );
}

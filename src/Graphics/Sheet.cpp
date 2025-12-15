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
    w4::blitSub(
        this->data,
        rect.position.x,
        rect.position.y,
        rect.size.x,
        rect.size.y,
        position.x + static_cast<int32_t>(this->tileWidth) > static_cast<int32_t>(view.size.x) ? tx : tx + this->tileWidth - rect.size.x,
        position.y + static_cast<int32_t>(this->tileHeight) > static_cast<int32_t>(view.size.y) ? tx : ty + this->tileHeight - rect.size.y,
        stride,
        flags | this->flags
    );
}

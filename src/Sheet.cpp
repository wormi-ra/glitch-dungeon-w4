#include "Sheet.hpp"
#include "wasm4.h"

void Sheet::blitSub(uint32_t tileId, int32_t x, int32_t y, uint32_t flags) const
{
    uint32_t tx = tileId % (this->width / this->tileWidth) * this->tileWidth;
    uint32_t ty = tileId / (this->width / this->tileWidth) * this->tileHeight;
    uint32_t stride = this->width;
    w4::blitSub(this->data, x, y, this->tileWidth, this->tileHeight, tx, ty, stride, flags | this->flags);
}

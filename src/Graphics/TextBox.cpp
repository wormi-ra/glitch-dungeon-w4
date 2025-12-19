#include "TextBox.hpp"

void TextBox::setText(const char *text, uint32_t duration) {
    this->text = text;
    this->timer = duration;
}

void TextBox::update() {
    if (this->timer == 0) {
        this->text = nullptr;
    } else {
        this->timer--;
    }
}

void TextBox::draw(const Viewport &view) const {
    if (this->text == nullptr)
        return;
    IntRect rect = view.transform({this->position, this->size}); 
    *DRAW_COLORS = this->rectColor;
    w4::rect(rect.position.x, rect.position.y, rect.size.x, rect.size.y);
    IntRect textRect = view.transform({this->position + this->padding, this->size}); 
    *DRAW_COLORS = this->textColor;
    w4::text(this->text, textRect.position.x, textRect.position.y);
}

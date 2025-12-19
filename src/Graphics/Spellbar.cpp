#include "Spellbar.hpp"
#include "../Input.hpp"
#include "../Game.hpp"
#include "../Data/Sheets.hpp"

void Spellbar::draw(const Viewport &view) const {
    const auto &currentSpell = Game::player.glitch;
    const char *text = currentSpell->getName();
    Vector2<int32_t> position = this->position;

    for (const auto &spell : Game::player.spellbook) {
        if (spell->getType() == Glitch::Type::GREY) {
            continue;
        }
        IntRect rect = view.transform({this->position + position + Vector2{1, 1}, {13, 13}});
        if (spell == currentSpell) {
            *DRAW_COLORS = 0x34;
        } else {
            if (rect.contains(static_cast<Vector2<int32_t>>(Input::getMouse()))) {
                *DRAW_COLORS = 0x31;
                if (Input::isClickedDown(rect, MOUSE_LEFT)) {
                    Game::player.setSpell(spell->getType());
                }
            } else {
                *DRAW_COLORS = this->rectColor;
            }
        }
        w4::rect(rect.position.x, rect.position.y, rect.size.x, rect.size.y);
        *DRAW_COLORS = 0x1230;
        Data::SPELL_ICONS.blitSub(view, static_cast<uint8_t>(spell->getType()) - 1, this->position + position + Vector2{2, 2});
        position.x += 16;
    }
    IntRect textRect = view.transform({this->position + Vector2{2, 20}, this->size}); 
    if (text != nullptr) {
        *DRAW_COLORS = this->textColor;
        w4::text(text, textRect.position.x, textRect.position.y);
    }
}

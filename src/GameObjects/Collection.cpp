#include "Collection.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"
#include "GameObject.hpp"
#include "Player.hpp"

static const anim_t COLLECTION_ANIMS[17][2] {
    {0, 1},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {2 ,2},
    {3, 3},
    {4 ,-4},
    {5 ,-5},
    {8 ,9},
    {6, -6},
    {10, 11},
    {12, 13},
    {14, 15},
    {7, -7},
};

Collection::Collection(const Data::Collection *data)
    : GameObject(&Data::COLLECTION_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    this->animation = COLLECTION_ANIMS[this->data->collection_id];
    this->animLength = 2;
    this->animSpeed = 8;
}

IEntity::Type Collection::getType() const {
    return IEntity::Type::COLLECTION;
}

uint16_t Collection::getDrawColor() const {
    switch (this->data->collection_id) {
    case Collection::Item::GRIMOIRE:
        return 0x1340;
    case Collection::Item::GREEN_SPELL:
        return 0x1430;
    case Collection::Item::RED_SPELL:
        return 0x1130;
    case Collection::Item::BLUE_SPELL:
    case Collection::Item::GOLD_SPELL:
        return 0x1230;
    case Collection::Item::ZERO_SPELL:
        return 0x1410;
    case Collection::Item::NEGATIVE_SPELL:
        return 0x4410;
    case Collection::Item::PINK_SPELL:
        return this->currentFrame ? 0x1140 : 0x1130;
    case Collection::Item::CAT:
        return 0x4320;
    default:
        return 0x1340;
    }
}

void Collection::update() {
    if (this->interacted())
        return;
    GameObject::update();
    if (this->collidesWith(Game::player)) {
        onCollect();
    }
}

void Collection::draw(const Viewport &view) const {
    if (!this->interacted())
        return GameObject::draw(view);
}

void Collection::onCollect() {
    static char getText[32] = "";
    strcpy(getText, "item get:\n");
    strcat(getText, this->getName());
    Game::textBox.setText(getText);
    Data::interactedEntities[this->getId()] = true;
    Game::player.artifacts++;
    switch (this->data->collection_id) {
    case Collection::Item::GRIMOIRE:
        Game::player.state |= Player::HAS_GRIMOIRE;
        break;
    case Collection::Item::GREEN_SPELL:
        Game::player.giveSpell(Glitch::Type::GREEN);
        break;
    case Collection::Item::RED_SPELL:
        Game::player.giveSpell(Glitch::Type::RED);
        break;
    case Collection::Item::BLUE_SPELL:
        Game::player.giveSpell(Glitch::Type::BLUE);
        break;
    case Collection::Item::GOLD_SPELL:
        Game::player.giveSpell(Glitch::Type::GOLD);
        break;
    case Collection::Item::ZERO_SPELL:
        Game::player.giveSpell(Glitch::Type::ZERO);
        break;
    case Collection::Item::PINK_SPELL:
        Game::player.giveSpell(Glitch::Type::PINK);
        break;
    case Collection::Item::NEGATIVE_SPELL:
        Game::player.giveSpell(Glitch::Type::NEGATIVE);
        break;
    default:
        break;
    }
}

const char *Collection::getName() const {
    switch (this->data->collection_id) {
    case Collection::Item::GRIMOIRE:
        return "grimoire";
    case Collection::Item::GREEN_SPELL:
        return "feather spell";
    case Collection::Item::RED_SPELL:
        return "floor spell";
    case Collection::Item::BLUE_SPELL:
        return "gravity spell";
    case Collection::Item::GOLD_SPELL:
        return "wall spell";
    case Collection::Item::ZERO_SPELL:
        return "invis spell";
    case Collection::Item::PINK_SPELL:
        return "memory spell";
    case Collection::Item::NEGATIVE_SPELL:
    default:
        return "undefined";
    }
}
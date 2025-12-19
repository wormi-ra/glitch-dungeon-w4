#include "NPC.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"

static const anim_t NPC_ANIM[] {0,1};

NPC::NPC(const Data::NPC *data)
    : GameObject(&Data::NPC_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2},
        {14, 16},
    };
    this->animation = NPC_ANIM;
    this->animLength = sizeof(NPC_ANIM) / sizeof(anim_t);
    this->animSpeed = 30;
}

IEntity::Type NPC::getType() const {
    return IEntity::Type::NPC;
}

uint16_t NPC::getDrawColor() const {
    return 0x1340;
}

void NPC::update() {
    GameObject::update();
    if (this->collidesWith(Game::player)) {
        Game::textBox.setText(this->getText(), 1);
    }
}

const char *NPC::getText() const {
    switch (this->data->npc_id) {
        case -1:
            return "hold up to jump\nhigher\nthere is no escape";
        case 0:
            return "you must escape\nthe dungeon\nuse arrow keys";
        case 1:
            return "press down to fall\nand to enter doors";
        case 2:
            return "when red, you can\nwalk off cliffs\nwithout falling";
        case 3:
            return "press X or space or\nclick on your spell\nbar to cast a spell";
        case 4:
            return "press down to\nplace a memory";
        case 5:
            return "are we free now?";
        case 6:
            return "dying revives you\nto last checkpoint\ni'm sorry";
        case 7:
            return "remember your wits\n\ndeath is inevitable";
        case 8:
            return "don't afraid of\nfailure\nits all there is";
        case 9:
            return "magick controls\nthe dungeon";
        case 10:
            return "GET\n/rooms/room_4_5.txt\n404 (Not found)";
        case 11:
            return "patience is virtue\nthat means\nnothing here";
        case 12:
            return "click the spell bar\ndown there to\nchange spells";
        case 13:
            return "there is no real\nescape..";
        case 14:
            return "i believe in you";
        case 15:
            return "nice of you\nto stop by. this\nis the wrong way";
        case 16:
            return "you did it :)!\ncongratulations!";
        case 17:
            return "we knew you\ncould do it!\nwell i did at least";
        case 18:
            return "hip hip hooray!\nyay!!\nyou're the best!";
        case 19:
            return "TODO: stats";
        case 20:
            return "thanks for playing\n:)!\npress R to restart";
        case 21:
            return "IT'S A SECRET\nTO EVERYBODY.";
        case 22:
            return "nothing here\nbut us chicken";
        case 99:
            return "go back to\nthe beginning";
        default:
            return nullptr;
    }
}
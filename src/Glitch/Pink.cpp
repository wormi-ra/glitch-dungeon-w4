#include "Pink.hpp"
#include "../Game.hpp"

Glitch::Type Glitch::Pink::getType() const {
    return Type::PINK;
}

const char *Glitch::Pink::getName() const {
    return "memory";
}

const uint32_t *Glitch::Pink::getPalette() const {
    static const uint32_t palette[4] = {
        0x000000,
        0x08368d,
        0xe2dd75,
        0x88f0a9,
    };
    return palette;
}

void Glitch::Pink::onPressDown() {
    static Data::Checkpoint data {
        {
            .position = {0, 0},
            .type = Data::EntityData::Type::CHECKPOINT,
            .id = 0,
        }
    };
    data.position = Vector2<int16_t>(Game::player.position);
    if (Game::player.customCheckpoint != nullptr) {
        delete Game::player.customCheckpoint;
    }
    Game::player.customCheckpoint = new Checkpoint(&data);
    Game::player.customCheckpoint->room = Game::roomPosition;
    Game::player.customCheckpoint->activate();
    for (auto &entity : Game::currentRoom->entities) {
        if (entity->getType() == IEntity::Type::CHECKPOINT) {
            static_cast<Checkpoint *>(entity)->deactivate();
            break;
        }
    }
}

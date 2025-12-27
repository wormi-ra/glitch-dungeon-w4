#include "Enemy.hpp"
#include "../Data/Sheets.hpp"
#include "../Game.hpp"
#include "GameObject.hpp"
#include <algorithm>

static const anim_t AIR_ENEMY_ANIM[] {4, 5, 0, 6, 7, -4};

static const anim_t FLOOR_ENEMY_ANIM[] {0,1, 0, 2,3, static_cast<anim_t>(0xFF)};

Enemy::Enemy(const Data::Enemy *data)
    : GameObject(&Data::ENEMY_SHEET), Entity(data) {
    this->position = Vector2<float>(data->position);
    this->bbox = {
        {2, 2, 14, 16},
    };
    this->flags |= BLIT_FLIP_X;
    if (this->data->enemy_id == 0) {
        this->animation = FLOOR_ENEMY_ANIM;
        this->animLength = sizeof(FLOOR_ENEMY_ANIM) / sizeof(anim_t);
    } else {
        this->animation = AIR_ENEMY_ANIM;
        this->animLength = sizeof(AIR_ENEMY_ANIM) / sizeof(anim_t);
    }
    this->animSpeed = 8;
}

IEntity::Type Enemy::getType() const {
    return IEntity::Type::ENEMY;
}

uint16_t Enemy::getDrawColor() const {
    if (this->currentFrame == 2) {
        return this->data->enemy_id ? 0x4444 : 0x0000;
    }
    return 0x0234;
}

void Enemy::applyCollisions() {
    auto tileCollide = [this](Vector2<uint32_t> tile, FloatRect bbox) {
        FloatRect tileRect = {
            Vector2<float>(tile * 8u),
            {8, 8},
        };
        bbox.position += this->position;
        return bbox.intersects(tileRect);
    };

    constexpr auto tileSize = 8u;
    constexpr auto q = 3;
    auto bbox = FloatRect(this->bbox).bbox();
    auto left_tile = uint32_t(std::floor(
        std::max(this->position.x + bbox.lb + this->velocity.x - 1, 0.0f) / tileSize
    ));
    auto right_tile = uint32_t(std::ceil(
        std::min((this->position.x + bbox.rb + this->velocity.x + 1) / tileSize, float(Game::currentRoom->data->width))
    ));
    auto top_tile = uint32_t(std::floor(
        std::max(this->position.y + bbox.tb + this->velocity.y - 1, 0.0f) / tileSize
    ));
    auto bottom_tile = uint32_t(std::ceil(
        std::min((this->position.y + bbox.bb + this->velocity.y + 1)  / tileSize, float(Game::currentRoom->data->height))  
    ));

    for (auto y = top_tile; y < bottom_tile; y++) {
        for (auto x = left_tile; x < right_tile; x++) {
            auto collision = Tile::getCollision(Game::currentRoom->getTile(x, y));
            if (collision != Tile::Type::SOLID && collision != Tile::Type::SUPER_SOLID)
                continue;
            //left collisions
            if (this->velocity.x < 0 && tileCollide({x, y},
                FloatRect::BBox {bbox.lb + this->velocity.x - 1, bbox.tb + q, bbox.lb, bbox.bb - q})) {
                this->position.x = float(x * tileSize + tileSize) - bbox.lb;
                this->velocity.x = 0;
                this->setFacing(Facing::RIGHT);
                return;
            }
            // right collisions
            if (this->velocity.x > 0 && tileCollide({x, y},
                FloatRect::BBox {bbox.rb, bbox.tb + q, bbox.rb + this->velocity.x + 1, bbox.bb - q})) {
                this->position.x = float(x * tileSize) - bbox.rb;
                this->velocity.x = 0;
                this->setFacing(Facing::LEFT);
                return;
            }
        }
    }
}

void Enemy::update() {
    // enemy speed is 5/6 instead of 1.5 in the original game because MoveStop() isn't applied in this version
    constexpr auto enemySpeed = 5.0f / 6.0f;

    GameObject::update();
    if (this->getFacing() == Facing::LEFT)
        this->velocity.x = -enemySpeed;
    else
        this->velocity.x = enemySpeed;
    if (this->data->enemy_id == 0) {
        applyCollisions();
	} else if (this->data->enemy_id == 1) {
        auto bbox = this->bbox.bbox();
		if (this->position.x < 0)
            this->setFacing(Facing::RIGHT);
		if (this->position.x + float(bbox.rb) > float(Game::currentRoom->data->width) * 8)
            this->setFacing(Facing::LEFT);
	}
    this->position.x += this->velocity.x;
    if (!(Game::player.glitch->getPhysics().flags & Glitch::Physics::IS_INVISIBLE) && this->collidesWith(Game::player, 3)) {
        Game::player.die();
    }
}

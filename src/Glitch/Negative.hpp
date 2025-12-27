#include "Glitch.hpp"

namespace Glitch {
    class Negative : public Glitch {
        public:
            virtual bool isFallthrough(Tile::Type collision) const override;
            virtual bool collidesWith(Tile::Type collision) const override;
            virtual Type getType() const override;
            virtual const char *getName() const override;
            virtual const uint32_t *getPalette() const override;
            virtual void transformPlayer(Player &player, Room &room) override;
    };
}

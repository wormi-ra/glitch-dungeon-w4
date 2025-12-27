#include "Glitch.hpp"

namespace Glitch {
    class Blue : public Glitch {
        public:
            Blue();

            virtual Type getType() const override;
            virtual const char *getName() const override;
            virtual const uint32_t *getPalette() const override;
            virtual void transformPlayer(Player &player, Room &room) override;
    };
}

#include "Glitch.hpp"

namespace Glitch {
    class Negative : public Glitch {
        public:
            virtual Type getType() const override;
            virtual const char *getName() const override;
            virtual const uint32_t *getPalette() const override;
    };
}

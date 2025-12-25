#include "Glitch.hpp"

namespace Glitch {
    class Zero : public Glitch {
        public:
            Zero();

            virtual Type getType() const override;
            virtual const char *getName() const override;
            virtual const uint32_t *getPalette() const override;
    };
}

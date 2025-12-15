#include "Glitch.hpp"

namespace Glitch {
    class Zero : public Glitch {
        public:
            Type getType() const override;
            const uint32_t *getPalette() const override;
    };
}

#pragma once

#include "Glitch.hpp"

namespace Glitch {
    class Green : public Glitch::Glitch {
        public:
            Green();

            Type getType() const override;
            const uint32_t *getPalette() const override;
    };
}

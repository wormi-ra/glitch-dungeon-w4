#pragma once

#include "Glitch.hpp"

namespace Glitch {
    class Green : public Glitch::Glitch {
        public:
            Green();

            virtual Type getType() const override;
            virtual const char *getName() const override;
            virtual const uint32_t *getPalette() const override;
    };
}

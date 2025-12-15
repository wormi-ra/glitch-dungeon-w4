#pragma once

#include "Glitch.hpp"

namespace Glitch {
    class Red : public Glitch::Glitch {
        public:            
            Type getType() const override;
            const uint32_t *getPalette() const override;
    };
}

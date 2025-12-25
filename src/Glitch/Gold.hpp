#include "Glitch.hpp"

namespace Glitch {
    class Gold : public Glitch {
        public:
            Gold();
            
            virtual Type getType() const override;
            virtual const char *getName() const override;
            virtual const uint32_t *getPalette() const override;
    };
}

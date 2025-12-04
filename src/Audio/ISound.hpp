#pragma once

#include <cstdint>

namespace Audio {

    class ISound {
        public:
            virtual ~ISound() {}

            virtual const char *name() const = 0;
            virtual void play(uint32_t frame, float volumeMultiplier = 1.0f) const = 0;
    };
}
#pragma once

#include <cstdint>

namespace Audio {
    struct Tone {
        union {
            struct {
                uint16_t freq1;
                uint16_t freq2;
            };
            uint32_t value;
        } frequency;

        union {
            struct {
                uint8_t sustain;
                uint8_t release;
                uint8_t decay;
                uint8_t attack;
            };
            uint32_t value;
        } duration;

        union {
            struct {
                uint8_t sustain;
                uint8_t peak;
            };
            uint32_t value;
        } volume;

        uint8_t flags;

        void play(float volumeMultiplier = 1.0f) const;
    };
}

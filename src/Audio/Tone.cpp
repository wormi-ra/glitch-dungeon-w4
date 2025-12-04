#include "Tone.hpp"
#include "../wasm4.h"
#include <cstdint>

void Audio::Tone::play(float volumeMultiplier) const {
    uint32_t volume = (
        (static_cast<uint32_t>(static_cast<float>(this->volume.peak * volumeMultiplier)) << 8)
        | static_cast<uint32_t>(this->volume.sustain * volumeMultiplier)
    );
    w4::tone(this->frequency.value, this->duration.value, volume, this->flags);
}

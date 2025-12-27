#include "Tone.hpp"
#include "../wasm4.hpp"
#include <cstdint>

void Audio::Tone::play(float volumeMultiplier) const {
    uint32_t volume = (
        (uint32_t(float(this->volume.peak * volumeMultiplier)) << 8)
        | uint32_t(this->volume.sustain * volumeMultiplier)
    );
    w4::tone(this->frequency.value, this->duration.value, volume, this->flags);
}

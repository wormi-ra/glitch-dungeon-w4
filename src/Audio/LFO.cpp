#include "../wasm4.hpp"
#include "LFO.hpp"

const char *Audio::LFO::name() const {
    return this->m_name;
}

void Audio::LFO::play(uint32_t frame, float volumeMultiplier) const {
    if (frame % this->m_offset == 0) {
        w4::tone(
            this->m_hifreq,
            this->m_offset,
            (uint32_t)(100 * volumeMultiplier),
            TONE_PULSE1
        );
    } else if (frame % this->m_offset == (this->m_offset / 2)) {
        w4::tone(
            this->m_lofreq,
            this->m_offset,
            (uint32_t)(100 * volumeMultiplier),
            TONE_PULSE1
        );
    }
}

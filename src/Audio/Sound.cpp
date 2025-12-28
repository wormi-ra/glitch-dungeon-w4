#include "Sound.hpp"

uint8_t Audio::Sound::length() const {
    return this->m_count;
}

bool Audio::Sound::isOver(uint32_t frame) const {
    return frame >= this->m_length;
}

void Audio::Sound::play(uint32_t frame, float volumeMultiplier) const {
    for (uint32_t i = 0 ; i < this->m_count ; i++) {
        if (m_offsets[i] == frame) {
            m_tones[i].play(volumeMultiplier);
        }
    }
}

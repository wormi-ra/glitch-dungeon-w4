#include "Sound.hpp"

const char *Audio::Sound::name() const {
    return this->m_name;
}

uint32_t Audio::Sound::length() const {
    return this->m_length;
}

void Audio::Sound::play(uint32_t frame, float volumeMultiplier) const {
    for (uint32_t i = 0 ; i < this->m_length ; i++) {
        if (m_offsets[i] == frame) {
            m_tones[i].play(volumeMultiplier);
        }
    }
}

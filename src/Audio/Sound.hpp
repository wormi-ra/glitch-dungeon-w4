#pragma once

#include "ISound.hpp"
#include "Tone.hpp"
#include <cstdint>

namespace Audio {
    class Sound : public ISound {
        public:
            Sound(const char *name, uint32_t length, const Audio::Tone *tones, const uint32_t *offsets)
                : m_name(name),
                m_length(length),
                m_tones(tones),
                m_offsets(offsets)
            {
            }

            uint32_t length() const;
            const char *name() const;
            virtual void play(uint32_t frame, float volumeMultiplier = 1.0f) const;

        private:
            const char *m_name;
            const uint32_t m_length;
            const Audio::Tone *m_tones;
            const uint32_t *m_offsets;
    };
}

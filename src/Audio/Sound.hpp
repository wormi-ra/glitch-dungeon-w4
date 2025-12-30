#pragma once

#include "ISound.hpp"
#include "Tone.hpp"
#include <cstdint>

namespace Audio {
    class Sound : public ISound {
        public:
            Sound(uint8_t count, const Audio::Tone *tones, const uint8_t *offsets)
                : m_tones(tones),
                m_offsets(offsets),
                m_count(count)
            {
                m_length = 0;
                for (uint8_t i = 0; i < m_count; i++) {
                    if (m_offsets[i] > m_length)
                        m_length = m_offsets[i];
                }
            }

            uint8_t length() const;
            virtual void play(uint32_t frame, float volumeMultiplier = 1.0f) const override;
            virtual bool isOver(uint32_t frame) const override;

        private:
            const Audio::Tone *m_tones;
            const uint8_t *m_offsets;
            const uint8_t m_count;
            uint8_t m_length;
    };
}

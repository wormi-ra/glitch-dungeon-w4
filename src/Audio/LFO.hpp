#pragma once

#include "ISound.hpp"

namespace Audio {
    class LFO : public ISound {
        public:
            LFO(const char *name, uint32_t lofreq, uint32_t hifreq, uint32_t offset)
                : m_name(name), m_lofreq(lofreq), m_hifreq(hifreq), m_offset(offset)
            {
            }

            virtual const char *name() const;
            virtual void play(uint32_t frame, float volumeMultiplier = 1.0f) const;

        private:
            const char *m_name;
            uint32_t m_lofreq;
            uint32_t m_hifreq;
            uint32_t m_offset;
    };
}

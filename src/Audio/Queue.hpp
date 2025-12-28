#pragma once

#include "ISound.hpp"

namespace Audio {
    void playSound(const ISound *sound, float volumeMultiplier = 1.0f);
    void update(float volumeMultiplier = 1.0f);
}
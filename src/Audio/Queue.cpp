#include "Queue.hpp"
#include "ISound.hpp"
#include "../DynamicArray.hpp"

namespace Audio {
    struct QueuedSound {
        const Audio::ISound *sound;
        uint32_t offset;
        float volume;
    };

    static DynamicArray<QueuedSound> queue {};
    static uint32_t frameCount = 0;
}

void Audio::playSound(const Audio::ISound *sound, float volumeMultiplier) {
    Audio::queue.emplace_back(QueuedSound {
        sound,
        frameCount,
        volumeMultiplier,
    });
}

void Audio::update(float volumeMultiplier) {
    for (auto it = Audio::queue.cbegin(); it != Audio::queue.cend(); it++) {
        auto &sound = *it;
        if (sound.offset <= frameCount) {
            sound.sound->play(frameCount - sound.offset, sound.volume * volumeMultiplier);
            if (sound.sound->isOver(frameCount - sound.offset)) {
                Audio::queue.erase(it--);
            }
        }
    }
    frameCount++;
}

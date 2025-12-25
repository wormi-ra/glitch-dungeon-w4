#include "Time.hpp"
#include <cmath>

Time Time::fromFrameCount(uint32_t frames) {
    uint64_t ms = (uint64_t(frames) * 1000) / 60;
    Time time{};

    time.hours = uint32_t(ms / (1000ull * 60 * 60));
    ms %= (1000ull * 60 * 60);
    time.minutes = uint8_t(ms / (1000ull * 60));
    ms %= (1000ull * 60);
    time.seconds = uint8_t(ms / 1000);
    time.milliseconds = uint16_t(ms % 1000);
    return time;
}

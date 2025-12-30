#include "../wasm4.hpp"
#include "Sounds.hpp"

const Audio::Sound Sounds::LAND {
    1,
    (Audio::Tone []){{
            {{340, 93}},
            {{1, 1, 0, 0}},
            {{100, 100}},
            TONE_MODE4 | TONE_PULSE1
        }},
    (uint8_t []){0}
};

const Audio::Sound Sounds::JUMP {
    1,
    (Audio::Tone []){{
            {{404, 538}},
            {{4, 2, 0, 0}},
            {{100, 100}},
            TONE_MODE4 | TONE_PULSE1
        }},
    (uint8_t []){0}
};

const Audio::Sound Sounds::CHECKPOINT {
    1,
    (Audio::Tone []){
        {
            {{2135, 2236}},
            {{1, 7, 0, 0}},
            {{80, 100}},
            TONE_MODE3 | TONE_PULSE1
        }
    },
    (const uint8_t []){0}
};

const Audio::Sound Sounds::HURT {
    2,
    (Audio::Tone []) {
        {
            {{178, 195}},
            {{5, 0, 0, 0}},
            {{100, 100}},
            TONE_PULSE2
        },
    {
            {{178, 174}},
            {{1, 4, 0, 0}},
            {{100, 100}},
            TONE_PULSE2
        },
    },
    (const uint8_t []) {0, 5}
};

const Audio::Sound Sounds::ERROR {
    5,
    (Audio::Tone []) {
        {
            {{855, 0}},
            {{1, 0, 0, 0}}, // 1
            {{100, 100}},
            TONE_PULSE1 | TONE_MODE3
        },
        {
            {{1013, 0}},
            {{1, 0, 0, 0}}, // 1
            {{50, 50}},
            TONE_PULSE1 | TONE_MODE3
        },
        {
            {{855, 0}},
            {{1, 0, 0, 0}}, // 1
            {{100, 100}},
            TONE_PULSE1 | TONE_MODE3
        },
        {
            {{1698, 2036}},
            {{1, 0, 0, 1}}, // 2
            {{50, 100}},
            TONE_PULSE1 | TONE_MODE3
        },
        {
            {{1013, 0}},
            {{0, 4, 0, 1}}, // 5
            {{100, 100}},
            TONE_TRIANGLE
        },
    },
    (const uint8_t []) {0, 1, 2, 3, 5}
};

const Audio::Sound Sounds::OPEN {
    4,
    (Audio::Tone []) {
        {
            {{226, 0}},
            {{1, 0, 0, 0}},
            {{80, 80}},
            TONE_NOISE
        },
        {
            {{136, 0}},
            {{3, 0, 0, 0}},
            {{100, 100}},
            TONE_NOISE
        },
        // 3f silent
        {
            {{284, 0}},
            {{3, 0, 0, 0}},
            {{80, 80}},
            TONE_NOISE
        },    
        {
            {{130, 0}},
            {{2, 0, 0, 0}},
            {{50, 50}},
            TONE_NOISE
        },
    },
    (const uint8_t []) {0,1,6,9}
};

const Audio::Sound Sounds::STAIRS {
    3,
    (Audio::Tone []) {
        {
            {{433, 0}},
            {{2, 4, 0, 0}},
            {{100, 100}},
            TONE_NOISE
        },
        // 6f silent
        {
            {{481, 0}},
            {{1, 4, 0, 0}},
            {{80, 80}},
            TONE_NOISE
        },
        // 6f silent
        {
            {{413, 0}},
            {{1, 2, 0, 0}},
            {{20, 20}},
            TONE_NOISE
        },
    },
    (const uint8_t []) {0, 12, 24}
};

const Audio::Sound Sounds::LOCKED {
    7,
    (Audio::Tone []) {
        {
            {{201, 422}},
            {{2, 0, 0, 0}},
            {{100, 100}},
            TONE_PULSE2 | TONE_MODE2
        },
        {
            {{201, 422}},
            {{2, 0, 0, 0}},
            {{85, 85}},
            TONE_PULSE2 | TONE_MODE2
        },
        {
            {{201, 422}},
            {{2, 0, 0, 0}},
            {{70, 70}},
            TONE_PULSE2 | TONE_MODE2
        },
        {
            {{201, 422}},
            {{2, 0, 0, 0}},
            {{55, 55}},
            TONE_PULSE2 | TONE_MODE2
        },
        {
            {{201, 422}},
            {{2, 0, 0, 0}},
            {{40, 40}},
            TONE_PULSE2 | TONE_MODE2
        },
        {
            {{201, 422}},
            {{2, 0, 0, 0}},
            {{25, 25}},
            TONE_PULSE2 | TONE_MODE2
        },
        {
            {{201, 422}},
            {{2, 0, 0, 0}},
            {{10, 10}},
            TONE_PULSE2 | TONE_MODE2
        },
        {
            {{201, 422}},
            {{2, 0, 0, 0}},
            {{5, 5}},
            TONE_PULSE2 | TONE_MODE2
        },
    },
    (const uint8_t []) {0,2, 4, 6, 8, 10, 12}
};

const Audio::Sound Sounds::PICKUP {
    2,
    (Audio::Tone []) {
        {
            {{833, 0}},
            {{1, 19, 0, 0}},
            {{75, 100}},
            TONE_PULSE2 | TONE_MODE3
        },
        {
            {{883, 0}},
            {{0, 14, 0, 0}},
            {{75, 75}},
            TONE_PULSE2 | TONE_MODE3
        },
    },
    (const uint8_t []) {0, 6}
};

const Audio::Sound Sounds::SWITCH {
    14,
    (Audio::Tone []) {
        {
            {{402, 1099}},
            {{0, 0, 0, 1}},
            {{100, 100}},
            TONE_TRIANGLE
        },
        {
            {{1099, 402}},
            {{0, 1, 0, 0}},
            {{100, 100}},
            TONE_TRIANGLE
        },
        {
            {{509, 1181}},
            {{0, 0, 0, 1}},
            {{85, 85}},
            TONE_TRIANGLE
        },
        {
            {{1181, 509}},
            {{0, 1, 0, 0}},
            {{85, 85}},
            TONE_TRIANGLE
        },
        {
            {{609, 1275}},
            {{0, 0, 0, 1}},
            {{70, 70}},
            TONE_TRIANGLE
        },
        {
            {{1275, 609}},
            {{0, 1, 0, 0}},
            {{70, 70}},
            TONE_TRIANGLE
        },
        {
            {{609, 1423}},
            {{0, 0, 0, 1}},
            {{55, 55}},
            TONE_TRIANGLE
        },
        {
            {{1423, 609}},
            {{0, 1, 0, 0}},
            {{55, 55}},
            TONE_TRIANGLE
        },
        {
            {{632, 1545}},
            {{0, 0, 0, 1}},
            {{40, 40}},
            TONE_TRIANGLE
        },
        {
            {{1545, 632}},
            {{0, 1, 0, 0}},
            {{40, 40}},
            TONE_TRIANGLE
        },
        {
            {{840, 1670}},
            {{0, 0, 0, 1}},
            {{25, 25}},
            TONE_TRIANGLE
        },
        {
            {{1670, 840}},
            {{0, 1, 0, 0}},
            {{25, 25}},
            TONE_TRIANGLE
        },
        {
            {{1318, 1725}},
            {{0, 0, 0, 1}},
            {{10, 10}},
            TONE_TRIANGLE
        },
        {
            {{1725, 1318}},
            {{0, 1, 0, 0}},
            {{10, 10}},
            TONE_TRIANGLE
        },
        // {
        //     {{2042, 2947}},
        //     {{0, 0, 0, 1}},
        //     {{1, 1}},
        //     TONE_TRIANGLE
        // },
        // {
        //     {{2947, 2042}},
        //     {{0, 1, 0, 0}},
        //     {{1, 1}},
        //     TONE_TRIANGLE
        // },
    },
    (const uint8_t []) {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
};

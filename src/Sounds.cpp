#include "wasm4.h"
#include "Audio/Sound.hpp"
#include <cstdint>
#include "Sounds.hpp"

const Audio::Sound Sounds::BLIP {
    "Blip",
    1,
    (Audio::Tone []){{
            {{800, 400}},
            {{1, 1, 0, 0}},
            {{100, 100}},
            TONE_MODE4 | TONE_PULSE1
        }},
    (uint32_t []){0}
};

const Audio::Sound Sounds::JUMP {
    "Jump",
    1,
    (Audio::Tone []){{
            {{440, 600}},
            {{6, 2, 0, 0}},
            {{100, 100}},
            TONE_MODE2 | TONE_PULSE1
        }},
    (uint32_t []){0}
};

const Audio::Sound Sounds::CHECKPOINT {
    "Checkpoint",
    2,
    (Audio::Tone []){
        {
            {{1200, 0}},
            {{2, 2, 0, 0}},
            {{100, 100}},
            TONE_TRIANGLE
        },
        {
            {{2300, 0}},
            {{4, 2, 0, 0}},
            {{100, 100}},
            TONE_TRIANGLE
        },
    },
    (uint32_t []){0, 2}
};

const Audio::Sound *Sounds::TEST = nullptr;

// const Audio::Sound *Sounds::TEST = new Audio::Sound({
//     "Checkpoint",
//     2,
//     (Audio::Tone []){
//         {
//             {{1200, 0}},
//             {{2, 2, 0, 0}},
//             {{100, 100}},
//             TONE_TRIANGLE
//         },
//         {
//             {{2300, 0}},
//             {{4, 2, 0, 0}},
//             {{100, 100}},
//             TONE_TRIANGLE
//         },
//     },
//     (uint32_t []){0, 2}
// });

const Audio::LFO Sounds::LFO {
    "LFO",
    500, 1000, 2
};

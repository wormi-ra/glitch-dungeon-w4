#include "../wasm4.hpp"
#include "Sounds.hpp"

const Audio::Sound Sounds::LAND {
    1,
    (Audio::Tone []){{
            {{200, 120}},
            {{2, 1, 0, 0}},
            {{50, 50}},
            TONE_MODE4 | TONE_PULSE2
        }},
    (uint8_t []){0}
};

const Audio::Sound Sounds::JUMP {
    1,
    (Audio::Tone []){{
            {{440, 600}},
            {{6, 2, 0, 0}},
            {{100, 100}},
            TONE_MODE2 | TONE_PULSE1
        }},
    (uint8_t []){0}
};

const Audio::Sound Sounds::CHECKPOINT {
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
    (const uint8_t []){0, 2}
};

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

// const Audio::LFO Sounds::LFO {
//     "LFO",
//     500, 1000, 2
// };

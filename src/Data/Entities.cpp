#include "Entities.hpp"

const Data::EntityData *Data::ENTITIES[213] {
    // 0
    new Data::NPC {
        {
            {48, 72},
            Data::EntityData::Type::NPC,
            0,
        },
        0,
    },
    // 1
    new Data::NPC {
        {
            {48, 72},
            Data::EntityData::Type::NPC,
            1,
        },
        0,
    },
    // 2
    new Data::Enemy {
        {
            {70, 72},
            Data::EntityData::Type::ENEMY,
            2,
        },
        0,
    },
    // 3
    new Data::Enemy {
        {
            {64, 72},
            Data::EntityData::Type::ENEMY,
            3,
        },
        0,
    },
    // 4
    new Data::Enemy {
        {
            {29, 72},
            Data::EntityData::Type::ENEMY,
            4,
        },
        0,
    },
    // 5
    new Data::Collection {
        {
            {120, 16},
            Data::EntityData::Type::COLLECTION,
            5,
        },
        0,
    },
    // 6
    new Data::Collection {
        {
            {144, 24},
            Data::EntityData::Type::COLLECTION,
            6,
        },
        2,
    },
    // 7
    new Data::Collection {
        {
            {104, 8},
            Data::EntityData::Type::COLLECTION,
            7,
        },
        1,
    },
    // 8
    new Data::Collection {
        {
            {48, 40},
            Data::EntityData::Type::COLLECTION,
            8,
        },
        4,
    },
    // 9
    new Data::Collection {
        {
            {40, 96},
            Data::EntityData::Type::COLLECTION,
            9,
        },
        5,
    },
    // 10
    new Data::Collection {
        {
            {16, 88},
            Data::EntityData::Type::COLLECTION,
            10,
        },
        6,
    },
    // 11
    new Data::Collection {
        {
            {8, 24},
            Data::EntityData::Type::COLLECTION,
            11,
        },
        13,
    },
    // 12
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            12,
        },
        {1, 0},
        0,
        0,
    },
    // 13
    new Data::Door {
        {
            {40, 48},
            Data::EntityData::Type::DOOR,
            13,
        },
        {4, 1},
        10,
        0,
    },
    // 14
    new Data::Checkpoint {
        {
            {56, 48},
            Data::EntityData::Type::CHECKPOINT,
            14,
        },
    },
    // 15
    new Data::NPC {
        {
            {80, 96},
            Data::EntityData::Type::NPC,
            15,
        },
        7,
    },
    // 16
    new Data::Door {
        {
            {16, 16},
            Data::EntityData::Type::DOOR,
            16,
        },
        {1, 2},
        1,
        0,
    },
    // 17
    new Data::Enemy {
        {
            {82, 96},
            Data::EntityData::Type::ENEMY,
            17,
        },
        0,
    },
    // 18
    new Data::Checkpoint {
        {
            {32, 16},
            Data::EntityData::Type::CHECKPOINT,
            18,
        },
    },
    // 19
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            19,
        },
        {5, 1},
        10,
        0,
    },
    // 20
    new Data::Door {
        {
            {16, 32},
            Data::EntityData::Type::DOOR,
            20,
        },
        {5, 3},
        0,
        0,
    },
    // 21
    new Data::Door {
        {
            {128, 32},
            Data::EntityData::Type::DOOR,
            21,
        },
        {3, 4},
        10,
        0,
    },
    // 22
    new Data::Checkpoint {
        {
            {40, 8},
            Data::EntityData::Type::CHECKPOINT,
            22,
        },
    },
    // 23
    new Data::NPC {
        {
            {64, 96},
            Data::EntityData::Type::NPC,
            23,
        },
        15,
    },
    // 24
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            24,
        },
        {3, 4},
        0,
        0,
    },
    // 25
    new Data::Enemy {
        {
            {69, 48},
            Data::EntityData::Type::ENEMY,
            25,
        },
        1,
    },
    // 26
    new Data::Door {
        {
            {72, 64},
            Data::EntityData::Type::DOOR,
            26,
        },
        {4, 4},
        1,
        0,
    },
    // 27
    new Data::Checkpoint {
        {
            {136, 96},
            Data::EntityData::Type::CHECKPOINT,
            27,
        },
    },
    // 28
    new Data::Collection {
        {
            {8, 96},
            Data::EntityData::Type::COLLECTION,
            28,
        },
        4,
    },
    // 29
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            29,
        },
        {3, 4},
        0,
        0,
    },
    // 30
    new Data::Enemy {
        {
            {69, 48},
            Data::EntityData::Type::ENEMY,
            30,
        },
        1,
    },
    // 31
    new Data::Door {
        {
            {72, 64},
            Data::EntityData::Type::DOOR,
            31,
        },
        {4, 4},
        1,
        0,
    },
    // 32
    new Data::Checkpoint {
        {
            {136, 96},
            Data::EntityData::Type::CHECKPOINT,
            32,
        },
    },
    // 33
    new Data::Collection {
        {
            {8, 96},
            Data::EntityData::Type::COLLECTION,
            33,
        },
        4,
    },
    // 34
    new Data::Collection {
        {
            {88, 80},
            Data::EntityData::Type::COLLECTION,
            34,
        },
        3,
    },
    // 35
    new Data::Collection {
        {
            {64, 24},
            Data::EntityData::Type::COLLECTION,
            35,
        },
        7,
    },
    // 36
    new Data::Checkpoint {
        {
            {24, 80},
            Data::EntityData::Type::CHECKPOINT,
            36,
        },
    },
    // 37
    new Data::NPC {
        {
            {32, 24},
            Data::EntityData::Type::NPC,
            37,
        },
        21,
    },
    // 38
    new Data::NPC {
        {
            {64, 24},
            Data::EntityData::Type::NPC,
            38,
        },
        4,
    },
    // 39
    new Data::NPC {
        {
            {104, 24},
            Data::EntityData::Type::NPC,
            39,
        },
        15,
    },
    // 40
    new Data::Enemy {
        {
            {103, 32},
            Data::EntityData::Type::ENEMY,
            40,
        },
        1,
    },
    // 41
    new Data::Checkpoint {
        {
            {80, 72},
            Data::EntityData::Type::CHECKPOINT,
            41,
        },
    },
    // 42
    new Data::Checkpoint {
        {
            {16, 96},
            Data::EntityData::Type::CHECKPOINT,
            42,
        },
    },
    // 43
    new Data::Collection {
        {
            {120, 96},
            Data::EntityData::Type::COLLECTION,
            43,
        },
        10,
    },
    // 44
    new Data::Enemy {
        {
            {105, 96},
            Data::EntityData::Type::ENEMY,
            44,
        },
        0,
    },
    // 45
    new Data::Door {
        {
            {128, 48},
            Data::EntityData::Type::DOOR,
            45,
        },
        {5, 5},
        0,
        1,
    },
    // 46
    new Data::Collection {
        {
            {144, 72},
            Data::EntityData::Type::COLLECTION,
            46,
        },
        8,
    },
    // 47
    new Data::Door {
        {
            {128, 56},
            Data::EntityData::Type::DOOR,
            47,
        },
        {2, 0},
        2,
        0,
    },
    // 48
    new Data::Door {
        {
            {16, 56},
            Data::EntityData::Type::DOOR,
            48,
        },
        {1, 1},
        1,
        0,
    },
    // 49
    new Data::NPC {
        {
            {112, 56},
            Data::EntityData::Type::NPC,
            49,
        },
        1,
    },
    // 50
    new Data::Door {
        {
            {72, 88},
            Data::EntityData::Type::DOOR,
            50,
        },
        {0, 1},
        0,
        2,
    },
    // 51
    new Data::Door {
        {
            {128, 56},
            Data::EntityData::Type::DOOR,
            51,
        },
        {2, 4},
        2,
        0,
    },
    // 52
    new Data::Door {
        {
            {72, 88},
            Data::EntityData::Type::DOOR,
            52,
        },
        {0, 1},
        0,
        0,
    },
    // 53
    new Data::Checkpoint {
        {
            {16, 56},
            Data::EntityData::Type::CHECKPOINT,
            53,
        },
    },
    // 54
    new Data::Collection {
        {
            {32, 32},
            Data::EntityData::Type::COLLECTION,
            54,
        },
        13,
    },
    // 55
    new Data::Collection {
        {
            {120, 24},
            Data::EntityData::Type::COLLECTION,
            55,
        },
        13,
    },
    // 56
    new Data::Collection {
        {
            {0, 48},
            Data::EntityData::Type::COLLECTION,
            56,
        },
        13,
    },
    // 57
    new Data::Collection {
        {
            {56, 16},
            Data::EntityData::Type::COLLECTION,
            57,
        },
        13,
    },
    // 58
    new Data::Collection {
        {
            {16, 16},
            Data::EntityData::Type::COLLECTION,
            58,
        },
        13,
    },
    // 59
    new Data::Collection {
        {
            {128, 32},
            Data::EntityData::Type::COLLECTION,
            59,
        },
        13,
    },
    // 60
    new Data::Collection {
        {
            {56, 80},
            Data::EntityData::Type::COLLECTION,
            60,
        },
        13,
    },
    // 61
    new Data::Collection {
        {
            {112, 104},
            Data::EntityData::Type::COLLECTION,
            61,
        },
        13,
    },
    // 62
    new Data::Collection {
        {
            {104, 56},
            Data::EntityData::Type::COLLECTION,
            62,
        },
        13,
    },
    // 63
    new Data::Enemy {
        {
            {72, 48},
            Data::EntityData::Type::ENEMY,
            63,
        },
        0,
    },
    // 64
    new Data::Collection {
        {
            {24, 96},
            Data::EntityData::Type::COLLECTION,
            64,
        },
        13,
    },
    // 65
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            65,
        },
        {1, 0},
        1,
        0,
    },
    // 66
    new Data::Door {
        {
            {128, 24},
            Data::EntityData::Type::DOOR,
            66,
        },
        {2, 1},
        0,
        0,
    },
    // 67
    new Data::NPC {
        {
            {112, 96},
            Data::EntityData::Type::NPC,
            67,
        },
        -1,
    },
    // 68
    new Data::Checkpoint {
        {
            {104, 24},
            Data::EntityData::Type::CHECKPOINT,
            68,
        },
    },
    // 69
    new Data::Enemy {
        {
            {72, 56},
            Data::EntityData::Type::ENEMY,
            69,
        },
        0,
    },
    // 70
    new Data::Enemy {
        {
            {72, 88},
            Data::EntityData::Type::ENEMY,
            70,
        },
        0,
    },
    // 71
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            71,
        },
        {0, 2},
        1,
        0,
    },
    // 72
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            72,
        },
        {4, 3},
        0,
        0,
    },
    // 73
    new Data::Enemy {
        {
            {64, 48},
            Data::EntityData::Type::ENEMY,
            73,
        },
        0,
    },
    // 74
    new Data::Enemy {
        {
            {39, 72},
            Data::EntityData::Type::ENEMY,
            74,
        },
        0,
    },
    // 75
    new Data::Enemy {
        {
            {64, 96},
            Data::EntityData::Type::ENEMY,
            75,
        },
        0,
    },
    // 76
    new Data::Enemy {
        {
            {28, 96},
            Data::EntityData::Type::ENEMY,
            76,
        },
        0,
    },
    // 77
    new Data::Enemy {
        {
            {68, 96},
            Data::EntityData::Type::ENEMY,
            77,
        },
        0,
    },
    // 78
    new Data::Enemy {
        {
            {77, 96},
            Data::EntityData::Type::ENEMY,
            78,
        },
        0,
    },
    // 79
    new Data::Enemy {
        {
            {56, 96},
            Data::EntityData::Type::ENEMY,
            79,
        },
        0,
    },
    // 80
    new Data::Enemy {
        {
            {31, 96},
            Data::EntityData::Type::ENEMY,
            80,
        },
        0,
    },
    // 81
    new Data::Door {
        {
            {136, 16},
            Data::EntityData::Type::DOOR,
            81,
        },
        {1, 0},
        2,
        0,
    },
    // 82
    new Data::Door {
        {
            {136, 96},
            Data::EntityData::Type::DOOR,
            82,
        },
        {3, 0},
        1,
        0,
    },
    // 83
    new Data::NPC {
        {
            {104, 16},
            Data::EntityData::Type::NPC,
            83,
        },
        2,
    },
    // 84
    new Data::Checkpoint {
        {
            {40, 16},
            Data::EntityData::Type::CHECKPOINT,
            84,
        },
    },
    // 85
    new Data::Door {
        {
            {8, 8},
            Data::EntityData::Type::DOOR,
            85,
        },
        {1, 1},
        0,
        0,
    },
    // 86
    new Data::NPC {
        {
            {16, 96},
            Data::EntityData::Type::NPC,
            86,
        },
        6,
    },
    // 87
    new Data::Collection {
        {
            {56, 96},
            Data::EntityData::Type::COLLECTION,
            87,
        },
        1,
    },
    // 88
    new Data::Enemy {
        {
            {73, 0},
            Data::EntityData::Type::ENEMY,
            88,
        },
        0,
    },
    // 89
    new Data::Enemy {
        {
            {101, 48},
            Data::EntityData::Type::ENEMY,
            89,
        },
        1,
    },
    // 90
    new Data::Checkpoint {
        {
            {136, 72},
            Data::EntityData::Type::CHECKPOINT,
            90,
        },
    },
    // 91
    new Data::Collection {
        {
            {40, 80},
            Data::EntityData::Type::COLLECTION,
            91,
        },
        9,
    },
    // 92
    new Data::Enemy {
        {
            {73, 0},
            Data::EntityData::Type::ENEMY,
            92,
        },
        0,
    },
    // 93
    new Data::Enemy {
        {
            {35, 48},
            Data::EntityData::Type::ENEMY,
            93,
        },
        1,
    },
    // 94
    new Data::Checkpoint {
        {
            {136, 72},
            Data::EntityData::Type::CHECKPOINT,
            94,
        },
    },
    // 95
    new Data::Collection {
        {
            {40, 80},
            Data::EntityData::Type::COLLECTION,
            95,
        },
        9,
    },
    // 96
    new Data::Checkpoint {
        {
            {40, 96},
            Data::EntityData::Type::CHECKPOINT,
            96,
        },
    },
    // 97
    new Data::Enemy {
        {
            {132, 48},
            Data::EntityData::Type::ENEMY,
            97,
        },
        0,
    },
    // 98
    new Data::NPC {
        {
            {112, 96},
            Data::EntityData::Type::NPC,
            98,
        },
        5,
    },
    // 99
    new Data::Enemy {
        {
            {8, 96},
            Data::EntityData::Type::ENEMY,
            99,
        },
        0,
    },
    // 100
    new Data::Enemy {
        {
            {129, 96},
            Data::EntityData::Type::ENEMY,
            100,
        },
        0,
    },
    // 101
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            101,
        },
        {3, 3},
        0,
        0,
    },
    // 102
    new Data::Door {
        {
            {72, 16},
            Data::EntityData::Type::DOOR,
            102,
        },
        {5, 0},
        9,
        5,
    },
    // 103
    new Data::Door {
        {
            {120, 8},
            Data::EntityData::Type::DOOR,
            103,
        },
        {3, 5},
        10,
        0,
    },
    // 104
    new Data::Collection {
        {
            {72, 56},
            Data::EntityData::Type::COLLECTION,
            104,
        },
        0,
    },
    // 105
    new Data::Checkpoint {
        {
            {72, 56},
            Data::EntityData::Type::CHECKPOINT,
            105,
        },
    },
    // 106
    new Data::NPC {
        {
            {8, 56},
            Data::EntityData::Type::NPC,
            106,
        },
        3,
    },
    // 107
    new Data::Door {
        {
            {8, 40},
            Data::EntityData::Type::DOOR,
            107,
        },
        {2, 0},
        1,
        0,
    },
    // 108
    new Data::Collection {
        {
            {136, 32},
            Data::EntityData::Type::COLLECTION,
            108,
        },
        2,
    },
    // 109
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            109,
        },
        6,
    },
    // 110
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            110,
        },
        {4, 0},
        0,
        0,
    },
    // 111
    new Data::Door {
        {
            {136, 96},
            Data::EntityData::Type::DOOR,
            111,
        },
        {3, 3},
        1,
        0,
    },
    // 112
    new Data::Enemy {
        {
            {106, 96},
            Data::EntityData::Type::ENEMY,
            112,
        },
        0,
    },
    // 113
    new Data::Enemy {
        {
            {74, 96},
            Data::EntityData::Type::ENEMY,
            113,
        },
        0,
    },
    // 114
    new Data::Enemy {
        {
            {42, 96},
            Data::EntityData::Type::ENEMY,
            114,
        },
        0,
    },
    // 115
    new Data::Enemy {
        {
            {66, 48},
            Data::EntityData::Type::ENEMY,
            115,
        },
        1,
    },
    // 116
    new Data::Checkpoint {
        {
            {120, 32},
            Data::EntityData::Type::CHECKPOINT,
            116,
        },
    },
    // 117
    new Data::NPC {
        {
            {56, 32},
            Data::EntityData::Type::NPC,
            117,
        },
        10,
    },
    // 118
    new Data::Door {
        {
            {128, 48},
            Data::EntityData::Type::DOOR,
            118,
        },
        {4, 2},
        0,
        0,
    },
    // 119
    new Data::Collection {
        {
            {56, 8},
            Data::EntityData::Type::COLLECTION,
            119,
        },
        2,
    },
    // 120
    new Data::Collection {
        {
            {120, 24},
            Data::EntityData::Type::COLLECTION,
            120,
        },
        0,
    },
    // 121
    new Data::Collection {
        {
            {24, 16},
            Data::EntityData::Type::COLLECTION,
            121,
        },
        13,
    },
    // 122
    new Data::Collection {
        {
            {80, 72},
            Data::EntityData::Type::COLLECTION,
            122,
        },
        7,
    },
    // 123
    new Data::Collection {
        {
            {56, 96},
            Data::EntityData::Type::COLLECTION,
            123,
        },
        6,
    },
    // 124
    new Data::Door {
        {
            {16, 72},
            Data::EntityData::Type::DOOR,
            124,
        },
        {3, 5},
        10,
        9999,
    },
    // 125
    new Data::Checkpoint {
        {
            {40, 48},
            Data::EntityData::Type::CHECKPOINT,
            125,
        },
    },
    // 126
    new Data::Checkpoint {
        {
            {64, 40},
            Data::EntityData::Type::CHECKPOINT,
            126,
        },
    },
    // 127
    new Data::Checkpoint {
        {
            {88, 48},
            Data::EntityData::Type::CHECKPOINT,
            127,
        },
    },
    // 128
    new Data::Checkpoint {
        {
            {112, 16},
            Data::EntityData::Type::CHECKPOINT,
            128,
        },
    },
    // 129
    new Data::Enemy {
        {
            {39, 88},
            Data::EntityData::Type::ENEMY,
            129,
        },
        0,
    },
    // 130
    new Data::Enemy {
        {
            {7, 8},
            Data::EntityData::Type::ENEMY,
            130,
        },
        0,
    },
    // 131
    new Data::Checkpoint {
        {
            {16, 40},
            Data::EntityData::Type::CHECKPOINT,
            131,
        },
    },
    // 132
    new Data::Collection {
        {
            {128, 0},
            Data::EntityData::Type::COLLECTION,
            132,
        },
        14,
    },
    // 133
    new Data::Collection {
        {
            {112, 88},
            Data::EntityData::Type::COLLECTION,
            133,
        },
        3,
    },
    // 134
    new Data::Collection {
        {
            {8, 88},
            Data::EntityData::Type::COLLECTION,
            134,
        },
        4,
    },
    // 135
    new Data::Collection {
        {
            {136, 96},
            Data::EntityData::Type::COLLECTION,
            135,
        },
        5,
    },
    // 136
    new Data::Enemy {
        {
            {125, 24},
            Data::EntityData::Type::ENEMY,
            136,
        },
        1,
    },
    // 137
    new Data::Enemy {
        {
            {112, 72},
            Data::EntityData::Type::ENEMY,
            137,
        },
        0,
    },
    // 138
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            138,
        },
        {3, 1},
        1,
        0,
    },
    // 139
    new Data::Door {
        {
            {24, 40},
            Data::EntityData::Type::DOOR,
            139,
        },
        {2, 4},
        0,
        0,
    },
    // 140
    new Data::NPC {
        {
            {136, 96},
            Data::EntityData::Type::NPC,
            140,
        },
        11,
    },
    // 141
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            141,
        },
        {3, 1},
        1,
        0,
    },
    // 142
    new Data::Door {
        {
            {24, 40},
            Data::EntityData::Type::DOOR,
            142,
        },
        {2, 4},
        0,
        0,
    },
    // 143
    new Data::NPC {
        {
            {136, 96},
            Data::EntityData::Type::NPC,
            143,
        },
        11,
    },
    // 144
    new Data::Collection {
        {
            {72, 24},
            Data::EntityData::Type::COLLECTION,
            144,
        },
        12,
    },
    // 145
    new Data::Collection {
        {
            {64, 40},
            Data::EntityData::Type::COLLECTION,
            145,
        },
        6,
    },
    // 146
    new Data::Collection {
        {
            {128, 40},
            Data::EntityData::Type::COLLECTION,
            146,
        },
        15,
    },
    // 147
    new Data::Door {
        {
            {136, 8},
            Data::EntityData::Type::DOOR,
            147,
        },
        {4, 3},
        10,
        0,
    },
    // 148
    new Data::Door {
        {
            {88, 56},
            Data::EntityData::Type::DOOR,
            148,
        },
        {0, 4},
        0,
        0,
    },
    // 149
    new Data::Door {
        {
            {136, 8},
            Data::EntityData::Type::DOOR,
            149,
        },
        {4, 3},
        10,
        0,
    },
    // 150
    new Data::Door {
        {
            {88, 56},
            Data::EntityData::Type::DOOR,
            150,
        },
        {0, 4},
        0,
        7,
    },
    // 151
    new Data::Collection {
        {
            {24, 24},
            Data::EntityData::Type::COLLECTION,
            151,
        },
        0,
    },
    // 152
    new Data::Collection {
        {
            {16, 48},
            Data::EntityData::Type::COLLECTION,
            152,
        },
        0,
    },
    // 153
    new Data::Collection {
        {
            {32, 64},
            Data::EntityData::Type::COLLECTION,
            153,
        },
        9,
    },
    // 154
    new Data::Collection {
        {
            {88, 24},
            Data::EntityData::Type::COLLECTION,
            154,
        },
        10,
    },
    // 155
    new Data::Collection {
        {
            {88, 48},
            Data::EntityData::Type::COLLECTION,
            155,
        },
        11,
    },
    // 156
    new Data::Enemy {
        {
            {112, 24},
            Data::EntityData::Type::ENEMY,
            156,
        },
        0,
    },
    // 157
    new Data::Enemy {
        {
            {128, 56},
            Data::EntityData::Type::ENEMY,
            157,
        },
        0,
    },
    // 158
    new Data::Enemy {
        {
            {89, 88},
            Data::EntityData::Type::ENEMY,
            158,
        },
        0,
    },
    // 159
    new Data::Door {
        {
            {120, 80},
            Data::EntityData::Type::DOOR,
            159,
        },
        {2, 4},
        10,
        0,
    },
    // 160
    new Data::Door {
        {
            {8, 32},
            Data::EntityData::Type::DOOR,
            160,
        },
        {0, 0},
        0,
        1,
    },
    // 161
    new Data::Checkpoint {
        {
            {56, 64},
            Data::EntityData::Type::CHECKPOINT,
            161,
        },
    },
    // 162
    new Data::Checkpoint {
        {
            {24, 88},
            Data::EntityData::Type::CHECKPOINT,
            162,
        },
    },
    // 163
    new Data::NPC {
        {
            {88, 88},
            Data::EntityData::Type::NPC,
            163,
        },
        0,
    },
    // 164
    new Data::Door {
        {
            {120, 16},
            Data::EntityData::Type::DOOR,
            164,
        },
        {4, 0},
        4,
        0,
    },
    // 165
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            165,
        },
        {4, 0},
        4,
        0,
    },
    // 166
    new Data::Enemy {
        {
            {18, 96},
            Data::EntityData::Type::ENEMY,
            166,
        },
        0,
    },
    // 167
    new Data::Door {
        {
            {128, 96},
            Data::EntityData::Type::DOOR,
            167,
        },
        {4, 1},
        2,
        0,
    },
    // 168
    new Data::Door {
        {
            {24, 16},
            Data::EntityData::Type::DOOR,
            168,
        },
        {3, 1},
        0,
        0,
    },
    // 169
    new Data::Checkpoint {
        {
            {80, 96},
            Data::EntityData::Type::CHECKPOINT,
            169,
        },
    },
    // 170
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            170,
        },
        9,
    },
    // 171
    new Data::Door {
        {
            {24, 16},
            Data::EntityData::Type::DOOR,
            171,
        },
        {4, 1},
        1,
        0,
    },
    // 172
    new Data::Door {
        {
            {128, 96},
            Data::EntityData::Type::DOOR,
            172,
        },
        {4, 1},
        1,
        0,
    },
    // 173
    new Data::Door {
        {
            {120, 16},
            Data::EntityData::Type::DOOR,
            173,
        },
        {4, 0},
        2,
        0,
    },
    // 174
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            174,
        },
        {0, 1},
        10,
        0,
    },
    // 175
    new Data::Enemy {
        {
            {97, 96},
            Data::EntityData::Type::ENEMY,
            175,
        },
        0,
    },
    // 176
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            176,
        },
        8,
    },
    // 177
    new Data::Door {
        {
            {8, 24},
            Data::EntityData::Type::DOOR,
            177,
        },
        {3, 2},
        0,
        0,
    },
    // 178
    new Data::Checkpoint {
        {
            {8, 40},
            Data::EntityData::Type::CHECKPOINT,
            178,
        },
    },
    // 179
    new Data::Collection {
        {
            {88, 24},
            Data::EntityData::Type::COLLECTION,
            179,
        },
        6,
    },
    // 180
    new Data::NPC {
        {
            {104, 96},
            Data::EntityData::Type::NPC,
            180,
        },
        99,
    },
    // 181
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            181,
        },
        {1, 3},
        0,
        0,
    },
    // 182
    new Data::Checkpoint {
        {
            {128, 96},
            Data::EntityData::Type::CHECKPOINT,
            182,
        },
    },
    // 183
    new Data::Collection {
        {
            {64, 56},
            Data::EntityData::Type::COLLECTION,
            183,
        },
        5,
    },
    // 184
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            184,
        },
        {0, 4},
        1,
        0,
    },
    // 185
    new Data::Checkpoint {
        {
            {32, 96},
            Data::EntityData::Type::CHECKPOINT,
            185,
        },
    },
    // 186
    new Data::Door {
        {
            {104, 16},
            Data::EntityData::Type::DOOR,
            186,
        },
        {2, 4},
        10,
        0,
    },
    // 187
    new Data::Collection {
        {
            {32, 96},
            Data::EntityData::Type::COLLECTION,
            187,
        },
        16,
    },
    // 188
    new Data::Collection {
        {
            {88, 96},
            Data::EntityData::Type::COLLECTION,
            188,
        },
        10,
    },
    // 189
    new Data::NPC {
        {
            {72, 96},
            Data::EntityData::Type::NPC,
            189,
        },
        22,
    },
    // 190
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            190,
        },
        {2, 4},
        9,
        0,
    },
    // 191
    new Data::Door {
        {
            {72, 8},
            Data::EntityData::Type::DOOR,
            191,
        },
        {5, 4},
        1,
        0,
    },
    // 192
    new Data::NPC {
        {
            {72, 56},
            Data::EntityData::Type::NPC,
            192,
        },
        14,
    },
    // 193
    new Data::Checkpoint {
        {
            {40, 96},
            Data::EntityData::Type::CHECKPOINT,
            193,
        },
    },
    // 194
    new Data::Enemy {
        {
            {127, 64},
            Data::EntityData::Type::ENEMY,
            194,
        },
        1,
    },
    // 195
    new Data::Enemy {
        {
            {128, 24},
            Data::EntityData::Type::ENEMY,
            195,
        },
        1,
    },
    // 196
    new Data::Checkpoint {
        {
            {24, 8},
            Data::EntityData::Type::CHECKPOINT,
            196,
        },
    },
    // 197
    new Data::Door {
        {
            {8, 8},
            Data::EntityData::Type::DOOR,
            197,
        },
        {0, 2},
        10,
        0,
    },
    // 198
    new Data::Enemy {
        {
            {41, 16},
            Data::EntityData::Type::ENEMY,
            198,
        },
        1,
    },
    // 199
    new Data::Door {
        {
            {128, 96},
            Data::EntityData::Type::DOOR,
            199,
        },
        {5, 4},
        0,
        0,
    },
    // 200
    new Data::NPC {
        {
            {64, 48},
            Data::EntityData::Type::NPC,
            200,
        },
        13,
    },
    // 201
    new Data::Enemy {
        {
            {83, 96},
            Data::EntityData::Type::ENEMY,
            201,
        },
        0,
    },
    // 202
    new Data::Enemy {
        {
            {30, 64},
            Data::EntityData::Type::ENEMY,
            202,
        },
        1,
    },
    // 203
    new Data::Door {
        {
            {128, 16},
            Data::EntityData::Type::DOOR,
            203,
        },
        {0, 3},
        0,
        0,
    },
    // 204
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            204,
        },
        {5, 0},
        1,
        0,
    },
    // 205
    new Data::Door {
        {
            {56, 48},
            Data::EntityData::Type::DOOR,
            205,
        },
        {5, 2},
        0,
        0,
    },
    // 206
    new Data::NPC {
        {
            {88, 96},
            Data::EntityData::Type::NPC,
            206,
        },
        12,
    },
    // 207
    new Data::Checkpoint {
        {
            {48, 96},
            Data::EntityData::Type::CHECKPOINT,
            207,
        },
    },
    // 208
    new Data::NPC {
        {
            {48, 88},
            Data::EntityData::Type::NPC,
            208,
        },
        16,
    },
    // 209
    new Data::NPC {
        {
            {88, 88},
            Data::EntityData::Type::NPC,
            209,
        },
        17,
    },
    // 210
    new Data::NPC {
        {
            {128, 88},
            Data::EntityData::Type::NPC,
            210,
        },
        18,
    },
    // 211
    new Data::NPC {
        {
            {240, 88},
            Data::EntityData::Type::NPC,
            211,
        },
        19,
    },
    // 212
    new Data::NPC {
        {
            {288, 88},
            Data::EntityData::Type::NPC,
            212,
        },
        20,
    },
};

Bitfield<Data::ENTITY_COUNT> Data::interactedEntities {};
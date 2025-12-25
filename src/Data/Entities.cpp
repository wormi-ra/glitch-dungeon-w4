#include "Entities.hpp"

const Data::EntityData *Data::ENTITIES[208] {
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
    new Data::Enemy {
        {
            {103, 32},
            Data::EntityData::Type::ENEMY,
            37,
        },
        1,
    },
    // 38
    new Data::Checkpoint {
        {
            {80, 72},
            Data::EntityData::Type::CHECKPOINT,
            38,
        },
    },
    // 39
    new Data::Checkpoint {
        {
            {16, 96},
            Data::EntityData::Type::CHECKPOINT,
            39,
        },
    },
    // 40
    new Data::Collection {
        {
            {120, 96},
            Data::EntityData::Type::COLLECTION,
            40,
        },
        10,
    },
    // 41
    new Data::Enemy {
        {
            {105, 96},
            Data::EntityData::Type::ENEMY,
            41,
        },
        0,
    },
    // 42
    new Data::Door {
        {
            {128, 48},
            Data::EntityData::Type::DOOR,
            42,
        },
        {5, 5},
        0,
        0,
    },
    // 43
    new Data::Collection {
        {
            {144, 72},
            Data::EntityData::Type::COLLECTION,
            43,
        },
        8,
    },
    // 44
    new Data::Door {
        {
            {128, 56},
            Data::EntityData::Type::DOOR,
            44,
        },
        {2, 0},
        2,
        0,
    },
    // 45
    new Data::Door {
        {
            {16, 56},
            Data::EntityData::Type::DOOR,
            45,
        },
        {1, 1},
        1,
        0,
    },
    // 46
    new Data::NPC {
        {
            {112, 56},
            Data::EntityData::Type::NPC,
            46,
        },
        1,
    },
    // 47
    new Data::Door {
        {
            {72, 88},
            Data::EntityData::Type::DOOR,
            47,
        },
        {0, 1},
        0,
        2,
    },
    // 48
    new Data::Door {
        {
            {128, 56},
            Data::EntityData::Type::DOOR,
            48,
        },
        {2, 4},
        2,
        0,
    },
    // 49
    new Data::Door {
        {
            {72, 88},
            Data::EntityData::Type::DOOR,
            49,
        },
        {0, 1},
        0,
        0,
    },
    // 50
    new Data::Checkpoint {
        {
            {16, 56},
            Data::EntityData::Type::CHECKPOINT,
            50,
        },
    },
    // 51
    new Data::Collection {
        {
            {32, 32},
            Data::EntityData::Type::COLLECTION,
            51,
        },
        13,
    },
    // 52
    new Data::Collection {
        {
            {120, 24},
            Data::EntityData::Type::COLLECTION,
            52,
        },
        13,
    },
    // 53
    new Data::Collection {
        {
            {0, 48},
            Data::EntityData::Type::COLLECTION,
            53,
        },
        13,
    },
    // 54
    new Data::Collection {
        {
            {56, 16},
            Data::EntityData::Type::COLLECTION,
            54,
        },
        13,
    },
    // 55
    new Data::Collection {
        {
            {16, 16},
            Data::EntityData::Type::COLLECTION,
            55,
        },
        13,
    },
    // 56
    new Data::Collection {
        {
            {128, 32},
            Data::EntityData::Type::COLLECTION,
            56,
        },
        13,
    },
    // 57
    new Data::Collection {
        {
            {56, 80},
            Data::EntityData::Type::COLLECTION,
            57,
        },
        13,
    },
    // 58
    new Data::Collection {
        {
            {112, 104},
            Data::EntityData::Type::COLLECTION,
            58,
        },
        13,
    },
    // 59
    new Data::Collection {
        {
            {104, 56},
            Data::EntityData::Type::COLLECTION,
            59,
        },
        13,
    },
    // 60
    new Data::Enemy {
        {
            {72, 48},
            Data::EntityData::Type::ENEMY,
            60,
        },
        0,
    },
    // 61
    new Data::Collection {
        {
            {24, 96},
            Data::EntityData::Type::COLLECTION,
            61,
        },
        13,
    },
    // 62
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            62,
        },
        {1, 0},
        1,
        0,
    },
    // 63
    new Data::Door {
        {
            {128, 24},
            Data::EntityData::Type::DOOR,
            63,
        },
        {2, 1},
        0,
        0,
    },
    // 64
    new Data::NPC {
        {
            {112, 96},
            Data::EntityData::Type::NPC,
            64,
        },
        -1,
    },
    // 65
    new Data::Checkpoint {
        {
            {104, 24},
            Data::EntityData::Type::CHECKPOINT,
            65,
        },
    },
    // 66
    new Data::Enemy {
        {
            {72, 56},
            Data::EntityData::Type::ENEMY,
            66,
        },
        0,
    },
    // 67
    new Data::Enemy {
        {
            {72, 88},
            Data::EntityData::Type::ENEMY,
            67,
        },
        0,
    },
    // 68
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            68,
        },
        {0, 2},
        1,
        0,
    },
    // 69
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            69,
        },
        {4, 3},
        0,
        0,
    },
    // 70
    new Data::Enemy {
        {
            {64, 48},
            Data::EntityData::Type::ENEMY,
            70,
        },
        0,
    },
    // 71
    new Data::Enemy {
        {
            {39, 72},
            Data::EntityData::Type::ENEMY,
            71,
        },
        0,
    },
    // 72
    new Data::Enemy {
        {
            {64, 96},
            Data::EntityData::Type::ENEMY,
            72,
        },
        0,
    },
    // 73
    new Data::Enemy {
        {
            {28, 96},
            Data::EntityData::Type::ENEMY,
            73,
        },
        0,
    },
    // 74
    new Data::Enemy {
        {
            {68, 96},
            Data::EntityData::Type::ENEMY,
            74,
        },
        0,
    },
    // 75
    new Data::Enemy {
        {
            {77, 96},
            Data::EntityData::Type::ENEMY,
            75,
        },
        0,
    },
    // 76
    new Data::Enemy {
        {
            {56, 96},
            Data::EntityData::Type::ENEMY,
            76,
        },
        0,
    },
    // 77
    new Data::Enemy {
        {
            {31, 96},
            Data::EntityData::Type::ENEMY,
            77,
        },
        0,
    },
    // 78
    new Data::Door {
        {
            {136, 16},
            Data::EntityData::Type::DOOR,
            78,
        },
        {1, 0},
        2,
        0,
    },
    // 79
    new Data::Door {
        {
            {136, 96},
            Data::EntityData::Type::DOOR,
            79,
        },
        {3, 0},
        1,
        0,
    },
    // 80
    new Data::NPC {
        {
            {104, 16},
            Data::EntityData::Type::NPC,
            80,
        },
        2,
    },
    // 81
    new Data::Checkpoint {
        {
            {40, 16},
            Data::EntityData::Type::CHECKPOINT,
            81,
        },
    },
    // 82
    new Data::Door {
        {
            {8, 8},
            Data::EntityData::Type::DOOR,
            82,
        },
        {1, 1},
        0,
        0,
    },
    // 83
    new Data::NPC {
        {
            {16, 96},
            Data::EntityData::Type::NPC,
            83,
        },
        6,
    },
    // 84
    new Data::Collection {
        {
            {56, 96},
            Data::EntityData::Type::COLLECTION,
            84,
        },
        1,
    },
    // 85
    new Data::Enemy {
        {
            {73, 0},
            Data::EntityData::Type::ENEMY,
            85,
        },
        0,
    },
    // 86
    new Data::Enemy {
        {
            {101, 48},
            Data::EntityData::Type::ENEMY,
            86,
        },
        1,
    },
    // 87
    new Data::Checkpoint {
        {
            {136, 72},
            Data::EntityData::Type::CHECKPOINT,
            87,
        },
    },
    // 88
    new Data::Collection {
        {
            {40, 80},
            Data::EntityData::Type::COLLECTION,
            88,
        },
        9,
    },
    // 89
    new Data::Enemy {
        {
            {73, 0},
            Data::EntityData::Type::ENEMY,
            89,
        },
        0,
    },
    // 90
    new Data::Enemy {
        {
            {35, 48},
            Data::EntityData::Type::ENEMY,
            90,
        },
        1,
    },
    // 91
    new Data::Checkpoint {
        {
            {136, 72},
            Data::EntityData::Type::CHECKPOINT,
            91,
        },
    },
    // 92
    new Data::Collection {
        {
            {40, 80},
            Data::EntityData::Type::COLLECTION,
            92,
        },
        9,
    },
    // 93
    new Data::Checkpoint {
        {
            {40, 96},
            Data::EntityData::Type::CHECKPOINT,
            93,
        },
    },
    // 94
    new Data::Enemy {
        {
            {132, 48},
            Data::EntityData::Type::ENEMY,
            94,
        },
        0,
    },
    // 95
    new Data::NPC {
        {
            {112, 96},
            Data::EntityData::Type::NPC,
            95,
        },
        5,
    },
    // 96
    new Data::Enemy {
        {
            {8, 96},
            Data::EntityData::Type::ENEMY,
            96,
        },
        0,
    },
    // 97
    new Data::Enemy {
        {
            {129, 96},
            Data::EntityData::Type::ENEMY,
            97,
        },
        0,
    },
    // 98
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            98,
        },
        {3, 3},
        0,
        0,
    },
    // 99
    new Data::Door {
        {
            {72, 16},
            Data::EntityData::Type::DOOR,
            99,
        },
        {5, 0},
        9,
        5,
    },
    // 100
    new Data::Door {
        {
            {120, 8},
            Data::EntityData::Type::DOOR,
            100,
        },
        {3, 5},
        10,
        0,
    },
    // 101
    new Data::Collection {
        {
            {72, 56},
            Data::EntityData::Type::COLLECTION,
            101,
        },
        0,
    },
    // 102
    new Data::Door {
        {
            {8, 40},
            Data::EntityData::Type::DOOR,
            102,
        },
        {2, 0},
        1,
        0,
    },
    // 103
    new Data::Collection {
        {
            {136, 32},
            Data::EntityData::Type::COLLECTION,
            103,
        },
        2,
    },
    // 104
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            104,
        },
        6,
    },
    // 105
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            105,
        },
        {4, 0},
        0,
        0,
    },
    // 106
    new Data::Door {
        {
            {136, 96},
            Data::EntityData::Type::DOOR,
            106,
        },
        {3, 3},
        1,
        0,
    },
    // 107
    new Data::Enemy {
        {
            {106, 96},
            Data::EntityData::Type::ENEMY,
            107,
        },
        0,
    },
    // 108
    new Data::Enemy {
        {
            {74, 96},
            Data::EntityData::Type::ENEMY,
            108,
        },
        0,
    },
    // 109
    new Data::Enemy {
        {
            {42, 96},
            Data::EntityData::Type::ENEMY,
            109,
        },
        0,
    },
    // 110
    new Data::Enemy {
        {
            {66, 48},
            Data::EntityData::Type::ENEMY,
            110,
        },
        1,
    },
    // 111
    new Data::Checkpoint {
        {
            {120, 32},
            Data::EntityData::Type::CHECKPOINT,
            111,
        },
    },
    // 112
    new Data::NPC {
        {
            {56, 32},
            Data::EntityData::Type::NPC,
            112,
        },
        10,
    },
    // 113
    new Data::Door {
        {
            {128, 48},
            Data::EntityData::Type::DOOR,
            113,
        },
        {4, 2},
        0,
        0,
    },
    // 114
    new Data::Collection {
        {
            {56, 8},
            Data::EntityData::Type::COLLECTION,
            114,
        },
        2,
    },
    // 115
    new Data::Collection {
        {
            {120, 24},
            Data::EntityData::Type::COLLECTION,
            115,
        },
        0,
    },
    // 116
    new Data::Collection {
        {
            {24, 16},
            Data::EntityData::Type::COLLECTION,
            116,
        },
        13,
    },
    // 117
    new Data::Collection {
        {
            {80, 72},
            Data::EntityData::Type::COLLECTION,
            117,
        },
        7,
    },
    // 118
    new Data::Collection {
        {
            {56, 96},
            Data::EntityData::Type::COLLECTION,
            118,
        },
        6,
    },
    // 119
    new Data::Door {
        {
            {16, 72},
            Data::EntityData::Type::DOOR,
            119,
        },
        {3, 5},
        10,
        9999,
    },
    // 120
    new Data::Checkpoint {
        {
            {40, 48},
            Data::EntityData::Type::CHECKPOINT,
            120,
        },
    },
    // 121
    new Data::Checkpoint {
        {
            {64, 40},
            Data::EntityData::Type::CHECKPOINT,
            121,
        },
    },
    // 122
    new Data::Checkpoint {
        {
            {88, 48},
            Data::EntityData::Type::CHECKPOINT,
            122,
        },
    },
    // 123
    new Data::Checkpoint {
        {
            {112, 16},
            Data::EntityData::Type::CHECKPOINT,
            123,
        },
    },
    // 124
    new Data::Enemy {
        {
            {39, 88},
            Data::EntityData::Type::ENEMY,
            124,
        },
        0,
    },
    // 125
    new Data::Enemy {
        {
            {7, 8},
            Data::EntityData::Type::ENEMY,
            125,
        },
        0,
    },
    // 126
    new Data::Checkpoint {
        {
            {16, 40},
            Data::EntityData::Type::CHECKPOINT,
            126,
        },
    },
    // 127
    new Data::Collection {
        {
            {128, 0},
            Data::EntityData::Type::COLLECTION,
            127,
        },
        14,
    },
    // 128
    new Data::Collection {
        {
            {112, 88},
            Data::EntityData::Type::COLLECTION,
            128,
        },
        3,
    },
    // 129
    new Data::Collection {
        {
            {8, 88},
            Data::EntityData::Type::COLLECTION,
            129,
        },
        4,
    },
    // 130
    new Data::Collection {
        {
            {136, 96},
            Data::EntityData::Type::COLLECTION,
            130,
        },
        5,
    },
    // 131
    new Data::Enemy {
        {
            {125, 24},
            Data::EntityData::Type::ENEMY,
            131,
        },
        1,
    },
    // 132
    new Data::Enemy {
        {
            {112, 72},
            Data::EntityData::Type::ENEMY,
            132,
        },
        0,
    },
    // 133
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            133,
        },
        {3, 1},
        1,
        0,
    },
    // 134
    new Data::Door {
        {
            {24, 40},
            Data::EntityData::Type::DOOR,
            134,
        },
        {2, 4},
        0,
        0,
    },
    // 135
    new Data::NPC {
        {
            {136, 96},
            Data::EntityData::Type::NPC,
            135,
        },
        11,
    },
    // 136
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            136,
        },
        {3, 1},
        1,
        0,
    },
    // 137
    new Data::Door {
        {
            {24, 40},
            Data::EntityData::Type::DOOR,
            137,
        },
        {2, 4},
        0,
        0,
    },
    // 138
    new Data::NPC {
        {
            {136, 96},
            Data::EntityData::Type::NPC,
            138,
        },
        11,
    },
    // 139
    new Data::Collection {
        {
            {72, 24},
            Data::EntityData::Type::COLLECTION,
            139,
        },
        12,
    },
    // 140
    new Data::Collection {
        {
            {64, 40},
            Data::EntityData::Type::COLLECTION,
            140,
        },
        6,
    },
    // 141
    new Data::Collection {
        {
            {128, 40},
            Data::EntityData::Type::COLLECTION,
            141,
        },
        15,
    },
    // 142
    new Data::Door {
        {
            {136, 8},
            Data::EntityData::Type::DOOR,
            142,
        },
        {4, 3},
        10,
        0,
    },
    // 143
    new Data::Door {
        {
            {88, 56},
            Data::EntityData::Type::DOOR,
            143,
        },
        {0, 4},
        0,
        0,
    },
    // 144
    new Data::Door {
        {
            {136, 8},
            Data::EntityData::Type::DOOR,
            144,
        },
        {4, 3},
        10,
        0,
    },
    // 145
    new Data::Door {
        {
            {88, 56},
            Data::EntityData::Type::DOOR,
            145,
        },
        {0, 4},
        0,
        7,
    },
    // 146
    new Data::Collection {
        {
            {24, 24},
            Data::EntityData::Type::COLLECTION,
            146,
        },
        0,
    },
    // 147
    new Data::Collection {
        {
            {16, 48},
            Data::EntityData::Type::COLLECTION,
            147,
        },
        0,
    },
    // 148
    new Data::Collection {
        {
            {32, 64},
            Data::EntityData::Type::COLLECTION,
            148,
        },
        9,
    },
    // 149
    new Data::Collection {
        {
            {88, 24},
            Data::EntityData::Type::COLLECTION,
            149,
        },
        10,
    },
    // 150
    new Data::Collection {
        {
            {88, 48},
            Data::EntityData::Type::COLLECTION,
            150,
        },
        11,
    },
    // 151
    new Data::Enemy {
        {
            {112, 24},
            Data::EntityData::Type::ENEMY,
            151,
        },
        0,
    },
    // 152
    new Data::Enemy {
        {
            {128, 56},
            Data::EntityData::Type::ENEMY,
            152,
        },
        0,
    },
    // 153
    new Data::Enemy {
        {
            {89, 88},
            Data::EntityData::Type::ENEMY,
            153,
        },
        0,
    },
    // 154
    new Data::Door {
        {
            {120, 80},
            Data::EntityData::Type::DOOR,
            154,
        },
        {2, 4},
        10,
        0,
    },
    // 155
    new Data::Door {
        {
            {8, 32},
            Data::EntityData::Type::DOOR,
            155,
        },
        {0, 0},
        0,
        1,
    },
    // 156
    new Data::Checkpoint {
        {
            {56, 64},
            Data::EntityData::Type::CHECKPOINT,
            156,
        },
    },
    // 157
    new Data::Checkpoint {
        {
            {24, 88},
            Data::EntityData::Type::CHECKPOINT,
            157,
        },
    },
    // 158
    new Data::NPC {
        {
            {88, 88},
            Data::EntityData::Type::NPC,
            158,
        },
        0,
    },
    // 159
    new Data::Door {
        {
            {120, 16},
            Data::EntityData::Type::DOOR,
            159,
        },
        {4, 0},
        4,
        0,
    },
    // 160
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            160,
        },
        {4, 0},
        4,
        0,
    },
    // 161
    new Data::Enemy {
        {
            {18, 96},
            Data::EntityData::Type::ENEMY,
            161,
        },
        0,
    },
    // 162
    new Data::Door {
        {
            {128, 96},
            Data::EntityData::Type::DOOR,
            162,
        },
        {4, 1},
        2,
        0,
    },
    // 163
    new Data::Door {
        {
            {24, 16},
            Data::EntityData::Type::DOOR,
            163,
        },
        {3, 1},
        0,
        0,
    },
    // 164
    new Data::Checkpoint {
        {
            {80, 96},
            Data::EntityData::Type::CHECKPOINT,
            164,
        },
    },
    // 165
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            165,
        },
        9,
    },
    // 166
    new Data::Door {
        {
            {24, 16},
            Data::EntityData::Type::DOOR,
            166,
        },
        {4, 1},
        1,
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
        1,
        0,
    },
    // 168
    new Data::Door {
        {
            {120, 16},
            Data::EntityData::Type::DOOR,
            168,
        },
        {4, 0},
        2,
        0,
    },
    // 169
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            169,
        },
        {0, 1},
        10,
        0,
    },
    // 170
    new Data::Enemy {
        {
            {97, 96},
            Data::EntityData::Type::ENEMY,
            170,
        },
        0,
    },
    // 171
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            171,
        },
        8,
    },
    // 172
    new Data::Door {
        {
            {8, 24},
            Data::EntityData::Type::DOOR,
            172,
        },
        {3, 2},
        0,
        0,
    },
    // 173
    new Data::Checkpoint {
        {
            {8, 40},
            Data::EntityData::Type::CHECKPOINT,
            173,
        },
    },
    // 174
    new Data::Collection {
        {
            {88, 24},
            Data::EntityData::Type::COLLECTION,
            174,
        },
        6,
    },
    // 175
    new Data::NPC {
        {
            {104, 96},
            Data::EntityData::Type::NPC,
            175,
        },
        99,
    },
    // 176
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            176,
        },
        {1, 3},
        0,
        0,
    },
    // 177
    new Data::Checkpoint {
        {
            {128, 96},
            Data::EntityData::Type::CHECKPOINT,
            177,
        },
    },
    // 178
    new Data::Collection {
        {
            {64, 56},
            Data::EntityData::Type::COLLECTION,
            178,
        },
        5,
    },
    // 179
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            179,
        },
        {0, 4},
        1,
        0,
    },
    // 180
    new Data::Checkpoint {
        {
            {32, 96},
            Data::EntityData::Type::CHECKPOINT,
            180,
        },
    },
    // 181
    new Data::Door {
        {
            {104, 16},
            Data::EntityData::Type::DOOR,
            181,
        },
        {2, 4},
        10,
        0,
    },
    // 182
    new Data::Collection {
        {
            {32, 96},
            Data::EntityData::Type::COLLECTION,
            182,
        },
        16,
    },
    // 183
    new Data::Collection {
        {
            {88, 96},
            Data::EntityData::Type::COLLECTION,
            183,
        },
        10,
    },
    // 184
    new Data::NPC {
        {
            {72, 96},
            Data::EntityData::Type::NPC,
            184,
        },
        22,
    },
    // 185
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            185,
        },
        {2, 4},
        9,
        0,
    },
    // 186
    new Data::Door {
        {
            {72, 8},
            Data::EntityData::Type::DOOR,
            186,
        },
        {5, 4},
        1,
        0,
    },
    // 187
    new Data::NPC {
        {
            {72, 56},
            Data::EntityData::Type::NPC,
            187,
        },
        14,
    },
    // 188
    new Data::Checkpoint {
        {
            {40, 96},
            Data::EntityData::Type::CHECKPOINT,
            188,
        },
    },
    // 189
    new Data::Enemy {
        {
            {127, 64},
            Data::EntityData::Type::ENEMY,
            189,
        },
        1,
    },
    // 190
    new Data::Enemy {
        {
            {128, 24},
            Data::EntityData::Type::ENEMY,
            190,
        },
        1,
    },
    // 191
    new Data::Checkpoint {
        {
            {24, 8},
            Data::EntityData::Type::CHECKPOINT,
            191,
        },
    },
    // 192
    new Data::Door {
        {
            {8, 8},
            Data::EntityData::Type::DOOR,
            192,
        },
        {0, 2},
        10,
        0,
    },
    // 193
    new Data::Enemy {
        {
            {41, 16},
            Data::EntityData::Type::ENEMY,
            193,
        },
        1,
    },
    // 194
    new Data::Door {
        {
            {128, 96},
            Data::EntityData::Type::DOOR,
            194,
        },
        {5, 4},
        0,
        0,
    },
    // 195
    new Data::NPC {
        {
            {64, 48},
            Data::EntityData::Type::NPC,
            195,
        },
        13,
    },
    // 196
    new Data::Enemy {
        {
            {83, 96},
            Data::EntityData::Type::ENEMY,
            196,
        },
        0,
    },
    // 197
    new Data::Enemy {
        {
            {30, 64},
            Data::EntityData::Type::ENEMY,
            197,
        },
        1,
    },
    // 198
    new Data::Door {
        {
            {128, 16},
            Data::EntityData::Type::DOOR,
            198,
        },
        {0, 3},
        0,
        0,
    },
    // 199
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            199,
        },
        {5, 0},
        1,
        0,
    },
    // 200
    new Data::Door {
        {
            {56, 48},
            Data::EntityData::Type::DOOR,
            200,
        },
        {5, 2},
        0,
        0,
    },
    // 201
    new Data::NPC {
        {
            {88, 96},
            Data::EntityData::Type::NPC,
            201,
        },
        12,
    },
    // 202
    new Data::Checkpoint {
        {
            {48, 96},
            Data::EntityData::Type::CHECKPOINT,
            202,
        },
    },
    // 203
    new Data::NPC {
        {
            {48, 88},
            Data::EntityData::Type::NPC,
            203,
        },
        16,
    },
    // 204
    new Data::NPC {
        {
            {88, 88},
            Data::EntityData::Type::NPC,
            204,
        },
        17,
    },
    // 205
    new Data::NPC {
        {
            {128, 88},
            Data::EntityData::Type::NPC,
            205,
        },
        18,
    },
    // 206
    new Data::NPC {
        {
            {240, 88},
            Data::EntityData::Type::NPC,
            206,
        },
        19,
    },
    // 207
    new Data::NPC {
        {
            {288, 88},
            Data::EntityData::Type::NPC,
            207,
        },
        20,
    },
};

#include "Entities.hpp"

const Data::EntityData *Data::ENTITIES[] {
    // 0
    new Data::Door {
        {
            {136, 8},
            Data::EntityData::Type::DOOR,
            0,
        },
        {4, 3},
        10,
        0,
    },
    // 1
    new Data::Door {
        {
            {88, 56},
            Data::EntityData::Type::DOOR,
            1,
        },
        {0, 4},
        0,
        0,
    },
    // 2
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            2,
        },
        {3, 4},
        0,
        0,
    },
    // 3
    new Data::Enemy {
        {
            {69, 48},
            Data::EntityData::Type::ENEMY,
            3,
        },
        1,
    },
    // 4
    new Data::Door {
        {
            {72, 64},
            Data::EntityData::Type::DOOR,
            4,
        },
        {4, 4},
        1,
        0,
    },
    // 5
    new Data::Checkpoint {
        {
            {136, 96},
            Data::EntityData::Type::CHECKPOINT,
            5,
        },
    },
    // 6
    new Data::Collection {
        {
            {8, 96},
            Data::EntityData::Type::COLLECTION,
            6,
        },
        4,
    },
    // 7
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            7,
        },
        {0, 4},
        1,
        0,
    },
    // 8
    new Data::Checkpoint {
        {
            {32, 96},
            Data::EntityData::Type::CHECKPOINT,
            8,
        },
    },
    // 9
    new Data::Door {
        {
            {104, 16},
            Data::EntityData::Type::DOOR,
            9,
        },
        {2, 4},
        10,
        0,
    },
    // 10
    new Data::Enemy {
        {
            {73, 0},
            Data::EntityData::Type::ENEMY,
            10,
        },
        0,
    },
    // 11
    new Data::Enemy {
        {
            {101, 48},
            Data::EntityData::Type::ENEMY,
            11,
        },
        1,
    },
    // 12
    new Data::Checkpoint {
        {
            {136, 72},
            Data::EntityData::Type::CHECKPOINT,
            12,
        },
    },
    // 13
    new Data::Collection {
        {
            {40, 80},
            Data::EntityData::Type::COLLECTION,
            13,
        },
        9,
    },
    // 14
    new Data::Door {
        {
            {136, 16},
            Data::EntityData::Type::DOOR,
            14,
        },
        {1, 0},
        2,
        0,
    },
    // 15
    new Data::Door {
        {
            {136, 96},
            Data::EntityData::Type::DOOR,
            15,
        },
        {3, 0},
        1,
        0,
    },
    // 16
    new Data::NPC {
        {
            {104, 16},
            Data::EntityData::Type::NPC,
            16,
        },
        2,
    },
    // 17
    new Data::Checkpoint {
        {
            {40, 16},
            Data::EntityData::Type::CHECKPOINT,
            17,
        },
    },
    // 18
    new Data::Door {
        {
            {136, 8},
            Data::EntityData::Type::DOOR,
            18,
        },
        {4, 3},
        10,
        0,
    },
    // 19
    new Data::Door {
        {
            {88, 56},
            Data::EntityData::Type::DOOR,
            19,
        },
        {0, 0},
        12,
        9999,
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
            {128, 56},
            Data::EntityData::Type::DOOR,
            24,
        },
        {2, 0},
        2,
        0,
    },
    // 25
    new Data::Door {
        {
            {16, 56},
            Data::EntityData::Type::DOOR,
            25,
        },
        {1, 1},
        1,
        0,
    },
    // 26
    new Data::NPC {
        {
            {112, 56},
            Data::EntityData::Type::NPC,
            26,
        },
        1,
    },
    // 27
    new Data::Door {
        {
            {72, 88},
            Data::EntityData::Type::DOOR,
            27,
        },
        {0, 1},
        0,
        2,
    },
    // 28
    new Data::NPC {
        {
            {48, 88},
            Data::EntityData::Type::NPC,
            28,
        },
        16,
    },
    // 29
    new Data::NPC {
        {
            {88, 88},
            Data::EntityData::Type::NPC,
            29,
        },
        17,
    },
    // 30
    new Data::NPC {
        {
            {128, 88},
            Data::EntityData::Type::NPC,
            30,
        },
        18,
    },
    // 31
    new Data::NPC {
        {
            {240, 88},
            Data::EntityData::Type::NPC,
            31,
        },
        19,
    },
    // 32
    new Data::NPC {
        {
            {288, 88},
            Data::EntityData::Type::NPC,
            32,
        },
        20,
    },
    // 33
    new Data::Enemy {
        {
            {72, 56},
            Data::EntityData::Type::ENEMY,
            33,
        },
        0,
    },
    // 34
    new Data::Enemy {
        {
            {72, 88},
            Data::EntityData::Type::ENEMY,
            34,
        },
        0,
    },
    // 35
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            35,
        },
        {0, 2},
        1,
        0,
    },
    // 36
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            36,
        },
        {4, 0},
        0,
        0,
    },
    // 37
    new Data::Door {
        {
            {136, 96},
            Data::EntityData::Type::DOOR,
            37,
        },
        {3, 3},
        1,
        0,
    },
    // 38
    new Data::Enemy {
        {
            {106, 96},
            Data::EntityData::Type::ENEMY,
            38,
        },
        0,
    },
    // 39
    new Data::Enemy {
        {
            {74, 96},
            Data::EntityData::Type::ENEMY,
            39,
        },
        0,
    },
    // 40
    new Data::Enemy {
        {
            {42, 96},
            Data::EntityData::Type::ENEMY,
            40,
        },
        0,
    },
    // 41
    new Data::Enemy {
        {
            {66, 48},
            Data::EntityData::Type::ENEMY,
            41,
        },
        1,
    },
    // 42
    new Data::Checkpoint {
        {
            {120, 32},
            Data::EntityData::Type::CHECKPOINT,
            42,
        },
    },
    // 43
    new Data::NPC {
        {
            {56, 32},
            Data::EntityData::Type::NPC,
            43,
        },
        10,
    },
    // 44
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            44,
        },
        {1, 3},
        0,
        0,
    },
    // 45
    new Data::Checkpoint {
        {
            {128, 96},
            Data::EntityData::Type::CHECKPOINT,
            45,
        },
    },
    // 46
    new Data::Collection {
        {
            {64, 56},
            Data::EntityData::Type::COLLECTION,
            46,
        },
        5,
    },
    // 47
    new Data::Enemy {
        {
            {28, 96},
            Data::EntityData::Type::ENEMY,
            47,
        },
        0,
    },
    // 48
    new Data::Enemy {
        {
            {68, 96},
            Data::EntityData::Type::ENEMY,
            48,
        },
        0,
    },
    // 49
    new Data::Enemy {
        {
            {77, 96},
            Data::EntityData::Type::ENEMY,
            49,
        },
        0,
    },
    // 50
    new Data::Enemy {
        {
            {56, 96},
            Data::EntityData::Type::ENEMY,
            50,
        },
        0,
    },
    // 51
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            51,
        },
        {4, 3},
        0,
        0,
    },
    // 52
    new Data::Enemy {
        {
            {64, 48},
            Data::EntityData::Type::ENEMY,
            52,
        },
        0,
    },
    // 53
    new Data::Enemy {
        {
            {39, 72},
            Data::EntityData::Type::ENEMY,
            53,
        },
        0,
    },
    // 54
    new Data::Enemy {
        {
            {64, 96},
            Data::EntityData::Type::ENEMY,
            54,
        },
        0,
    },
    // 55
    new Data::Door {
        {
            {8, 8},
            Data::EntityData::Type::DOOR,
            55,
        },
        {1, 1},
        0,
        0,
    },
    // 56
    new Data::NPC {
        {
            {16, 96},
            Data::EntityData::Type::NPC,
            56,
        },
        6,
    },
    // 57
    new Data::Collection {
        {
            {56, 96},
            Data::EntityData::Type::COLLECTION,
            57,
        },
        1,
    },
    // 58
    new Data::Enemy {
        {
            {8, 96},
            Data::EntityData::Type::ENEMY,
            58,
        },
        0,
    },
    // 59
    new Data::Enemy {
        {
            {129, 96},
            Data::EntityData::Type::ENEMY,
            59,
        },
        0,
    },
    // 60
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            60,
        },
        {3, 3},
        0,
        0,
    },
    // 61
    new Data::Door {
        {
            {72, 16},
            Data::EntityData::Type::DOOR,
            61,
        },
        {5, 0},
        9,
        5,
    },
    // 62
    new Data::Door {
        {
            {120, 8},
            Data::EntityData::Type::DOOR,
            62,
        },
        {3, 5},
        10,
        0,
    },
    // 63
    new Data::Collection {
        {
            {72, 56},
            Data::EntityData::Type::COLLECTION,
            63,
        },
        0,
    },
    // 64
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            64,
        },
        {1, 0},
        1,
        0,
    },
    // 65
    new Data::Door {
        {
            {128, 24},
            Data::EntityData::Type::DOOR,
            65,
        },
        {2, 1},
        0,
        0,
    },
    // 66
    new Data::NPC {
        {
            {112, 96},
            Data::EntityData::Type::NPC,
            66,
        },
        -1,
    },
    // 67
    new Data::Checkpoint {
        {
            {104, 24},
            Data::EntityData::Type::CHECKPOINT,
            67,
        },
    },
    // 68
    new Data::Door {
        {
            {128, 16},
            Data::EntityData::Type::DOOR,
            68,
        },
        {0, 3},
        0,
        0,
    },
    // 69
    new Data::Enemy {
        {
            {103, 32},
            Data::EntityData::Type::ENEMY,
            69,
        },
        1,
    },
    // 70
    new Data::Checkpoint {
        {
            {80, 72},
            Data::EntityData::Type::CHECKPOINT,
            70,
        },
    },
    // 71
    new Data::Checkpoint {
        {
            {16, 96},
            Data::EntityData::Type::CHECKPOINT,
            71,
        },
    },
    // 72
    new Data::Collection {
        {
            {120, 96},
            Data::EntityData::Type::COLLECTION,
            72,
        },
        10,
    },
    // 73
    new Data::Enemy {
        {
            {105, 96},
            Data::EntityData::Type::ENEMY,
            73,
        },
        0,
    },
    // 74
    new Data::Door {
        {
            {128, 48},
            Data::EntityData::Type::DOOR,
            74,
        },
        {5, 5},
        0,
        0,
    },
    // 75
    new Data::Collection {
        {
            {144, 72},
            Data::EntityData::Type::COLLECTION,
            75,
        },
        8,
    },
    // 76
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            76,
        },
        {1, 0},
        0,
        0,
    },
    // 77
    new Data::Door {
        {
            {40, 48},
            Data::EntityData::Type::DOOR,
            77,
        },
        {4, 1},
        10,
        0,
    },
    // 78
    new Data::Checkpoint {
        {
            {56, 48},
            Data::EntityData::Type::CHECKPOINT,
            78,
        },
    },
    // 79
    new Data::NPC {
        {
            {80, 96},
            Data::EntityData::Type::NPC,
            79,
        },
        7,
    },
    // 80
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            80,
        },
        {5, 0},
        1,
        0,
    },
    // 81
    new Data::Door {
        {
            {56, 48},
            Data::EntityData::Type::DOOR,
            81,
        },
        {5, 2},
        0,
        0,
    },
    // 82
    new Data::NPC {
        {
            {88, 96},
            Data::EntityData::Type::NPC,
            82,
        },
        12,
    },
    // 83
    new Data::Checkpoint {
        {
            {48, 96},
            Data::EntityData::Type::CHECKPOINT,
            83,
        },
    },
    // 84
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            84,
        },
        {2, 4},
        9,
        0,
    },
    // 85
    new Data::Door {
        {
            {72, 8},
            Data::EntityData::Type::DOOR,
            85,
        },
        {5, 4},
        1,
        0,
    },
    // 86
    new Data::NPC {
        {
            {72, 56},
            Data::EntityData::Type::NPC,
            86,
        },
        14,
    },
    // 87
    new Data::Checkpoint {
        {
            {40, 96},
            Data::EntityData::Type::CHECKPOINT,
            87,
        },
    },
    // 88
    new Data::Door {
        {
            {8, 24},
            Data::EntityData::Type::DOOR,
            88,
        },
        {3, 2},
        0,
        0,
    },
    // 89
    new Data::Checkpoint {
        {
            {8, 40},
            Data::EntityData::Type::CHECKPOINT,
            89,
        },
    },
    // 90
    new Data::NPC {
        {
            {104, 96},
            Data::EntityData::Type::NPC,
            90,
        },
        99,
    },
    // 91
    new Data::Enemy {
        {
            {31, 96},
            Data::EntityData::Type::ENEMY,
            91,
        },
        0,
    },
    // 92
    new Data::Collection {
        {
            {88, 80},
            Data::EntityData::Type::COLLECTION,
            92,
        },
        3,
    },
    // 93
    new Data::Collection {
        {
            {64, 24},
            Data::EntityData::Type::COLLECTION,
            93,
        },
        7,
    },
    // 94
    new Data::Checkpoint {
        {
            {24, 80},
            Data::EntityData::Type::CHECKPOINT,
            94,
        },
    },
    // 95
    new Data::NPC {
        {
            {48, 72},
            Data::EntityData::Type::NPC,
            95,
        },
        0,
    },
    // 96
    new Data::Door {
        {
            {120, 16},
            Data::EntityData::Type::DOOR,
            96,
        },
        {4, 0},
        4,
        0,
    },
    // 97
    new Data::Door {
        {
            {24, 96},
            Data::EntityData::Type::DOOR,
            97,
        },
        {4, 0},
        4,
        0,
    },
    // 98
    new Data::Enemy {
        {
            {18, 96},
            Data::EntityData::Type::ENEMY,
            98,
        },
        0,
    },
    // 99
    new Data::Door {
        {
            {128, 96},
            Data::EntityData::Type::DOOR,
            99,
        },
        {4, 1},
        2,
        0,
    },
    // 100
    new Data::Door {
        {
            {24, 16},
            Data::EntityData::Type::DOOR,
            100,
        },
        {3, 1},
        0,
        0,
    },
    // 101
    new Data::Checkpoint {
        {
            {80, 96},
            Data::EntityData::Type::CHECKPOINT,
            101,
        },
    },
    // 102
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            102,
        },
        9,
    },
    // 103
    new Data::Checkpoint {
        {
            {40, 96},
            Data::EntityData::Type::CHECKPOINT,
            103,
        },
    },
    // 104
    new Data::Enemy {
        {
            {132, 48},
            Data::EntityData::Type::ENEMY,
            104,
        },
        0,
    },
    // 105
    new Data::NPC {
        {
            {112, 96},
            Data::EntityData::Type::NPC,
            105,
        },
        5,
    },
    // 106
    new Data::NPC {
        {
            {48, 72},
            Data::EntityData::Type::NPC,
            106,
        },
        0,
    },
    // 107
    new Data::Enemy {
        {
            {70, 72},
            Data::EntityData::Type::ENEMY,
            107,
        },
        0,
    },
    // 108
    new Data::Enemy {
        {
            {64, 72},
            Data::EntityData::Type::ENEMY,
            108,
        },
        0,
    },
    // 109
    new Data::Enemy {
        {
            {29, 72},
            Data::EntityData::Type::ENEMY,
            109,
        },
        0,
    },
    // 110
    new Data::Collection {
        {
            {120, 16},
            Data::EntityData::Type::COLLECTION,
            110,
        },
        0,
    },
    // 111
    new Data::Collection {
        {
            {144, 24},
            Data::EntityData::Type::COLLECTION,
            111,
        },
        2,
    },
    // 112
    new Data::Collection {
        {
            {104, 8},
            Data::EntityData::Type::COLLECTION,
            112,
        },
        1,
    },
    // 113
    new Data::Collection {
        {
            {48, 40},
            Data::EntityData::Type::COLLECTION,
            113,
        },
        4,
    },
    // 114
    new Data::Collection {
        {
            {40, 96},
            Data::EntityData::Type::COLLECTION,
            114,
        },
        5,
    },
    // 115
    new Data::Collection {
        {
            {16, 88},
            Data::EntityData::Type::COLLECTION,
            115,
        },
        6,
    },
    // 116
    new Data::Collection {
        {
            {8, 24},
            Data::EntityData::Type::COLLECTION,
            116,
        },
        13,
    },
    // 117
    new Data::Door {
        {
            {16, 16},
            Data::EntityData::Type::DOOR,
            117,
        },
        {1, 2},
        1,
        0,
    },
    // 118
    new Data::Enemy {
        {
            {82, 96},
            Data::EntityData::Type::ENEMY,
            118,
        },
        0,
    },
    // 119
    new Data::Checkpoint {
        {
            {32, 16},
            Data::EntityData::Type::CHECKPOINT,
            119,
        },
    },
    // 120
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            120,
        },
        {5, 1},
        10,
        0,
    },
    // 121
    new Data::Door {
        {
            {128, 48},
            Data::EntityData::Type::DOOR,
            121,
        },
        {4, 2},
        0,
        0,
    },
    // 122
    new Data::Collection {
        {
            {56, 8},
            Data::EntityData::Type::COLLECTION,
            122,
        },
        2,
    },
    // 123
    new Data::Collection {
        {
            {120, 24},
            Data::EntityData::Type::COLLECTION,
            123,
        },
        0,
    },
    // 124
    new Data::Collection {
        {
            {24, 16},
            Data::EntityData::Type::COLLECTION,
            124,
        },
        13,
    },
    // 125
    new Data::Collection {
        {
            {80, 72},
            Data::EntityData::Type::COLLECTION,
            125,
        },
        7,
    },
    // 126
    new Data::Collection {
        {
            {56, 96},
            Data::EntityData::Type::COLLECTION,
            126,
        },
        6,
    },
    // 127
    new Data::Door {
        {
            {16, 72},
            Data::EntityData::Type::DOOR,
            127,
        },
        {0, 0},
        0,
        9999,
    },
    // 128
    new Data::Checkpoint {
        {
            {40, 48},
            Data::EntityData::Type::CHECKPOINT,
            128,
        },
    },
    // 129
    new Data::Checkpoint {
        {
            {64, 40},
            Data::EntityData::Type::CHECKPOINT,
            129,
        },
    },
    // 130
    new Data::Checkpoint {
        {
            {88, 48},
            Data::EntityData::Type::CHECKPOINT,
            130,
        },
    },
    // 131
    new Data::Checkpoint {
        {
            {112, 16},
            Data::EntityData::Type::CHECKPOINT,
            131,
        },
    },
    // 132
    new Data::Enemy {
        {
            {39, 88},
            Data::EntityData::Type::ENEMY,
            132,
        },
        0,
    },
    // 133
    new Data::Enemy {
        {
            {7, 8},
            Data::EntityData::Type::ENEMY,
            133,
        },
        0,
    },
    // 134
    new Data::Checkpoint {
        {
            {16, 40},
            Data::EntityData::Type::CHECKPOINT,
            134,
        },
    },
    // 135
    new Data::Collection {
        {
            {128, 0},
            Data::EntityData::Type::COLLECTION,
            135,
        },
        14,
    },
    // 136
    new Data::Collection {
        {
            {112, 88},
            Data::EntityData::Type::COLLECTION,
            136,
        },
        3,
    },
    // 137
    new Data::Collection {
        {
            {8, 88},
            Data::EntityData::Type::COLLECTION,
            137,
        },
        4,
    },
    // 138
    new Data::Collection {
        {
            {136, 96},
            Data::EntityData::Type::COLLECTION,
            138,
        },
        5,
    },
    // 139
    new Data::Enemy {
        {
            {125, 24},
            Data::EntityData::Type::ENEMY,
            139,
        },
        1,
    },
    // 140
    new Data::Enemy {
        {
            {112, 72},
            Data::EntityData::Type::ENEMY,
            140,
        },
        0,
    },
    // 141
    new Data::Enemy {
        {
            {73, 0},
            Data::EntityData::Type::ENEMY,
            141,
        },
        0,
    },
    // 142
    new Data::Enemy {
        {
            {35, 48},
            Data::EntityData::Type::ENEMY,
            142,
        },
        1,
    },
    // 143
    new Data::Checkpoint {
        {
            {136, 72},
            Data::EntityData::Type::CHECKPOINT,
            143,
        },
    },
    // 144
    new Data::Collection {
        {
            {40, 80},
            Data::EntityData::Type::COLLECTION,
            144,
        },
        9,
    },
    // 145
    new Data::Collection {
        {
            {32, 96},
            Data::EntityData::Type::COLLECTION,
            145,
        },
        16,
    },
    // 146
    new Data::Collection {
        {
            {88, 96},
            Data::EntityData::Type::COLLECTION,
            146,
        },
        10,
    },
    // 147
    new Data::NPC {
        {
            {72, 96},
            Data::EntityData::Type::NPC,
            147,
        },
        22,
    },
    // 148
    new Data::Door {
        {
            {8, 40},
            Data::EntityData::Type::DOOR,
            148,
        },
        {2, 0},
        1,
        0,
    },
    // 149
    new Data::Collection {
        {
            {136, 32},
            Data::EntityData::Type::COLLECTION,
            149,
        },
        2,
    },
    // 150
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            150,
        },
        6,
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
            {128, 56},
            Data::EntityData::Type::DOOR,
            164,
        },
        {2, 4},
        2,
        0,
    },
    // 165
    new Data::Door {
        {
            {72, 88},
            Data::EntityData::Type::DOOR,
            165,
        },
        {0, 1},
        0,
        2,
    },
    // 166
    new Data::Checkpoint {
        {
            {16, 56},
            Data::EntityData::Type::CHECKPOINT,
            166,
        },
    },
    // 167
    new Data::Collection {
        {
            {32, 32},
            Data::EntityData::Type::COLLECTION,
            167,
        },
        13,
    },
    // 168
    new Data::Collection {
        {
            {120, 24},
            Data::EntityData::Type::COLLECTION,
            168,
        },
        13,
    },
    // 169
    new Data::Collection {
        {
            {0, 48},
            Data::EntityData::Type::COLLECTION,
            169,
        },
        13,
    },
    // 170
    new Data::Collection {
        {
            {56, 16},
            Data::EntityData::Type::COLLECTION,
            170,
        },
        13,
    },
    // 171
    new Data::Collection {
        {
            {16, 16},
            Data::EntityData::Type::COLLECTION,
            171,
        },
        13,
    },
    // 172
    new Data::Collection {
        {
            {128, 32},
            Data::EntityData::Type::COLLECTION,
            172,
        },
        13,
    },
    // 173
    new Data::Collection {
        {
            {56, 80},
            Data::EntityData::Type::COLLECTION,
            173,
        },
        13,
    },
    // 174
    new Data::Collection {
        {
            {112, 104},
            Data::EntityData::Type::COLLECTION,
            174,
        },
        13,
    },
    // 175
    new Data::Collection {
        {
            {104, 56},
            Data::EntityData::Type::COLLECTION,
            175,
        },
        13,
    },
    // 176
    new Data::Enemy {
        {
            {72, 48},
            Data::EntityData::Type::ENEMY,
            176,
        },
        0,
    },
    // 177
    new Data::Collection {
        {
            {24, 96},
            Data::EntityData::Type::COLLECTION,
            177,
        },
        13,
    },
    // 178
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            178,
        },
        {3, 1},
        1,
        0,
    },
    // 179
    new Data::Door {
        {
            {24, 40},
            Data::EntityData::Type::DOOR,
            179,
        },
        {2, 4},
        0,
        0,
    },
    // 180
    new Data::NPC {
        {
            {136, 96},
            Data::EntityData::Type::NPC,
            180,
        },
        11,
    },
    // 181
    new Data::Collection {
        {
            {72, 24},
            Data::EntityData::Type::COLLECTION,
            181,
        },
        12,
    },
    // 182
    new Data::Collection {
        {
            {64, 40},
            Data::EntityData::Type::COLLECTION,
            182,
        },
        6,
    },
    // 183
    new Data::Collection {
        {
            {128, 40},
            Data::EntityData::Type::COLLECTION,
            183,
        },
        16,
    },
    // 184
    new Data::Door {
        {
            {24, 16},
            Data::EntityData::Type::DOOR,
            184,
        },
        {4, 1},
        1,
        0,
    },
    // 185
    new Data::Door {
        {
            {128, 96},
            Data::EntityData::Type::DOOR,
            185,
        },
        {4, 1},
        1,
        0,
    },
    // 186
    new Data::Door {
        {
            {120, 16},
            Data::EntityData::Type::DOOR,
            186,
        },
        {4, 0},
        2,
        0,
    },
    // 187
    new Data::Door {
        {
            {16, 96},
            Data::EntityData::Type::DOOR,
            187,
        },
        {0, 1},
        10,
        0,
    },
    // 188
    new Data::Enemy {
        {
            {97, 96},
            Data::EntityData::Type::ENEMY,
            188,
        },
        0,
    },
    // 189
    new Data::NPC {
        {
            {72, 16},
            Data::EntityData::Type::NPC,
            189,
        },
        8,
    },
    // 190
    new Data::Enemy {
        {
            {11, 96},
            Data::EntityData::Type::ENEMY,
            190,
        },
        0,
    },
    // 191
    new Data::Enemy {
        {
            {120, 96},
            Data::EntityData::Type::ENEMY,
            191,
        },
        0,
    },
    // 192
    new Data::Collection {
        {
            {72, 56},
            Data::EntityData::Type::COLLECTION,
            192,
        },
        0,
    },
    // 193
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            193,
        },
        {3, 3},
        0,
        0,
    },
    // 194
    new Data::Collection {
        {
            {40, 64},
            Data::EntityData::Type::COLLECTION,
            194,
        },
        5,
    },
    // 195
    new Data::Collection {
        {
            {104, 64},
            Data::EntityData::Type::COLLECTION,
            195,
        },
        4,
    },
    // 196
    new Data::NPC {
        {
            {48, 72},
            Data::EntityData::Type::NPC,
            196,
        },
        0,
    },
    // 197
    new Data::Door {
        {
            {72, 56},
            Data::EntityData::Type::DOOR,
            197,
        },
        {2, 4},
        0,
        0,
    },
    // 198
    new Data::Collection {
        {
            {96, 56},
            Data::EntityData::Type::COLLECTION,
            198,
        },
        1,
    },
    // 199
    new Data::Collection {
        {
            {104, 56},
            Data::EntityData::Type::COLLECTION,
            199,
        },
        2,
    },
    // 200
    new Data::Enemy {
        {
            {127, 64},
            Data::EntityData::Type::ENEMY,
            200,
        },
        1,
    },
    // 201
    new Data::Enemy {
        {
            {128, 24},
            Data::EntityData::Type::ENEMY,
            201,
        },
        1,
    },
    // 202
    new Data::Checkpoint {
        {
            {24, 8},
            Data::EntityData::Type::CHECKPOINT,
            202,
        },
    },
    // 203
    new Data::Door {
        {
            {8, 8},
            Data::EntityData::Type::DOOR,
            203,
        },
        {0, 2},
        10,
        0,
    },
    // 204
    new Data::Enemy {
        {
            {41, 16},
            Data::EntityData::Type::ENEMY,
            204,
        },
        1,
    },
    // 205
    new Data::Door {
        {
            {128, 96},
            Data::EntityData::Type::DOOR,
            205,
        },
        {5, 4},
        0,
        0,
    },
    // 206
    new Data::NPC {
        {
            {64, 48},
            Data::EntityData::Type::NPC,
            206,
        },
        13,
    },
    // 207
    new Data::Enemy {
        {
            {83, 96},
            Data::EntityData::Type::ENEMY,
            207,
        },
        0,
    },
    // 208
    new Data::Enemy {
        {
            {30, 64},
            Data::EntityData::Type::ENEMY,
            208,
        },
        1,
    },
    // 209
    new Data::Door {
        {
            {8, 96},
            Data::EntityData::Type::DOOR,
            209,
        },
        {3, 1},
        1,
        0,
    },
    // 210
    new Data::Door {
        {
            {24, 40},
            Data::EntityData::Type::DOOR,
            210,
        },
        {2, 4},
        0,
        0,
    },
    // 211
    new Data::NPC {
        {
            {136, 96},
            Data::EntityData::Type::NPC,
            211,
        },
        11,
    },
    // 212
    new Data::Door {
        {
            {72, 96},
            Data::EntityData::Type::DOOR,
            212,
        },
        {3, 4},
        0,
        0,
    },
    // 213
    new Data::Enemy {
        {
            {69, 48},
            Data::EntityData::Type::ENEMY,
            213,
        },
        1,
    },
    // 214
    new Data::Door {
        {
            {72, 64},
            Data::EntityData::Type::DOOR,
            214,
        },
        {4, 4},
        1,
        0,
    },
    // 215
    new Data::Checkpoint {
        {
            {136, 96},
            Data::EntityData::Type::CHECKPOINT,
            215,
        },
    },
    // 216
    new Data::Collection {
        {
            {8, 96},
            Data::EntityData::Type::COLLECTION,
            216,
        },
        4,
    },
};

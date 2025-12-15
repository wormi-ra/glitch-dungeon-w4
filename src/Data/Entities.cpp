
#include "Entities.hpp"

const Data::EntityData *Data::ENTITIES[] {
    // 0
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {136, 8}
        },
        {4, 3},
        10,
        0,
    },
    // 1
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {88, 56}
        },
        {0, 4},
        0,
        0,
    },
    // 2
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 96}
        },
        {3, 4},
        0,
        0,
    },
    // 3
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {69, 48}
        },
        1,
    },
    // 4
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 64}
        },
        {4, 4},
        1,
        0,
    },
    // 5
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {136, 96}
        },
    },
    // 6
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {8, 96}
        },
        4,
    },
    // 7
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 96}
        },
        {0, 4},
        1,
        0,
    },
    // 8
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {32, 96}
        },
    },
    // 9
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {104, 16}
        },
        {2, 4},
        10,
        0,
    },
    // 10
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {73, 0}
        },
        0,
    },
    // 11
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {101, 48}
        },
        1,
    },
    // 12
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {136, 72}
        },
    },
    // 13
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {40, 80}
        },
        9,
    },
    // 14
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {136, 16}
        },
        {1, 0},
        2,
        0,
    },
    // 15
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {136, 96}
        },
        {3, 0},
        1,
        0,
    },
    // 16
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {104, 16}
        },
        2,
    },
    // 17
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {40, 16}
        },
    },
    // 18
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {136, 8}
        },
        {4, 3},
        10,
        0,
    },
    // 19
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {88, 56}
        },
        {0, 0},
        12,
        9999,
    },
    // 20
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 32}
        },
        {5, 3},
        0,
        0,
    },
    // 21
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 32}
        },
        {3, 4},
        10,
        0,
    },
    // 22
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {40, 8}
        },
    },
    // 23
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {64, 96}
        },
        15,
    },
    // 24
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 56}
        },
        {2, 0},
        2,
        0,
    },
    // 25
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 56}
        },
        {1, 1},
        1,
        0,
    },
    // 26
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {112, 56}
        },
        1,
    },
    // 27
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 88}
        },
        {0, 1},
        0,
        2,
    },
    // 28
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {48, 88}
        },
        16,
    },
    // 29
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {88, 88}
        },
        17,
    },
    // 30
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {128, 88}
        },
        18,
    },
    // 31
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {240, 88}
        },
        19,
    },
    // 32
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {288, 88}
        },
        20,
    },
    // 33
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {72, 56}
        },
        0,
    },
    // 34
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {72, 88}
        },
        0,
    },
    // 35
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {24, 96}
        },
        {0, 2},
        1,
        0,
    },
    // 36
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 96}
        },
        {4, 0},
        0,
        0,
    },
    // 37
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {136, 96}
        },
        {3, 3},
        1,
        0,
    },
    // 38
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {106, 96}
        },
        0,
    },
    // 39
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {74, 96}
        },
        0,
    },
    // 40
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {42, 96}
        },
        0,
    },
    // 41
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {66, 48}
        },
        1,
    },
    // 42
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {120, 32}
        },
    },
    // 43
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {56, 32}
        },
        10,
    },
    // 44
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 96}
        },
        {1, 3},
        0,
        0,
    },
    // 45
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {128, 96}
        },
    },
    // 46
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {64, 56}
        },
        5,
    },
    // 47
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {28, 96}
        },
        0,
    },
    // 48
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {68, 96}
        },
        0,
    },
    // 49
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {77, 96}
        },
        0,
    },
    // 50
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {56, 96}
        },
        0,
    },
    // 51
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 96}
        },
        {4, 3},
        0,
        0,
    },
    // 52
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {64, 48}
        },
        0,
    },
    // 53
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {39, 72}
        },
        0,
    },
    // 54
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {64, 96}
        },
        0,
    },
    // 55
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 8}
        },
        {1, 1},
        0,
        0,
    },
    // 56
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {16, 96}
        },
        6,
    },
    // 57
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {56, 96}
        },
        1,
    },
    // 58
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {8, 96}
        },
        0,
    },
    // 59
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {129, 96}
        },
        0,
    },
    // 60
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 96}
        },
        {3, 3},
        0,
        0,
    },
    // 61
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 16}
        },
        {5, 0},
        9,
        5,
    },
    // 62
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {120, 8}
        },
        {0, 0},
        10,
        0,
    },
    // 63
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {72, 56}
        },
        0,
    },
    // 64
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {24, 96}
        },
        {1, 0},
        1,
        0,
    },
    // 65
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 24}
        },
        {2, 1},
        0,
        0,
    },
    // 66
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {112, 96}
        },
        -1,
    },
    // 67
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {104, 24}
        },
    },
    // 68
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 16}
        },
        {0, 3},
        0,
        0,
    },
    // 69
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {103, 32}
        },
        1,
    },
    // 70
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {80, 72}
        },
    },
    // 71
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {16, 96}
        },
    },
    // 72
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {120, 96}
        },
        10,
    },
    // 73
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {105, 96}
        },
        0,
    },
    // 74
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 48}
        },
        {5, 5},
        0,
        0,
    },
    // 75
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {144, 72}
        },
        8,
    },
    // 76
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 96}
        },
        {1, 0},
        0,
        0,
    },
    // 77
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {40, 48}
        },
        {4, 1},
        10,
        0,
    },
    // 78
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {56, 48}
        },
    },
    // 79
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {80, 96}
        },
        7,
    },
    // 80
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 96}
        },
        {5, 0},
        1,
        0,
    },
    // 81
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {56, 48}
        },
        {5, 2},
        0,
        0,
    },
    // 82
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {88, 96}
        },
        12,
    },
    // 83
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {48, 96}
        },
    },
    // 84
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 96}
        },
        {2, 4},
        9,
        0,
    },
    // 85
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 8}
        },
        {5, 4},
        1,
        0,
    },
    // 86
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {72, 56}
        },
        14,
    },
    // 87
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {40, 96}
        },
    },
    // 88
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 24}
        },
        {3, 2},
        0,
        0,
    },
    // 89
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {8, 40}
        },
    },
    // 90
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {104, 96}
        },
        99,
    },
    // 91
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {31, 96}
        },
        0,
    },
    // 92
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {88, 80}
        },
        3,
    },
    // 93
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {64, 24}
        },
        7,
    },
    // 94
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {24, 80}
        },
    },
    // 95
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {48, 72}
        },
        0,
    },
    // 96
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {120, 16}
        },
        {4, 0},
        4,
        0,
    },
    // 97
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {24, 96}
        },
        {4, 0},
        4,
        0,
    },
    // 98
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {18, 96}
        },
        0,
    },
    // 99
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 96}
        },
        {4, 1},
        2,
        0,
    },
    // 100
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {24, 16}
        },
        {3, 1},
        0,
        0,
    },
    // 101
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {80, 96}
        },
    },
    // 102
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {72, 16}
        },
        9,
    },
    // 103
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {40, 96}
        },
    },
    // 104
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {132, 48}
        },
        0,
    },
    // 105
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {112, 96}
        },
        5,
    },
    // 106
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {48, 72}
        },
        0,
    },
    // 107
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {70, 72}
        },
        0,
    },
    // 108
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {64, 72}
        },
        0,
    },
    // 109
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {29, 72}
        },
        0,
    },
    // 110
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {120, 16}
        },
        0,
    },
    // 111
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {144, 24}
        },
        2,
    },
    // 112
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {104, 8}
        },
        1,
    },
    // 113
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {48, 40}
        },
        4,
    },
    // 114
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {40, 96}
        },
        5,
    },
    // 115
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {16, 88}
        },
        6,
    },
    // 116
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {8, 24}
        },
        22,
    },
    // 117
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 16}
        },
        {1, 2},
        1,
        0,
    },
    // 118
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {82, 96}
        },
        0,
    },
    // 119
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {32, 16}
        },
    },
    // 120
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 96}
        },
        {5, 1},
        10,
        0,
    },
    // 121
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 48}
        },
        {4, 2},
        0,
        0,
    },
    // 122
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {56, 8}
        },
        2,
    },
    // 123
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {120, 24}
        },
        0,
    },
    // 124
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {24, 16}
        },
        22,
    },
    // 125
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {80, 72}
        },
        7,
    },
    // 126
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {56, 96}
        },
        6,
    },
    // 127
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 72}
        },
        {0, 0},
        0,
        9999,
    },
    // 128
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {40, 48}
        },
    },
    // 129
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {64, 40}
        },
    },
    // 130
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {88, 48}
        },
    },
    // 131
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {112, 16}
        },
    },
    // 132
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {39, 88}
        },
        0,
    },
    // 133
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {7, 8}
        },
        0,
    },
    // 134
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {16, 40}
        },
    },
    // 135
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {128, 0}
        },
        23,
    },
    // 136
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {112, 88}
        },
        3,
    },
    // 137
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {8, 88}
        },
        4,
    },
    // 138
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {136, 96}
        },
        5,
    },
    // 139
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {125, 24}
        },
        1,
    },
    // 140
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {112, 72}
        },
        0,
    },
    // 141
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {73, 0}
        },
        0,
    },
    // 142
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {35, 48}
        },
        1,
    },
    // 143
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {136, 72}
        },
    },
    // 144
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {40, 80}
        },
        9,
    },
    // 145
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {32, 96}
        },
        30,
    },
    // 146
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {88, 96}
        },
        10,
    },
    // 147
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {72, 96}
        },
        22,
    },
    // 148
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 40}
        },
        {2, 0},
        1,
        0,
    },
    // 149
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {136, 32}
        },
        2,
    },
    // 150
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {72, 16}
        },
        6,
    },
    // 151
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {24, 24}
        },
        0,
    },
    // 152
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {16, 48}
        },
        0,
    },
    // 153
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {32, 64}
        },
        9,
    },
    // 154
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {88, 24}
        },
        10,
    },
    // 155
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {88, 48}
        },
        14,
    },
    // 156
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {112, 24}
        },
        0,
    },
    // 157
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {128, 56}
        },
        0,
    },
    // 158
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {89, 88}
        },
        0,
    },
    // 159
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {120, 80}
        },
        {0, 0},
        0,
        0,
    },
    // 160
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 32}
        },
        {0, 0},
        0,
        1,
    },
    // 161
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {56, 64}
        },
    },
    // 162
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {24, 88}
        },
    },
    // 163
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {88, 88}
        },
        0,
    },
    // 164
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 56}
        },
        {2, 4},
        2,
        0,
    },
    // 165
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 88}
        },
        {0, 1},
        0,
        2,
    },
    // 166
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {16, 56}
        },
    },
    // 167
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {32, 32}
        },
        22,
    },
    // 168
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {120, 24}
        },
        22,
    },
    // 169
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {0, 48}
        },
        22,
    },
    // 170
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {56, 16}
        },
        22,
    },
    // 171
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {16, 16}
        },
        22,
    },
    // 172
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {128, 32}
        },
        22,
    },
    // 173
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {56, 80}
        },
        22,
    },
    // 174
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {112, 104}
        },
        22,
    },
    // 175
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {104, 56}
        },
        22,
    },
    // 176
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {72, 48}
        },
        0,
    },
    // 177
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {24, 96}
        },
        22,
    },
    // 178
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 96}
        },
        {3, 1},
        1,
        0,
    },
    // 179
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {24, 40}
        },
        {2, 4},
        0,
        0,
    },
    // 180
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {136, 96}
        },
        11,
    },
    // 181
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {72, 24}
        },
        19,
    },
    // 182
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {64, 40}
        },
        6,
    },
    // 183
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {128, 40}
        },
        30,
    },
    // 184
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {24, 16}
        },
        {4, 1},
        1,
        0,
    },
    // 185
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 96}
        },
        {4, 1},
        1,
        0,
    },
    // 186
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {120, 16}
        },
        {4, 0},
        2,
        0,
    },
    // 187
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {16, 96}
        },
        {0, 1},
        10,
        0,
    },
    // 188
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {97, 96}
        },
        0,
    },
    // 189
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {72, 16}
        },
        8,
    },
    // 190
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {11, 96}
        },
        0,
    },
    // 191
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {120, 96}
        },
        0,
    },
    // 192
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {72, 56}
        },
        0,
    },
    // 193
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 96}
        },
        {3, 3},
        0,
        0,
    },
    // 194
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {40, 64}
        },
        5,
    },
    // 195
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {104, 64}
        },
        4,
    },
    // 196
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {48, 72}
        },
        0,
    },
    // 197
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 56}
        },
        {2, 4},
        0,
        0,
    },
    // 198
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {96, 56}
        },
        1,
    },
    // 199
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {104, 56}
        },
        2,
    },
    // 200
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {127, 64}
        },
        1,
    },
    // 201
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {128, 24}
        },
        1,
    },
    // 202
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {24, 8}
        },
    },
    // 203
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 8}
        },
        {0, 2},
        10,
        0,
    },
    // 204
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {41, 16}
        },
        1,
    },
    // 205
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {128, 96}
        },
        {5, 4},
        0,
        0,
    },
    // 206
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {64, 48}
        },
        13,
    },
    // 207
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {83, 96}
        },
        0,
    },
    // 208
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {30, 64}
        },
        1,
    },
    // 209
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {8, 96}
        },
        {3, 1},
        1,
        0,
    },
    // 210
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {24, 40}
        },
        {2, 4},
        0,
        0,
    },
    // 211
    new Data::NPC {
        {
            Data::EntityData::Type::NPC,
            {136, 96}
        },
        11,
    },
    // 212
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 96}
        },
        {3, 4},
        0,
        0,
    },
    // 213
    new Data::Enemy {
        {
            Data::EntityData::Type::ENEMY,
            {69, 48}
        },
        1,
    },
    // 214
    new Data::Door {
        {
            Data::EntityData::Type::DOOR,
            {72, 64}
        },
        {4, 4},
        1,
        0,
    },
    // 215
    new Data::Checkpoint {
        {
            Data::EntityData::Type::CHECKPOINT,
            {136, 96}
        },
    },
    // 216
    new Data::Collection {
        {
            Data::EntityData::Type::COLLECTION,
            {8, 96}
        },
        4,
    },
};

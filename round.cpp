#include "header.h"
using vec = std::vector<int>;
using vec2D = std::vector<vec>;


std::bitset<32> round (const std::bitset<32> &half_block, const std::bitset<48> &sub_key) {
    // int s_box[8][4][16];
    std::vector<vec2D> s_box(8, vec2D(4, vec(16, 0)));
    std::bitset<48> expanded_block;
    vec expansion { 31, 0, 1, 2, 3, 4, 3, 4, 5, 6, 7, 8, 7, 8, 9, 10, 11, 12, 11, 12, 13,
                                14, 15, 16, 15, 16, 17, 18, 19, 20, 19, 20, 21, 22, 23, 24, 23, 24, 
                                25, 26, 27, 28, 27, 28, 29, 30, 31, 0 };
    
    for (int i = 0; i < 48; ++i) 
        expanded_block[i] = half_block[expansion[i]];

// S - Boxes

// 1    
    s_box[0][0] = {14,	4,	13,	1,	2,	15,	11,	8,	3,	10,	6,	12,	5,	9,	0,	7};
    s_box[0][1] = {0,	15,	7,	4,	14,	2,	13,	1,	10,	6,	12,	11,	9,	5,	3,	8};
    s_box[0][2] = {4,	1,	14,	8,	13,	6,	2,	11,	15,	12,	9,	7,	3,	10,	5,	0};
    s_box[0][3] = {15,	12,	8,	2,	4,	9,	1,	7,	5,	11,	3,	14,	10,	0,	6,	13};
// 2
    s_box[1][0] = {};
    s_box[1][1] = {};
    s_box[1][2] = {};
    s_box[1][3] = {};
// 3
    s_box[2][0] = {};
    s_box[2][1] = {};
    s_box[2][2] = {};
    s_box[2][3] = {};
// 4
    s_box[3][0] = {};
    s_box[3][1] = {};
    s_box[3][2] = {};
    s_box[3][3] = {};
// 5
    s_box[4][0] = {};
    s_box[4][1] = {};
    s_box[4][2] = {};
    s_box[4][3] = {};
// 6
    s_box[5][0] = {};
    s_box[5][1] = {};
    s_box[5][2] = {};
    s_box[5][3] = {};
// 7
    s_box[6][0] = {};
    s_box[6][1] = {};
    s_box[6][2] = {};
    s_box[6][3] = {};
// 8
    s_box[7][0] = {};
    s_box[7][1] = {};
    s_box[7][2] = {};
    s_box[7][3] = {};

}

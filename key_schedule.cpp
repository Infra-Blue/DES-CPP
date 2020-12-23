#include "header.h"
enum {ENCRYPT, DECRYPT};


void rotate (std::bitset<28> &block) {
    int rightMost = block[0];
    block >>= 1;
    block[27] = rightMost;
}


std::vector<std::bitset<48>> generate_sub_keys (const std::string &key) {
    // converting key-string for bitwise operation
    int i = 0;
    std::bitset<64> bit_key;
    for (int c : key) {
        int plate = 1 << 7;
        while(plate) {
            bit_key[i] = plate & c;
            plate >>= 1;
            ++i;
        }
    }

    // S-tables for PC-1 and PC-2
    std::vector<int> pc_1_left{ 56, 48, 40, 32, 24, 16, 8, 0, 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35 },
                     pc_1_right{ 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 60, 52, 44, 36, 28, 20, 12, 4, 27, 19, 11, 3 },
                     pc_2{ 13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 20, 9, 22, 18, 11, 3, 25, 7, 15, 6, 26, 19, 12, 1, 40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47, 43, 48, 
                           38, 55, 33, 52, 45, 41, 49, 35, 28, 31 };
    
    std::vector<std::bitset<48>> sub_keys(16);
    std::bitset<28> left_1, right_1;
    std::bitset<24> left_2, right_2;
    
    // generating 48-bit keys
    for (auto &sk : sub_keys) {
        // 64 to 56
        for (int i = 0; i < 28; ++i) {
            left_1[i] = bit_key[pc_1_left[i]];
            right_1[i] = bit_key[pc_1_right[i]];
        }
        
        rotate(left_1);
        rotate(right_1);
        
        // 56 to 48
        for (int i = 0; i < 24; ++i) {
            left_2[i] = left_1[pc_2[i]];
            right_2[i] = right_1[pc_2[i + 24]];
        }

        // combining
        for (int i = 0; i < 24; ++i) {
            sk[i] = left_2[i];
            sk[i + 24] = right_2[i];
        }
    }
}

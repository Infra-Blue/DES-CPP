#include "header.h"
enum {ENCRYPT, DECRYPT};


void rotate (std::bitset<28> &block) {
    int rightMost = block[0];
    block >>= 1;
    block[27] = rightMost;
}

// this function constructs 16 48-bit sub-keys from a single key-string
std::vector<std::bitset<48>> generate_sub_keys (const std::string &key, int MODE) {
    std::bitset<64> bit_key (str_to_bits(key));  // converting key-string for bitwise operation

    // S-tables for PC-1 and PC-2
    vec pc_1_left{ 56, 48, 40, 32, 24, 16, 8, 0, 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35 },
        pc_1_right{ 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 60, 52, 44, 36, 28, 20, 12, 4, 27, 19, 11, 3 },
        pc_2{ 13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 20, 9, 22, 18, 11, 3, 25, 7, 15, 6, 26, 19, 12, 1, 40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47, 43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31 };
    
    std::vector<std::bitset<48>> sub_keys(16);
    std::bitset<28> left_1, right_1;
    std::bitset<24> left_2, right_2;
    
    //  PC-1 ~ 64 bits to 56 bits ~ ONLY ONCE
    for (int i = 0; i < 28; ++i) {
        left_1[i] = bit_key[pc_1_left[i]];
        right_1[i] = bit_key[pc_1_right[i]];
    }
    
    for (int i = 0; i < 16; ++i) {
        auto &sk = (MODE ? sub_keys[15 - i] : sub_keys[i]);   // shedule-direction depends on MODE (Encryption / Decryption)   

        rotate(left_1);
        rotate(right_1);
        
        // PC-2 ~ 56 bits to 48 bits
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

    return sub_keys;
}

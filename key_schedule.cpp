#include "header.h"
enum {ENCRYPT, DECRYPT};

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
    std::vector<int> pc_1_left{ 57, 49,	41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60,	52, 44, 36 },
                     pc_1_right{ 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 },
                     pc_2{ 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40,
                           51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
    
    std::bitset<28> left, right;

}

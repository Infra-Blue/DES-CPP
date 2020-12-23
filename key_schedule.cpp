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
}

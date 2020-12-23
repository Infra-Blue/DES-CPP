#include "header.h"
enum {ENCRYPT, DECRYPT};

std::vector<std::bitset<48>> sub_keys;


std::bitset<64> block (const std::bitset<64> &raw) {
    std::bitset<32> left, right;
    std::bitset<64> ripe;
    
    for (int i = 0; i < 32; ++i) {
        left[i] = raw[i];
        right[i] = raw[i + 32];
    }

    for (int i = 0; i < 15; ++i) {
        left ^= round (right, sub_keys[i]);
        std::swap (left, right);
    }

    left ^= round (right, sub_keys[15]);

    for (int i = 0; i < 32; ++i) {
        ripe[i] = left[i];
        ripe[i + 32] = right[i];
    }

    return ripe;
}


std::string des (const std::string& text, const std::string& key, int MODE) {
    std::string output;
    sub_keys = generate_sub_keys(key, MODE);
        

    return "";
}



#include "header.h"
enum {ENCRYPT, DECRYPT};

vector<bitset<48>> sub_keys;


bitset<64> block (const bitset<64> &raw) {
    bitset<32> left, right;
    bitset<64> ripe;
    
    // splitting raw 64-bits into two 
    for (int i = 0; i < 32; ++i) {
        left[i] = raw[i];
        right[i] = raw[i + 32];
    }

    // 15 rounds
    for (int i = 0; i < 15; ++i) {
        left ^= round (right, sub_keys[i]);
        swap (left, right);
    }

    // last round ~ no swap
    left ^= round (right, sub_keys[15]);

    // raw recombined into ripe
    for (int i = 0; i < 32; ++i) {
        ripe[i] = left[i];
        ripe[i + 32] = right[i];
    }

    return ripe;
}


string des (const string& text, const string& key, int MODE) {
    string output;
    sub_keys = generate_sub_keys(key, MODE);
    
    if (MODE == ENCRYPT) for (int i = 0, sz = text.size(); i < sz; i += 8)
        output.append(block(str_to_bits(text.substr(i, 8))).to_string());

    else for (int i = 0, sz = text.size(); i < sz; i += 64)
        output.append(bits_to_str(block(bitset<64>(text.substr(i, 64)))));

    output.push_back('\0');
    return output;
}



#include "header.h"

extern char choice;
extern std::string text, key;

                 /**************** Helper Functions *****************/

void error_handling () {
    if (key.size() != 8 or (choice != 'e' and choice != 'd')) {
        std::cout << "<<< ERROR >>>" << std::endl;
        exit(EXIT_FAILURE);
    }
}


void text_padding () {
   while (text.size() % 8 != 0)
        text.push_back(' ');
}


std::bitset<64> str_to_bits (const std::string& s) {
    std::bitset<64> bs;
    int i = 0;
    
    for (int c : s) {
        int plate = 1 << 7;
        while(plate) {
            bs[i] = plate & c;
            plate >>= 1;
            ++i;
        }
    }

    return bs;
}


std::string bits_to_str (const std::bitset<64> &b) {
    std::string s;
    
    for (int i = 0; i < 64; i += 8) {
        int mask = 1, c = 0;
        for(int j = i + 7; j >= i; --j) {
            if(b.test(j))
                c += mask;
            mask <<= 1;
        }
        s.push_back((char)c);
    }
    
    return s;
}

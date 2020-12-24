#include "header.h"

extern char choice;
extern string text, key;

                 /**************** Helper Functions *****************/ 

void error_handling () {
    if (key.size() != 8 or (choice != 'e' and choice != 'd')) {
        cout << "<<< ERROR >>>" << endl;
        exit(EXIT_FAILURE);
    }
}


void text_padding () {
   while (text.size() % 8 != 0)
        text.push_back(' ');
}

template<size_t sz>
int bits_eval (const bitset<sz>& b, int pos, int n) {
    int val = 0, mask = 1;

    for (int i = pos + n - 1; i >= pos; --i) {
        if (b.test(i))
            val += mask;
        mask <<= 1;
    }

    return val;
} template int bits_eval (const bitset<48>&, int, int);


template<size_t sz>
void bits_fill (bitset<sz> &b, int val, int pos, int n) {
    int mask = 1 << (n - 1);
    while (mask) {
       b[pos] = mask & val;
       mask >>= 1;
       ++pos;
    }
} template void bits_fill (bitset<32>&, int, int, int); 


bitset<64> str_to_bits (const string& s) {
    bitset<64> b;
    
    for (int i = 0, j = 0, sz = s.size(); i < sz; ++i, j += 8)
        bits_fill(b, s[i], j, 8);

    return b;
}


string bits_to_str (const bitset<64> &b) {
    string s;
    
    for (int i = 0; i < 64; i += 8)
      s.push_back((char) bits_eval(b, i, 8));
    
    return s;
}

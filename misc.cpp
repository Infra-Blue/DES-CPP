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
} template int bits_eval<48> (const bitset<48>&, int, int);


bitset<64> str_to_bits (const string& s) {
    bitset<64> bs;
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


string bits_to_str (const bitset<64> &b) {
    string s;
    
    for (int i = 0; i < 64; i += 8)
      s.push_back((char) bits_eval(b, i, 8));
    
    return s;
}

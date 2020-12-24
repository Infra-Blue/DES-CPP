#pragma once 

// includes
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

// typedefs
using namespace std;
using vec = vector<int>;
using vec2D = vector<vec>;
using vec3D = vector<vec2D>;

// function prototypes
void error_handling ();
void text_padding ();
bitset<64> str_to_bits (const string&);
string bits_to_str (const bitset<64>&);
string des (const string&, const string&, int);
vector<bitset<48>> generate_sub_keys (const string&, int);
bitset<32> round (const bitset<32>&, const bitset<48>&);
template<size_t sz> int bits_eval (const bitset<sz>&, int, int);
template<size_t sz> void bits_fill (bitset<sz>&, int, int, int);





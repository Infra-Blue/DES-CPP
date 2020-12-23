#pragma once

// includes
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

// using vec = std::vector<int>;
// using string = std::string;
// using bits_32 = std::bitset<32>;
// using bits_48 = std::bitset<48>;
// using bits_64 = std::bitset<64>;


// function prototypes
void error_handling ();
void text_padding ();
std::string des (const std::string&, const std::string&, int);
std::bitset<64> str_to_bits (const std::string&);
std::vector<std::bitset<48>> generate_sub_keys (const std::string&, int);
std::bitset<32> round (const std::bitset<32>&, const std::bitset<48>&);



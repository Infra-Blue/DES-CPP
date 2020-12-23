#pragma once

// includes
#include <iostream>
#include <string>
#include <vector>
#include <bitset>


// function prototypes
void error_handling ();
void text_padding ();
std::string des (const std::string&, const std::string&, int);
std::bitset<64> str_to_bits (const std::string&);
std::vector<std::bitset<48>> generate_sub_keys (const std::string&, int);



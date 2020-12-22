#include "header.h"

extern char choice;
extern std::string text, key;


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

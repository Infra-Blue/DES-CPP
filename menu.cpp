#include "header.h"
void error_handling ();
void text_padding ();


char choice;
std::string text, key;


int main () {
    // user prompts
    std::cout << "< DES Encryption >\nEnter your choice <e to encrypt, d to decrypt>: ";        
    std::cin >> choice;
    std::cout << "Enter Text: ";
    std::cin >> text;
    std::cout << "Enter Key (Must be 8 alphanumeric characters): ";
    std::cin >> key;
    std::cout << std::endl;

    error_handling();
    text_padding();    
    
    std::cout << "text begins |" << des(text, key, choice == 'd') << "| text ends" << std::endl;
}


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
#include "header.h"

char choice;
std::string text, key;

int main () {
    // user prompts
    std::cout << "< DES Encryption >\nEnter your choice <e to encrypt, d to decrypt>: ";        
    std::cin >> choice;
    std::cout << "Enter Text (No WhiteSpace): ";
    std::cin >> text;
    std::cout << "Enter Key (Must be 8 alphanumeric characters): ";
    std::cin >> key;
    std::cout << std::endl;

    error_handling();
    text_padding();    
    
    std::cout << "text begins |" << des(text, key, choice == 'd') << "| text ends" << std::endl;
}


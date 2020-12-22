#include "header.h"
enum {ENCRYPT, DECRYPT};


int main () {
    char choice;
    std::string text, key;

    std::cout << "< DES Encryption >\nEnter your choice <e to encrypt, d to decrypt>: ";        
    std::cin >> choice;
    std::cout << "Enter Text: ";
    std::cin >> text;
    std::cout << "Enter Key (Must be 8 alphanumeric characters): ";
    std::cin >> key;
    
    if (key.size() != 8 or (choice != 'e' and choice != 'd')) {
        std::cout << "<<< ERROR >>>" << std::endl;
        return 1;
    }
    
    std::cout << std::endl << "text begins |";

    
    
    std::cout << "| text ends" << std::endl;
}
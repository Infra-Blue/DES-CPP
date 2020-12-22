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
    std::cout << std::endl << "text begins |";

    switch (choice) {
        case 'e' : 
            std::cout << des(text, key, ENCRYPT);
            break;
        case 'd' : 
            std::cout << des(text, key, DECRYPT);
            break;
        default :
            std::cout << " <<< Invalid Option >>> ";
    }
    
    std::cout << "| text ends" << std::endl;
}
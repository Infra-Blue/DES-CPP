#include "header.h"

char choice;
string text, key;

int main () {
    // user prompts 
    cout << "< DES Encryption >\nEnter your choice <e to encrypt, d to decrypt>: ";        
    cin >> choice;
    cout << "Enter Text (No WhiteSpace): ";
    cin >> text;
    cout << "Enter Key (Must be 8 alphanumeric characters): ";
    cin >> key;
    cout << endl;

    error_handling();
    text_padding();    
    
    cout << ">>>" << des(text, key, choice == 'd') << "<<<" << endl;
}


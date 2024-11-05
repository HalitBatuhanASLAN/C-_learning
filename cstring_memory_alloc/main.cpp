#include <iostream>
#include "gtuString.h"

int main() {
    GTUString str1("Hello");
    GTUString str2("Worldjjgj");

    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;

    
    str1 += str2;
    std::cout << "Concatenated String: " << str1 << std::endl;

    if (str1 == str2) {
        std::cout << "String 1 is equal to String 2." << std::endl;
    } else {
        std::cout << "String 1 is not equal to String 2." << std::endl;
    }

    std::cout << "Length of String 1: " << str1.len() << std::endl;
    std::cout << "Length of String 2: " << str2.len() << std::endl;

    return 0;
}

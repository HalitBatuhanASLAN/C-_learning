#include <iostream>
#include "StringManager.h" // Include your class header file here

int main() {
    // Testing Default Constructor
    StringManager str1;
    std::cout << "Default Constructor: ";
    str1.print();
    

    // Testing Parameterized Constructor
    StringManager str2("Hello, World!");
    std::cout << "Parameterized Constructor: ";
    str2.print(); // Should print "Hello, World!"

    // Testing Copy Constructor
    StringManager str3 = str2;
    std::cout << "Copy Constructor: ";
    str3.print(); // Should print "Hello, World!"

    // Testing Copy Assignment Operator
    StringManager str4;
    str4 = str2;
    std::cout << "Copy Assignment Operator: ";
    str4.print(); // Should print "Hello, World!"

    // Testing Move Constructor
    StringManager str5 = std::move(str2);
    std::cout << "Move Constructor: ";
    str5.print(); // Should print "Hello, World!"
    std::cout << "After Move Constructor, str2: ";
    str2.print(); // Should print "String is empty!"

    // Testing Move Assignment Operator
    StringManager str6;
    str6 = std::move(str3);
    std::cout << "Move Assignment Operator: ";
    str6.print(); // Should print "Hello, World!"
    std::cout << "After Move Assignment Operator, str3: ";
    str3.print(); // Should print "String is empty!"

    // Destructor will be called automatically for all objects when they go out of scope
    return 0;
}

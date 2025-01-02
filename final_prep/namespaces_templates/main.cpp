#include <iostream>
#include <string>
#include"Container.h" // Include your namespace and class definitions
#include"AdvencedCont.h"
using namespace std;
using namespace MyNamespace;
int main() {
    // Using the namespace
    using namespace MyNamespace;

    // Using the template class
    Container<int> intContainer(42);
    intContainer.display(); // Output: Value: 42

    Container<std::string> stringContainer("Hello, Templates!");
    stringContainer.display(); // Output: Value: Hello, Templates!

    // Using the derived template class
    MyNamespace::AdvancedContainer<double> advancedDoubleContainer(3.14, "Pi value");
    advancedDoubleContainer.display(); // Output: Advanced Container - Value: 3.14, Description: Pi value

    MyNamespace::AdvancedContainer<std::string> advancedStringContainer("C++", "Programming Language");
    advancedStringContainer.display(); // Output: Advanced Container - Value: C++, Description: Programming Language

    return 0;
}
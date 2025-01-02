#ifndef ADVANCEDCONT_H
#define ADVANCEDCONT_H

#include "Container.h" // Include the base class definition
#include <iostream>
#include <string>
#include <typeinfo>

namespace MyNamespace
{ // Ensure the namespace matches the one in Container.h
    template <class T>
    class AdvancedContainer : public MyNamespace::Container<T> {
    public:
        // Constructor
        AdvancedContainer(const T& input, const std::string& desc)
            : MyNamespace::Container<T>(input), description(desc) {}

        // Display method
        void display() const {
            // Use 'this->value' to access the inherited member
            std::cout << "Value is " << this->value
                      << " and its description is " << description << std::endl;
        }

    private:
        std::string description; // Additional member for AdvancedContainer
    };
}

#endif // ADVANCEDCONT_H

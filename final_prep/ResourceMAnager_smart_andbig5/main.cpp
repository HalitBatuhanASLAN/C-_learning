#include"ResourceManager.h"
#include<iostream>

int main() {
    // Create a ResourceManager object
    ResourceManager rm1(5);
    for (size_t i = 0; i < 5; ++i) {
        rm1.setValue(i, i * 10); // Set values
    }

    // Use Copy Constructor
    ResourceManager rm2 = rm1;
    std::cout << "Values in rm2 (copied from rm1): ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << rm2.getValue(i) << " ";
    }
    std::cout << "\n";

    // Use Move Constructor
    ResourceManager rm3 = std::move(rm1);
    std::cout << "Values in rm3 (moved from rm1): ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << rm3.getValue(i) << " ";
    }
    std::cout << "\n";

    // Use Copy Assignment Operator
    ResourceManager rm4(3);
    rm4 = rm2;
    std::cout << "Values in rm4 (assigned from rm2): ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << rm4.getValue(i) << " ";
    }
    std::cout << "\n";

    // Use Move Assignment Operator
    ResourceManager rm5(2);
    rm5 = std::move(rm3);
    std::cout << "Values in rm5 (moved from rm3): ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << rm5.getValue(i) << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
#include <iostream>
#include <memory> // For std::unique_ptr
#include <utility> // For std::move

// ResourceManager Class Definition
class ResourceManager {
private:
    std::unique_ptr<int[]> data; // Smart pointer for dynamic array
    size_t size; // Size of the array

public:
    // Default Constructor
    ResourceManager(size_t n = 0) : size(n), data(n > 0 ? std::make_unique<int[]>(n) : nullptr) {
        std::cout << "Default Constructor called. Size: " << size << "\n";
    }

    // Destructor
    ~ResourceManager() {
        std::cout << "Destructor called. Size: " << size << "\n";
    }

    // Copy Constructor (Deep Copy)
    ResourceManager(const ResourceManager& other) : size(other.size), data(other.size > 0 ? std::make_unique<int[]>(other.size) : nullptr) {
        std::cout << "Copy Constructor called. Size: " << size << "\n";
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy Assignment Operator (Deep Copy)
    ResourceManager& operator=(const ResourceManager& other) {
        std::cout << "Copy Assignment Operator called.\n";
        if (this == &other) return *this; // Self-assignment check

        // Allocate new memory if sizes differ
        if (size != other.size) {
            data = other.size > 0 ? std::make_unique<int[]>(other.size) : nullptr;
            size = other.size;
        }

        // Copy data
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Move Constructor
    ResourceManager(ResourceManager&& other) noexcept : size(other.size), data(std::move(other.data)) {
        std::cout << "Move Constructor called. Size: " << size << "\n";
        other.size = 0; // Reset the moved-from object's size
    }

    // Move Assignment Operator
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        std::cout << "Move Assignment Operator called.\n";
        if (this == &other) return *this; // Self-assignment check

        // Transfer ownership of resources
        data = std::move(other.data);
        size = other.size;

        // Reset the moved-from object
        other.size = 0;

        return *this;
    }

    // Method to set values in the array
    void setValue(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        }
    }

    // Method to get values from the array
    int getValue(size_t index) const {
        if (index < size) {
            return data[index];
        }
        return -1; // Return -1 if index is out of bounds
    }

    // Method to display the contents of the array
    void display() const {
        std::cout << "ResourceManager contents: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

// Main Function
int main() {
    // Create a ResourceManager object
    ResourceManager rm1(5);
    for (size_t i = 0; i < 5; ++i) {
        rm1.setValue(i, i * 10); // Set values
    }

    // Use Copy Constructor
    ResourceManager rm2 = rm1;
    std::cout << "Values in rm2 (copied from rm1): ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << rm2.getValue(i) << " ";
    }
    std::cout << "\n";

    // Use Move Constructor
    ResourceManager rm3 = std::move(rm1);
    std::cout << "Values in rm3 (moved from rm1): ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << rm3.getValue(i) << " ";
    }
    std::cout << "\n";

    // Use Copy Assignment Operator
    ResourceManager rm4(3);
    rm4 = rm2;
    std::cout << "Values in rm4 (assigned from rm2): ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << rm4.getValue(i) << " ";
    }
    std::cout << "\n";

    // Use Move Assignment Operator
    ResourceManager rm5(2);
    rm5 = std::move(rm3);
    std::cout << "Values in rm5 (moved from rm3): ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << rm5.getValue(i) << " ";
    }
    std::cout << "\n";

    return 0;
}
*/
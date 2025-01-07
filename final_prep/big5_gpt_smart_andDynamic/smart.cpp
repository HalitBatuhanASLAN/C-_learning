#include <iostream>
#include <memory> // For smart pointers
#include <string>

class MyClass {
private:
    std::unique_ptr<std::string> data; // Smart pointer to manage a string

public:
    // 1. Default Constructor
    MyClass() : data(std::make_unique<std::string>("Default")) {
        std::cout << "Default Constructor called\n";
    }

    // 2. Parameterized Constructor
    MyClass(const std::string& value) : data(std::make_unique<std::string>(value)) {
        std::cout << "Parameterized Constructor called\n";
    }

    // 3. Destructor
    ~MyClass() {
        std::cout << "Destructor called for: " << *data << "\n";
    }

    // 4. Copy Constructor
    MyClass(const MyClass& other) : data(std::make_unique<std::string>(*other.data)) {
        std::cout << "Copy Constructor called\n";
    }

    // 5. Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        std::cout << "Copy Assignment Operator called\n";
        data = std::make_unique<std::string>(*other.data); // Deep copy
        return *this;
    }

    // 6. Move Constructor
    MyClass(MyClass&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Move Constructor called\n";
    }

    // 7. Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        std::cout << "Move Assignment Operator called\n";
        data = std::move(other.data); // Transfer ownership
        return *this;
    }

    // Getter for data (const method)
    const std::string& getData() const {
        return *data;
    }

    // Setter for data
    void setData(const std::string& value) {
        *data = value;
    }

    // Display method
    void display() const {
        std::cout << "Data: " << *data << "\n";
    }
};

int main() {
    // Using default constructor
    MyClass obj1;
    obj1.display();

    // Using parameterized constructor
    MyClass obj2("Hello, World!");
    obj2.display();

    // Copy constructor
    MyClass obj3 = obj2; // Invokes copy constructor
    obj3.display();

    // Copy assignment operator
    obj1 = obj3; // Invokes copy assignment operator
    obj1.display();

    // Move constructor
    MyClass obj4 = std::move(obj2); // Invokes move constructor
    obj4.display();

    // Move assignment operator
    obj1 = std::move(obj4); // Invokes move assignment operator
    obj1.display();

    return 0;
}

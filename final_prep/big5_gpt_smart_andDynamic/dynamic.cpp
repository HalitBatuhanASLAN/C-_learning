#include <iostream>
#include <string>

class MyClass {
private:
    std::string* data; // Raw pointer to manage a dynamically allocated string

public:
    // 1. Default Constructor
    MyClass() : data(new std::string("Default")) {
        std::cout << "Default Constructor called\n";
    }

    // 2. Parameterized Constructor
    MyClass(const std::string& value) : data(new std::string(value)) {
        std::cout << "Parameterized Constructor called\n";
    }

    // 3. Destructor
    ~MyClass() {
        std::cout << "Destructor called for: " << *data << "\n";
        delete data; // Free the dynamically allocated memory
    }

    // 4. Copy Constructor
    MyClass(const MyClass& other) : data(new std::string(*other.data)) {
        std::cout << "Copy Constructor called\n";
    }

    // 5. Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        std::cout << "Copy Assignment Operator called\n";

        // Free the existing memory
        delete data;

        // Allocate new memory and copy the value
        data = new std::string(*other.data);

        return *this;
    }

    // 6. Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        std::cout << "Move Constructor called\n";
        other.data = nullptr; // Nullify the source pointer to avoid double deletion
    }

    // 7. Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        std::cout << "Move Assignment Operator called\n";

        // Free the existing memory
        delete data;

        // Transfer ownership of the resource
        data = other.data;
        other.data = nullptr; // Nullify the source pointer to avoid double deletion

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

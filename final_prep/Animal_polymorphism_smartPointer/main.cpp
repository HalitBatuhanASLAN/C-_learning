#include"Animal.h"
#include"Dog.h"
#include"Cat.h"
#include<memory>
int main() {
    // Polymorphism with base class pointer
    Animal* animal1 = new Dog("Buddy", 3); // Dog with name and age
    Animal* animal2 = new Cat("Whiskers", 2); // Cat with name and age

    // Call overridden methods (runtime polymorphism)
    animal1->speak(); // Calls Dog's speak()
    animal2->speak(); // Calls Cat's speak()

    // Call additional methods
    animal1->move(); // Calls Dog's move()
    animal2->move(); // Calls Cat's move()

    // Access attributes through base class
    std::cout << animal1->getName() << " is " << animal1->getAge() << " years old." << std::endl;
    std::cout << animal2->getName() << " is " << animal2->getAge() << " years old." << std::endl;

    // Clean up memory
    delete animal1; // Calls Dog destructor, then Animal destructor
    delete animal2; // Calls Cat destructor, then Animal destructor

    std::cout << "---- Using smart pointers ----" << std::endl;

    // Polymorphism with smart pointers
    std::unique_ptr<Animal> animal3 = std::make_unique<Dog>("Max", 5);
    std::unique_ptr<Animal> animal4 = std::make_unique<Cat>("Luna", 1);

    // Call overridden methods
    animal3->speak(); // Calls Dog's speak()
    animal4->speak(); // Calls Cat's speak()

    // Call additional methods
    animal3->move(); // Calls Dog's move()
    animal4->move(); // Calls Cat's move()

    // Access attributes through base class
    std::cout << animal3->getName() << " is " << animal3->getAge() << " years old." << std::endl;
    std::cout << animal4->getName() << " is " << animal4->getAge() << " years old." << std::endl;

    // Smart pointers automatically clean up memory
    return 0;
}
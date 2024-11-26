#include <iostream>
using namespace std;
/*it is normal polymorphism
class Animal
{
    public:
        void soubd(){cout << "Animals has fidderent special sounds\n";}
};

class Dog:public Animal
{
    public:
        void soubd(){cout << "Dogs sounds hav hav\n";}
};

class Cat:public Animal
{
    public:
        void soubd(){cout << "Cats sounds miyav miyav\n";}
};

int main()
{
    Animal a;
    Dog d;
    Cat c;

    c.soubd();
    d.soubd();
    a.soubd();
    return 0;
}*/

/*virtual metods by 2 different usage*/

class Animal
{
    public:
        virtual void soubd() = 0;
};

class Dog:public Animal
{
    public:
        void soubd(){cout << "Dogs sounds hav hav\n";}
};

class Cat:public Animal
{
    public:
        void soubd(){cout << "Cats sounds miyav miyav\n";}
};

void virtual_usage(Animal * a){a->soubd();}
int main()
{
    Animal *a;
    Dog d;
    Cat c;

    a = &d;
    a->soubd();

    a = &c;
    a->soubd();

    virtual_usage(&d);
    virtual_usage(&c);

    return 0;
}






#ifndef Ani_H
#define Ani_H

#include<iostream>
using namespace std;
class Animal
{
    public:
        Animal() = default;
        Animal(string name,int age):name(name),age(age){}
        virtual void speak() = 0;
        virtual void move() = 0;

        const string getName()const;
        const int getAge()const;

        void setName(const string& na);
        void setAge(const int& ag);
    private:
        string name;
        int age;
};

#endif
#ifndef DOG_H
#define DOG_H

#include"Animal.h"
#include<iostream>

class Dog:public Animal
{
    public:
        /*Dog(string na,int ag):Animal()
        {
            setName(na);
            setAge(ag);
        }*/
        Dog(string na,int ag):Animal(na,ag){}
        void speak()override;
        void move()override;
};

#endif
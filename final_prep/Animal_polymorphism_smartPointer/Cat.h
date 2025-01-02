#ifndef CAT_H
#define CAT_H

#include"Animal.h"
#include<iostream>

class Cat:public Animal
{
    public:
        Cat(string na,int ag):Animal()
        {
            setName(na);
            setAge(ag);
        }
        void speak()override;
        void move()override;
};

#endif
#include"Animal.h"
#include<iostream>

const string Animal::getName()const{return name;}
const int Animal::getAge()const{return age;}

void Animal::setName(const string& na){name = na;}
void Animal::setAge(const int& ag){age = ag;}
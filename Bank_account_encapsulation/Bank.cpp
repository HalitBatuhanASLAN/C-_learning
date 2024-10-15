#include <iostream>
#include <string>
using namespace std;

#include "bank.h"

void Bank::set_money(string password,double new_money)
{
    if(password != password_to_set)
        cerr << "You pasword is wrong you can not set your money and debt.\n";
    else
        money = new_money;
}

void Bank::set_debt(string password,double new_debt)
{
    if(password != password_to_set)
        cerr << "You pasword is wrong you can not set your money and debt.\n";
    else
        debt = new_debt;
}

double Bank::get_money(int password)
{
    if(password != password_to_get)
        cerr << "You pasword is wrong you can not get your money and pay your debt.\n";
    else
        return money;
}

double Bank::get_debt(int password)
{
    if(password != password_to_get)
        cerr << "You pasword is wrong you can not get your money and pay your debt.\n";
    else
        return debt;
}

Bank::Bank(string input_name)
{
    name = input_name;
    cout << "Object created\n";
}


Bank::~Bank()
{
    cout << "Object is deleted\n";
}


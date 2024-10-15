#ifndef BANK_HEADER
#define BANK_HEADER

#include <string>
#include <iostream>
using namespace std;

const string password_to_set = "example987654321";
const int password_to_get = 9999;
class Bank
{
    public:
        Bank(string name);
        void set_money(string password,double new_money);
        double get_money(int password);

        void set_debt(string password,double new_money);
        double get_debt(int password);

        ~Bank();
    private:
        string name;
        double money;
        double debt;
};


#endif // BANK_HEADER

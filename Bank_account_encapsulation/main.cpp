#include <iostream>
#include "bank.h"

using namespace std;

int main()
{
    Bank HBA_account("Halit");

    HBA_account.set_debt("example987654321",12500);
    cout << "Your debt is " << HBA_account.get_debt(9999);
    cout << endl;

    HBA_account.set_money("example987654321",35000.500);
    cout << "Your money is " << HBA_account.get_money(9999);
    cout << endl;

    
    return 0;
}

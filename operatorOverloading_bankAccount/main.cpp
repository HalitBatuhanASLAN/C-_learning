#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
    public:
        BankAccount(string in_name, int in_amount);
        BankAccount():name("deafult name"),amount(0){}

        string getOwner() const;
        int getAmount() const;
        void setOwner(string new_name);
        void setAmount(int new_money);

        void deposit(int adding_money);
        void withdraw(int taking_money);

        friend ostream& operator<<(ostream& out,const BankAccount& acc);
        bool operator==(BankAccount& acc)const;
        BankAccount operator+(int adding_money);
        BankAccount operator-(int taking_money);
    private:
        string name;
        int amount;
};

BankAccount::BankAccount(string in_name, int in_amount):name(in_name),amount(in_amount){}

string BankAccount::getOwner()const {return name;}
int BankAccount::getAmount()const {return amount;}
void BankAccount::setOwner(string new_name) {name = new_name;}
void BankAccount::setAmount(int new_money) {amount = new_money;}

void BankAccount::deposit(int new_money){amount += new_money;}
void BankAccount::withdraw(int taking_money){amount -= taking_money;}

ostream& operator<<(ostream& out,BankAccount& acc)
{
    out << acc.getAmount();
    return out;
}
bool BankAccount::operator==(BankAccount& acc)const
{
    return (getAmount() == acc.getAmount()); 
}
BankAccount BankAccount::operator+(int adding_money)
{
    BankAccount acc;
    acc.setAmount(getAmount() + adding_money);
    return acc;
}
BankAccount BankAccount::operator-(int taking_money)
{
    BankAccount acc;
    acc.setAmount(getAmount() - taking_money);
    return acc;
}



int main() {

    BankAccount account1("Alice", 1000);
    BankAccount account2("Bob", 500);

    cout << "Initial Balances:" << endl;
    cout << "Account 1 (" << account1.getOwner() << "): " << account1 << endl;
    cout << "Account 2 (" << account2.getOwner() << "): " << account2 << endl;

    account1.deposit(300);
    cout << "After depositing $300 to Account 1: " << account1 << endl;

    account2.withdraw(200);
    cout << "After withdrawing $200 from Account 2: " << account2 << endl;

    account2 = account2 + 200;
    account1 = account1 - 200;
    cout << "After transferring $200 from Account 1 to Account 2:" << endl;
    cout << "Account 1: " << account1 << endl;
    cout << "Account 2: " << account2 << endl;  
    if (account1 == account2) {
        cout << "Both accounts have the same balance." << endl;
    } else {
        cout << "The accounts have different balances." << endl;
    }
    account1.setOwner("Alice Cooper");
    cout << "Account 1 new owner: " << account1.getOwner() << endl;

    return 0;
}

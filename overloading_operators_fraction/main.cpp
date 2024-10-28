#include <iostream>

using namespace std;

class Fraction
{
    public:
        Fraction(){}
        Fraction(int num,int denom);

        void setNumerator(int num);
        void setDenominator(int denom);

        int getNumerator() const{return numerator;}
        int getDenominator() const{return denominator;}

        Fraction operator+(const Fraction& f1);
        bool operator==(Fraction& f1)const;
        friend ostream& operator<<(decltype(cout)& out,const Fraction& f1);
    private:
        int numerator,denominator;
};

Fraction::Fraction(int num,int denom):numerator(num), denominator(denom){};
void Fraction::setNumerator(int num)
{
    numerator = num;
}
void Fraction::setDenominator(int denom)
{
    denominator = denom;
}

Fraction Fraction::operator+(const Fraction& f1)
{
    Fraction result(f1.getDenominator()*getNumerator() + f1.getNumerator()*getDenominator(),
                    f1.getDenominator()*getDenominator());
    return result;
}
bool Fraction::operator==(Fraction& f1)const
{
    return (f1.getDenominator()*getNumerator() == f1.getNumerator()*getDenominator());
}
ostream& operator<<(decltype(cout)& out,const Fraction& f1)
{
    out << f1.getNumerator() << "/" << f1.getDenominator();
    return out;
}

int main() {
    Fraction f1(3, 4);
    Fraction f2(5, 6);

    Fraction result = f1 + f2;
    cout << "f1 + f2 = " << result << endl;
    
    f1.setNumerator(7);
    f1.setDenominator(8);
    cout << "New f1: " << f1 << endl;
    
    if (f1 == f2) {
        cout << "f1 and f2 are equal." << endl;
    } else {
        cout << "f1 and f2 are not equal." << endl;
    }

    return 0;
}



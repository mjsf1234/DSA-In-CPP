#include <iostream>
using namespace std;
class Fraction
{
private:
    int denominator;
    int nemerator;

public:
    //constructor
    Fraction(int nemerator, int denominator)
    {
        this->nemerator = nemerator;
        this->denominator = denominator;
    }

    void Print() const
    {
        cout << this->nemerator << "/" << this->denominator << endl;
    }
    void simplyfy()
    {
        //

        int gcd = 1;
        int n = min(this->nemerator, this->denominator);
        //

        for (int i = 1; i < n + 1; i++)
        {
            if ((this->nemerator % i == 0) && (this->denominator % i == 0))
            {
                gcd = i;
            }
        }

        this->nemerator = this->nemerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    // + operator overloading
    Fraction operator+(Fraction const &f2) const
    {
        int lcm = this->denominator * f2.denominator;
        int num = this->nemerator * f2.denominator + this->denominator * f2.nemerator;
        Fraction newFrac(num, lcm);
        newFrac.simplyfy();
        return newFrac;
    }
    void multiply(Fraction const &f2)
    {
        this->nemerator = this->nemerator * f2.nemerator;
        this->denominator = this->denominator * f2.denominator;
        this->simplyfy();
    }

    //Same above function with operator(*) overloading
    Fraction operator*(Fraction const &f2) const
    {
        int num = this->nemerator * f2.nemerator;
        int den = this->denominator * f2.denominator;
        Fraction newFrac(num, den);
        newFrac.simplyfy();
        return newFrac;
    }

    // double equal operator overloading
    bool operator==(Fraction const &f) const
    {
        Fraction f1(*this);

        Fraction f2(f);
        f1.simplyfy();
        f2.simplyfy();
        return (f1.nemerator == f2.nemerator && f1.denominator == f2.denominator);
    }
    // ++f ->  pre-increament operator overloading
    Fraction &operator++()
    {
        //this line is for checking the address of object
        cout << "address: " << this << endl;
        cout << "operator called : "
             << "Numerator: " << this->nemerator << " denominator: " << this->denominator << endl;
        ///////////////////////////////////////////////////

        this->nemerator = this->nemerator + this->denominator;
        simplyfy();
        return *this;
    }

    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = this->denominator * f2.denominator;
        int num = this->nemerator * f2.denominator + this->denominator * f2.nemerator;
        this->nemerator = num;
        this->denominator = lcm;
        simplyfy();
        return *this;
    }
};
int main()
{
    Fraction f1(4, 3);
    Fraction f2(5, 6);
    // Fraction f3 = f1 + f2; // f1->(this) and f2 ->(arguement)
    // Fraction f4 = f1 * f2;
    // Fraction f5 = ++(++f1);
    Fraction f6 = (f1 += f2) += f2;
    // f1.Print();
    // f2.Print();
    // f3.Print();
    // f4.Print();
    f6.Print();
    // cout << (f1 == f2);

    return 0;
}
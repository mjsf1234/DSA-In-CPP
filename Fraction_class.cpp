#include <iostream>
using namespace std;
class Fraction
{
private:
    int denominator;
    int nemerator;

public:
    Fraction(int nemerator, int denominator)
    {
        this->nemerator = nemerator;
        this->denominator = denominator;
    }

    void Print()
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
    void add(Fraction const &f2)
    {
        int lcm = this->denominator * f2.denominator;
        int num = this->nemerator * f2.denominator + this->denominator * f2.nemerator;
        this->nemerator = num;
        this->denominator = lcm;

        this->simplyfy();
    }
    void multiply(Fraction const &f2)
    {
        this->nemerator = this->nemerator * f2.nemerator;
        this->denominator = this->denominator * f2.denominator;
        this->simplyfy();
    }
};
#include <iostream>
using namespace std;
class ComplexNumbers
{

private:
    int real;
    int img;

public:
    ComplexNumbers(int a, int b)
    {
        this->real = a;
        this->img = b;
    }
    void print()
    {
        cout << this->real << "+i" << this->img << endl;
    }

    void plus(ComplexNumbers const &c2)
    {
        this->img = this->img + c2.img;
        this->real = this->real + c2.real;
    }
    void multiply(ComplexNumbers const &c2)
    {
        int r = this->real;
        this->real = this->real * c2.real - this->img * c2.img;
        this->img = r * c2.img + this->img * c2.real;
        cout << this->img << endl;
    }
};
#include <iostream>
using namespace std;
// #include "Fraction_class.cpp"
#include "Complex.cpp"
int main()
{
    ComplexNumbers c1(3, 6);
    ComplexNumbers c2(7, 9);
    c1.multiply(c2);
    // c1.print();

    return 0;
}
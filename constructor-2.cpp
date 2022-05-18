#include <iostream>
using namespace std;
#include "Student.cpp"
int main()
{
    Student s1;           //constructor 1
    Student s2(10, 1001); //constructor 3
    Student s3(s2);       //copy constructor
    Student s4 = s3;      // => Student s4(s3)  //copy constructor
    s4.Get();

    return 0;
}
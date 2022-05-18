#include <iostream>
using namespace std;
#include "Student.cpp"

int main()
{

    // Copy constructor
    Student s1(10, 1001);
    s1.Get();

    Student s2(s1); //Copy constructor is called
    s2.Get();
    // ____________________________________________________________________________
    // Copy assignment
    Student s3(30, 3001);
    Student s4(40, 4001);
    Student *s5 = new Student(50, 5001);
    s4.Get();
    s5->Get();
    s4 = s3;  //copy assignment operator
    *s5 = s3; //copy assignment operator on dynamically created object
    s5->Get();
    s4.Get();
    Student s6(*s5);
    cout << "the value of s6 ";
    s6.Get();
    delete s5;
    // _______________________________________________________

    return 0;
}
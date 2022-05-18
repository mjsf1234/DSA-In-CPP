#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    int const rollNumber;
    int &x;

public:
    void show()
    {
        cout << "age: " << this->age << ", rollnumber : " << this->rollNumber << endl;
    }
    Student(int age, int r) : rollNumber(r), age(age), x(this->age) // initialisation list
    {
        this->age = age;
    }
};
int main()
{
    Student s1(10, 101);
    s1.show();

    return 0;
}
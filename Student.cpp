#include <iostream>
using namespace std;
class Student
{
public:
    int rn;

private:
    int age;

public:
    void Get()
    {
        cout << "age: " << age << " rollnumber: " << rn << endl;
    }
    void set(int n, int m)
    {
        age = n;
        rn = m;
    }
    //Constructor with no arguement
    Student()
    {
        cout << "constructor 1  " << endl;
    }

    //Constructor with two arguement
    Student(int a, int b)
    {
        cout << "constructor 3" << endl;
        this->age = a; // => (*object).age = a;
        this->rn = b;  // => (*object).rn = b;
    }

    //Destructor
    ~Student()
    {
        cout << "Destructor Called!!" << endl;
    }
};

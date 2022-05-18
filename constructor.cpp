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
        cout << "constructor called  " << endl;
    }

    //Constructor with two arguement
    Student(int a, int b)
    {
        cout << "this is a parameterize constructor" << endl;
        this->age = a; // => (*object).age = a;
        this->rn = b;  // => (*object).rn = b;
    }
};

int main()
{
    // Student s1; //default constructor called
    // s1.Get();
    // s1.set(20, 101);
    // s1.Get();
    // Student s4(10, 101); // second constructor is called with inital values
    // s4.Get();
    // s4.set(30, 201); //update the value of object with the set function
    // s4.Get();

    //dynamically
    Student *s3 = new Student;
    (*s3).Get();
    (*s3).set(40, 301);
    (*s3).Get();

    Student *s4 = new Student(50, 401);
    s4->Get();
    return 0;
}
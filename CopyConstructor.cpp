#include <iostream>
using namespace std;
#include <cstring>

class Student
{
private:
    int age;
    // // Private copy constructor => no one can create the copy of your objects

    // Student(Student const &s) //arguement is pass by reference to avoid the infinite loop of calling copy constructor
    // {
    //     cout << "copy constructor called" << endl;
    //     this->age = s.age;
    //     this->name = new char[strlen(s.name) + 1];
    //     strcpy(this->name, s.name);
    // }

public:
    char *name;

    Student(int age, char *name)
    {
        this->age = age;
        this->name = name;
    };

    void show()
    {
        cout << "age: " << this->age << ", name : " << this->name << endl;
    }
    //copy constructor
    Student(Student const &s) //arguement is pass by reference to avoid the infinite loop of calling copy constructor
    {
        cout << "copy constructor called" << endl;
        this->age = s.age;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }
};

int main()
{
    char name[] = "abcd";
    Student s1(10, name);
    s1.show();

    Student s2(s1); //copy constructor called
    name[0] = 'z';
    s2.show();
    s1.show();

    return 0;
}
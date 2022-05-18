#include <iostream>
using namespace std;

class Student
{
public:
    int rn;

private:
    int age;

public:
    void display()
    {
        cout << age << " " << rn << endl;
        ;
    }

    void setAge(int n)
    {
        age = n;
    }
};

int main()
{
    Student s1;
    Student *s2 = new Student;
    // s1.age = 21;
    s1.rn = 103;
    s1.setAge(30);
    cout << "the details of s1 is : " << endl;
    s1.display();

    s2->rn = 101;
    // s2->age = 22;

    // (*s2).display();
    s2->display();

    return 0;
}
#include <iostream>
using namespace std;

//constructor class
class Student
{
public:
    int rollNumber;
    int age;
};

int main()
{

    //creating the object statically
    Student s1;
    Student s2, s3, s4;

    //creating the object dynamically => (type of variable * Name of the variable = new type of Memory needed)
    Student *s5 = new Student;

    //setting the value of object
    s1.age = 26;
    s1.rollNumber = 101;

    //setting the value of dynamically created  object
    (*s5).age = 20;
    s5->rollNumber = 103; // another syntax to write =>(*s5).rollNumber

    cout << s1.age << " " << (*s5).age << " " << s5->age;

    return 0;
}
#include <iostream>
using namespace std;
class Student
{
private:
    static int totalStudent; //belong to class , object don't get the copy of static variable

public:
    int rn;
    int age;

    // constructor with two arguement
    Student(int age, int rn)
    {
        this->age = age;
        this->rn = rn;
        totalStudent++;
    }

    //creating own copy constructor
    Student(Student const &s)
    {
        this->age = s.age;
        this->rn = s.rn;
    }
    static int showTotalStudents() //static function
    {
        return totalStudent; //static function has access to static properties of class only
    }
};
int Student ::totalStudent = 0; //inititalise static member outside the class

int main()
{
    Student s1(10, 101);
    Student s2(20, 201);
    cout << Student::showTotalStudents() << endl;

    return 0;
}
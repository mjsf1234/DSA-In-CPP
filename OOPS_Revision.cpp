#include <iostream>
using namespace std;

// decalring the class Student type;
class Student{
    // access modifier => private
    private:
    int name;
    int rn;
    int age;
    // access modifier => private
    public:
    // functions to access the private variables
    int getRn(){
        return rn;
    }
    int getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    //default constructor
    Student(){
        cout<<"default constructor is called "<<endl;
    }

    // constructor
    Student(int name, int rn){
        // this store the address of the Object to whome constructor is called
        this->name = name; 
        this->rn =rn;
    }
    // copy constructor


    
};

int main() { 
    Student s1;
    Student s2;
    Student *s3 = new Student; 
    return 0;
}
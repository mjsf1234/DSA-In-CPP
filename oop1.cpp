#include <iostream>
using namespace std;

class box{
    public:
        double length;
        double breadth;
        double height;

        double getVolumn(void);
        
       



};

int box::getVolumn(void) {
   return length*breadth*height;


int main() { 

    // box box1;
    // box box2;
    // box1.length = 1;
    // box1.height = 2;
    // box1.breadth = 3;

    // box2.length = 2;
    // box2.height = 3;
    // box2.breadth = 4;
    // cout <<"the volume of box1 is "<<box1.getVolumn()<<endl;
    // cout <<"the volume of box2 is "<<box2.getVolumn()<<endl;

    
    return 0;
}
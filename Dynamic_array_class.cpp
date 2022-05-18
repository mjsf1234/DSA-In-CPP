#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    // default is private
    int capacity;
    int *data;
    int nextIndex;

public:
    // constructor
    StackUsingArray()
    {
        data = new int[4]; // arbitary number
        capacity = 4;      // arbitary number
        nextIndex = 0;
    }

    //  push function for pushing the data into the stack
    void push(int number)
    {

        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity = 2 * capacity;
            delete[] data;
            data

                = newData;

            // cout << "stack is full" << endl;
            // return;
        }
        data[nextIndex] = number;
        nextIndex++;
    }
    // checking the size of the stack
    bool isEmpty()
    {
        return (nextIndex == 0);
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return (data[nextIndex]);
    }

    int size()
    {
        return nextIndex;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

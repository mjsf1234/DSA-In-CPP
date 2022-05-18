template <typename T>
class QueueUsingArray
{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int number)
    {
        data = new T[number];
        nextIndex = 0;
        firstIndex = -1;
        capacity = number;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    // inserting the element

    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
            }

            delete[] data;
            data = newData;
            nextIndex = capacity;
            capacity = 2 * capacity;
        }
        data[nextIndex] = element;
        size++;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    T front()
    {
        if (size == 0)
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }
};
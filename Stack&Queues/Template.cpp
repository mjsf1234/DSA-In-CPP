#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {

        this->x = x;
    }
    void setY(V y)
    {

        this->y = y;
    }
    V getY()
    {
        return y;
    }
    T getX()
    {
        return x;
    }
};

int main()
{
    // Pair<int, int> p1;
    // p1.setX(3);
    // p1.setY(4);
    // cout << p1.getX() << " " << p1.getY() << endl;

    // for generating the triplet using the double class

    Pair<Pair<int, int>, int> p2;
    p2.setY(30);
    Pair<int, int> p3;
    p3.setX(10);
    p3.setY(20);
    p2.setX(p3);

    cout << p2.getX().getX();

    return 0;
}
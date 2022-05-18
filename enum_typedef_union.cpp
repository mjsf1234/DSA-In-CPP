#include <iostream>

using namespace std;
int main() { 
    enum meal {breakfast, lunch =6, dinner}a ;
    a = breakfast;
    cout<<a;
    return 0;
}  
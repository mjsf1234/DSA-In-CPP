#include <iostream>
using namespace std; 

int main() { 
    cout <<"type the number"<<endl;
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i =0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
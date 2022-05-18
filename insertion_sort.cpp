#include <iostream>
using namespace std; 

void insertionSort( int arr[] , int n ){

    for (int i =1; i<n; i++){        
        int current = arr[i];
        int j;
        for (j = i-1; j>=0; j--){
            if (current<arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = current;
    }
}
int main() { 
    int arr[] = {10,5,3,15,4};
    int n = 5;
    insertionSort(arr, n);
    for (int i = 0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
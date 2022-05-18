#include <iostream>
using namespace std;


int binary_search(int arr[] , int size , int val ){

    int start =0 , end = size-1;

    while(start<=end){
        int mid = (start+end)/2;

        if (arr[mid] ==val){
            return mid ;

        }

        else if (arr[mid]> val){
            end = mid -1 ; 
        }

        else{
            start = mid +1 ;
        }
    }
    return -1;
}


int main() { 
    int size = 7;
    int arr[] = {1, 3, 7, 9, 11, 12, 45} ;
    int val1 = 7;
    int val2 = 9;
    int val3= 43;
    cout<<("the value   ")<<val1<<(" is at index: ")<<binary_search( arr , size , val1)<<endl;
    cout<<("the value of ")<<val2<<(" is at index: ")<<binary_search( arr , size , val2)<<endl;
    cout<<("the value of ")<<val3<<(" is at index: ")<<binary_search( arr , size , val3)<<endl;
    return 0;
}
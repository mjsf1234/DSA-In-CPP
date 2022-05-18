#include <iostream>

using namespace std;


void swap(int x , int y){
    int temp  = x ;
    x = y;
    y =temp; 
}

// swaping the variables using pointers

void swap_pointer (int* x , int* y){                   //int* x , int* y ---> these variable store the address
    int temp = *x; 
    *x = *y;
    *y = temp;
}

// swaping using refernce varibles;

void swap_reference (int &x, int &y){  // &x , &y ---> point towards the actual parameter(arguement) therefore changing the formal parameter will chng actual values
    int temp = x;
    x = y;
    y =temp;   
}



int main() { 
    int a =4 , b =5; 
    cout<<"the value of a is "<<a<<" ,the value of b is "<<b<<endl;
    swap(a ,b);
    cout<<"the value of a is "<<a<<" ,the value of b is "<<b<<endl;
    cout <<"_____________________________________________________"<<endl;
    swap_pointer(&a,&b);                                                       // here &a --> will give address of a, &b will give the address of b, then function will swap the values at address. 
    cout<<"the value of a is "<<a<<" ,the value of b is "<<b<<endl;
    cout <<"_____________________________________________________"<<endl;
    swap_reference(a ,b);                                                      // here &x ---> a , &y---->b, therfore changing x,y will chng actual parameter (a ,b)
    cout<<"the value of a is "<<a<<" ,the value of b is "<<b<<endl;
    


    
    return 0;
}
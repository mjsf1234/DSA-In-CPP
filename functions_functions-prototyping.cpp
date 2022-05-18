#include <iostream>

using namespace std;

// defining the sum function
int sum (int a, int b){
    int result;
    result = a +b; 
    return result;
}

// defining the max function
int max (int a , int b){
    if (a>b){
        return a;
    }

    else{
        return b; 
    }
}

// proto-typing the greet function

void greet(void);


int main() { 
    int num1 ,num2 ; 
    cout << "type the first number " <<endl;
    cin>>num1;
    cout << "type the second number " <<endl;
    cin>>num2;

    cout<<"the sum of the numebers is "<< sum(num1 ,num2)<<endl;
    cout<<"the max of the number is  "<< max (num1 ,num2)<<endl;
    greet();

    return 0;
}
void greet (){
    cout<<"hello, good morning";
}






#include <iostream>

using namespace std;

int gcd(int a ,int b){
    int smaller;
    if ( a >= b ){
        int smaller =b;
    }
    else{
        int smaller = a;

    }
    int g =1;
    for (int i ; i<= smaller; i++ ){
        if (((a%i)==0)&&((b%i)==0)){
            int g = i;
        }
    return g ;
    
    }
}

int main() { 
    int a,b;
    cout<<"enter the first number: "<<endl;
    cin>>a;
    cout<<"enter the second number: "<<endl;
    cin>>b;
    cout<<"the gcd is "<<gcd(a,b)<<endl;
    
    return 0;
}
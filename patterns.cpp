#include <iostream>

using namespace std;
int main() { 
    cout<<"enter"<<endl;
    int N;
    cin>>N;
    
    int i =1;
    
    while(i<=N){
        int c =1;
        int j =i;
        while(c<=i){
            cout <<j;
            j+=1;
            c+=1;
        }
        cout<<endl;
        i+=1;    
    }


  
    return 0;
}
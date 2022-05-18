#include <iostream>
#include <string>

using namespace std;
int main() {
    cout <<"type the string: "<<endl;
    string c;
    cin>>c;
    int ce =0;
    int co =0;
    int l = c.length();
    int i =0;
    while (i<l){
        int a  = c[i] - '0';
        if ((a%2)==0){
            ce = ce + a;
        }
        else{
            co= co+a;
        }
        i=i+1;
    }
    cout <<ce<<" "<<co;

    
}
#include <iostream>
using namespace std; 

void merge(int arr1[], int size1, int arr2[], int size2, int ans[])
{
    
    int n1 = size1;
    int n2 =size2;
    int n3 = n1 + n2;
    
    int i=0;
    int j=0;
    int k =0;
    
    while ( i < n1 && j<n2){
        
        if (arr1[i] <arr2[j]){
            ans[k] = arr1[i];
            k++;
            i++;
        }
        
        else if( arr1[i] ==arr2[j]){
          ans[k] =arr1[i];
          k++;
          i++;
          
          }
        
        else{
            ans[k] = arr2[j];
            k++;
            j++;
        }       
        
    } 
    
    while(i<n1) {
        
        ans[k] = arr1[i];
        i++;
        k++;
    }
        
    while(j<n2) {
        
        ans[k] = arr2[j];
        j++;
        k++;
    }
}
int main() { 
    int arr1[] = {1, 3 ,6 ,11 ,12 ,17  };
    int arr2[] = {2, 8 ,12, 16, 19,  };
    int ans[11] = {0,0,0,0,0,0};
    int n1 = 6;
    int n2 = 5;
    
    merge(arr1,  n1, arr2,  n2,  ans);
    for (int i = 0; i<11 ; i++){
        cout<<ans[i]<<" ";  
    }
    
    return 0;
}
#include <iostream>
using namespace std;


void insert(int a[],int n){
    for(int i=0;i<n-1;i++){     // i<n,j<n; i<n-1,j<n-1 is also work but it is not efficient 
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){      // we can also use swap(a[j],a[j+1])
                int temp=a[j];         
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

    int main(){
        int n;
        cout<<"Enter n:";
        cin>>n;

        int a[100];
        cout<<"Enter the array elements:";
        for(int i=0;i<n;i++){
            cin>>a[i];
}


        insert(a,n);
        cout<<"Sorted array:";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        return 0;
    }
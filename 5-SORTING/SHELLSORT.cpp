//SHELL SORT 

#include <iostream>
using namespace std;

void insert(int a[],int n){
    int gap=n/2;
    while(gap){
    for(int i=gap;i<n;i++){
        int key=a[i];
            int j=i-gap;
        while(j>=0 && a[j]>key){
            a[j+gap]=a[j];
            j=j-gap;
        }
        a[j+gap]=key;
        
    }
    gap=gap/2;
}
  
}


int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;

    int arr[100];
    cout<<"Enter the array elements :";
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
   insert(arr,n);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   return 0;
}
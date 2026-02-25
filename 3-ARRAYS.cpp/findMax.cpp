//<---- Maximum Value in an Array---->
#include <iostream>
using namespace std;

// Iterative approach :
int findMax(int arr[],int n ){
     int maxValue=arr[0];

     for(int i=1;i<n;i++){
        if(arr[i]>maxValue){
            maxValue=arr[i];
        }
     }

     return maxValue;
}

// Recursive approach :
int RfindMax(int arr[],int n){
    if(n==1){
        return arr[0];
    }

    int maxValue=RfindMax(arr,n-1);

    return(arr[n-1] > maxValue) ? arr[n-1] : maxValue;

}

// Using while loop:
int lfindMax(int arr[],int n){
    int i=1;
    int maxValue=arr[0];

    while(i<n){
      if(arr[i]>maxValue){
         maxValue=arr[i];
         i++;
      }
    }
    return maxValue;
}

// Using sort :
void sort(int arr[],int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}


int main(){
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the array "<<i+1<<":"<<endl;
        cin>>arr[i];
    }

    cout<<"Array values"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n"<<endl;

    int value=lfindMax(arr,n);
    cout<<"Max Value : "<<value<<endl;


    sort(arr,n);
    cout<<"Max Value (using sort) "<<arr[n-1]<<endl;
   


return 0;
}
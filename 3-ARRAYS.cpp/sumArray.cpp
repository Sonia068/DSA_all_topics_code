//<---- Sum of Array elements---->
#include <iostream>
using namespace std;

// Iterative approach :
int sumArray(int arr[],int n ){
    int sum=0;
     for(int i=0;i<n;i++){
        sum+=arr[i];
     }
   return sum;
}

// Recursive Approach :

int RsumArray(int arr[], int n) {
    if(n == 0)
        return 0;

    return arr[n-1] + sumArray(arr, n-1);
}

// do -While:

int sum2(int arr[],int n){
    int i = 0;
    int sum=0;
    do {
        sum += arr[i];
        i++;
    } while(i < n);

    return sum;
}

// also used while loop:



int main(){
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the array "<<i+1<<":"<<endl;
        cin>>arr[i];
    }

    cout<<"Array values: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n"<<endl;

    int value=RsumArray(arr,n);
    cout<<"Max Value : "<<value<<endl;

    cout<<"\n"<<endl;
   
    int value2=sum2(arr,n);
    cout<<"Max Value : "<<value2<<endl;

return 0;
}
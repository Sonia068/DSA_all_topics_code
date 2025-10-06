// Array Sorting using Bubble Sort :(Without using swap function )
#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
        }
    }
}
}

    

int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the value"<<i+1<<":";
        cin>>arr[i];
    }

    cout<<"\n";

    cout<<"Before Sorting :"<<endl;
     for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}


    for(int i=0;i<n;i++){
        bubbleSort(arr,n);
}

cout<<"\n";
cout<<"After Sorting :"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}


return 0;
}


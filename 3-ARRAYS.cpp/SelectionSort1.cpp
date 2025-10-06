// Array Sorting using Selection Sort:(Swapping method)

#include <iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
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



        selectionSort(arr,n);


cout<<"\n";
cout<<"After Sorting :"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}


return 0;
}


//BUBBLE SORT

#include <iostream>
 using namespace std;

 void bubble_sort(int arr[],int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
     if(arr[j]>arr[j+1]){
      int temp=arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp;
    }
  }
}
 }

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
 


    int main(){
        int n;
        cout<<"Enter the size of the array:";
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<"Before bubble sort:"<<endl;
        display(arr,n);

        bubble_sort(arr,n);
        cout<<"\n After bubble sort:"<< endl;
        display(arr,n);

    }
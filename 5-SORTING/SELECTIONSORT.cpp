// SELECTION SORT :
#include <iostream>
 using namespace std;

 
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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

        cout<<"Before selection sort:"<<endl;
        display(arr,n);

        selection_sort(arr,n);
        cout<<"\n After selection sort:"<< endl;
        display(arr,n);

    }

    
    
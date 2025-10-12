#include <iostream>
using namespace std;


void merge(int a[],int l,int m,int r){
int n1=(m-l)+1;              //size of left subarray
int n2=r-(m+1)+1; //r-m       //size of right subarray

//copy the elements in temp ;
int left[n1],right[n2];
for(int i=0;i<n1;i++)
left[i]=a[l+i];

for(int j=0;j<n2;j++)
right[j]=a[m+1+j];

int i=0,j=0,k=l;   // initial indices
 // merge the arrays back into array
 while(i<n1  && j<n2){
 if (left[i] <= right[j]) {
   a[k]=left[i];
   i++;
   }
   else{
   a[k]=right[j];
   j++;
   }
   
   k++;
   }
   
   // Copy remaining elements of left subarray:
   while(i<n1){
   a[k]=left[i];
   i++;
   k++;
   }
   
     // Copy remaining elements of right subarray:
     while(j<n2){
     a[k]=right[j];
       j++;
       k++;
       }
       }
   
   

void mergeSort(int a[],int l,int r){
if(l<r){
int m=l+(r-l)/2;     // to calculate  the mid

mergeSort (a,l,m);       // Sort first half
mergeSort (a,m+1,r);

merge(a,l,m,r) ;    //merge the two halves
}
}



int main(){
int n;
cout<<"Enter the size of the array:";
cin>>n;

int a[100];
cout<<"Enter the array elements:";
for(int i=0;i<n;i++){
cin>>a[i];
}
 cout << endl;


mergeSort(a,0,n-1);
cout<<"Sorted array:";
for(int i=0;i<n;i++){
cout<<a[i]<<" ";
}
cout << endl;

return 0;
}

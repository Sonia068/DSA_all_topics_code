//   QUICK SORT :
#include <iostream>
using namespace std;

void quicksort(int a[],int f,int l){
if(f<l){
    int pivot=a[f],i,j,temp;
    i=f+1;
    j=l;

    while(i<=j){
         while(i<=l && a[i]<pivot)  i++;
         while(j>=f && a[j]>pivot)  j--;

         if(i<j){
            temp=a[i];           //swap()
            a[i]=a[j];
            a[j]=temp;
    
            i++;
            j--;
         }
        }
            a[f] = a[j];   
            a[j] = pivot; 

            quicksort( a,f, j-1);
            quicksort(a,j+1, l);
    }
}

        

int main(){
    int n;
    cout<<"Enter the number of products:";
    cin>>n;

    int a[100];
    cout<<"Enter the products price :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Price of Product "<< i+1 <<" : ";
        cin>>a[i];
    }

    cout<<endl;

    int f=0;
    int l=n-1;

    quicksort(a,f,l);

    cout<<"After Sorting:"<<endl;
    for(int i=0;i<n;i++){
    cout<<"Price of Product "<< i+1 <<" : ";
    cout<<a[i]<<endl;
    }

    return 0;


}
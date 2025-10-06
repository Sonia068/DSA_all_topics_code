// Simple Queue (using Array)

#include<iostream>
using namespace std;
#define size 5

class qu{
    int rear;
    int front;
    int arr[size];

    public:
    qu(){
        rear=-1;
        front=-1;
    }

    qu(int val){
        rear=val;
        front=-1;
    }

    void enqueue(int val){
        if(rear==size-1){
            cout<<"Queue is full.Can't insert"<<endl;
        }
    
        else{
            rear++;
            arr[rear]=val;
        }
    }

    void dequeue(){
        if(rear==-1){
            cout<<"Queue is Empty.Can't delete"<<endl;
        }

        else{
            front++;
            int val=arr[front];
        }
    }


    void print(){
        if(rear==-1){
            cout<<"queue is empty"<<endl;
        }
        else{
            front++;
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }
    }

};


int main(){
    qu s;
    for(int i=0;i<size;i++){
         int v;
         cout<<"Enter the value:";
         cin>>v;
         s.enqueue(v);
    }

    cout<<"Queue after insertion :"<<endl;
    s.print();
    cout<<"\n";

    int n;
    cout<<" How many numbers you want to delete?" << endl;
    cin>>n;
  
    for(int i=0;i<n-1;i++){
        s.dequeue();
}

 cout<<"Queue after deletion  :"<<endl;
    s.print();
  

    return 0;
}



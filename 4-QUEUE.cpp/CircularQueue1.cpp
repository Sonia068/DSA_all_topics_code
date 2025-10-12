// Circular Queue:
#include <iostream>
using  namespace std;
#define size 5

class q{
    int front;
    int rear;
    int arr[size];

    public:
    q(){
        front=-1;
        rear=-1;
    }


    void enq(int val){
        if(front==0 && rear==size-1){
              cout<<"Q is Full";
        }

        if(front==-1){
            front=0;
        }

        rear=(rear+1)%size;
        arr[rear]=val;
        cout<<"Value is inserted "<<val<<" at position "<<rear<<endl;
    }


    void dq(){
        if(front==-1){
            cout<<"Q is Empty";
        }

        else{
            // cout<<"Deleted  element is "<<arr[front];
                     
            int element=arr[front];
        //    front++;
            cout<<element<<endl;
            
            front=(front+1)%size;
            
        }
    }


     void display(){
        if(front==-1 && rear==-1){
            cout<<"Q is empty";
        }
        else{
         
                 int i=front;
                 while (true){
                 cout<<arr[i]<<" ";
                 if(i==rear)
                 break;
                i=(i+1)%size;
            }

            
        }
     }


    
    };
    


    int main(){
        q s;
        s.enq(10);
        s.enq(20);
        s.enq(30);
        s.enq(40);
        s.enq(50);

        s.display();

        s.dq();
        s.dq();
        s.enq(100);
        s.enq(300);
        s.display();

    }
    




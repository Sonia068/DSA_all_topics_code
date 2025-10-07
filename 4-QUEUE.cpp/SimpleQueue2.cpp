// Simple Queue using Linked List:
#include <iostream>
 using namespace std;

 class node{
    public:
    int data;
    node*next;

    node(){
        data=0;
        next=NULL;
    }


    node(int val){
        data=val;
        next=NULL;
    }
 

};

class Queue{
    public:
   node*front;
   node*rear;

   Queue(){
    front=NULL;
    rear=NULL;
   }


 void enqueue(int val){
    node*nn=new node(val);
    if(rear==NULL && front ==NULL){
       front=nn;
       rear=nn;   
 }

 else{
         rear->next=nn;
         rear=nn;
    }
 }



 void dequeue(){
    if(front==NULL){
        cout<<"Queue is empty!Can't  dequeue"<<endl;
    }
    else{
        node*curr=front;
        front=front->next;
        delete  curr;
    }
 }


 void display(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
        node*temp=front;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
 }

};

 int main(){
 Queue q;
 int n;
 int choice;
 do{

 cout<<"\nMENU"<<endl;
 cout<<"1)Enqueue"<<endl;
 cout<<"2)Dequeue"<<endl;
 cout<<"3)Display"<<endl;
 cout<<"4)Exit"<<endl;

 cout<<"Enter the choice :"<<endl;
 cin>>choice;

 switch(choice){

 case 1:
  int v;
  cout<<"Enter the node value:"<<endl;
  cin>>v;
  q.enqueue(v);
  break;

  case 2:
  q.dequeue();
  break;

  case 3:
  cout<<"Queue:"
  q.display();
  break;

  case 4:
  break;

  default:
  cout<<"Invalid Choice"<<endl;
 }
} 
while(choice!=4);

return 0;
 }


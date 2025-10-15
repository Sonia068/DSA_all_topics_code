#include <iostream>
using namespace std;
#define size 5 

class deq{
    int front;
    int rear;
    int arr[size];

    public:
    deq(){
    front=-1;
    rear=-1; 
}

// Inert from front ;
void insertfront(int val1){
    if(rear==size-1){
        cout<<"Q is full";
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else if  (front==0){
        front=size-1;
    }
    else{
          front--;                                             // if(front==0 && front==size-1)
    }
    arr[front]=val1;
}

// Insert from rear 
void insertRear(int val1){
    if(rear==size){
        cout<<"Q is full"<<endl;
    }

    if(front==-1){
        front=0;
    }

      rear=(rear+1)%size;
        arr[rear]=val1;
    }



// Delete from Rear:
 void deleteRear(){
    if(front==-1){
        cout<<"Q is empty";
    }
    else{
    if(front==-1){
        front=0;
    }
    else if( rear==size-1){
        int element=arr[rear]; 
    }

    else if(rear==0){
        rear=size-1;
    }

    else if(front=rear){
        front=rear=-1;
    }

    else{
        rear--;
    }
}
 }


// Delete from front :
   void deleteFront(){
     if(front==-1){
        cout<<"Q is empty"<<endl; 
   }
     else{
        int t1=arr[front];
        front++;
     }

     if(front==size-1){
        front=0;
     } 
     else if(front==rear){
        front=rear=-1;
     }
   }

            // Or

//    void deleteFront(){
//      if(front==-1){
//         cout<<"Q is empty"<<endl; 
//    }
//      else{
//         int t1=arr[front];

//         front=(front+1)%size;
//      }
//     }



// where Front points that should always display first
void display(){
   if(front==-1 && rear==-1){
    cout<<" Q is empty"<<endl;
   }

   else{
       int i=front;
       while(true){
        cout<<arr[i]<<" ";

        if(i==rear)
        break;

        i=(i+1)%size;
          
       }
   }
}

};

int main(){
    deq d;
    d.insertfront(10);
    d.insertfront(20);
    d.insertfront(30);
    d.insertfront(50);
    d.insertfront(60);
    d.deleteRear();

    d.display();
    cout<<"\n";

    d.insertRear(100);
    d.insertRear(200);
    d.insertRear(300);
    d.insertRear(500);
    d.insertRear(600);
    d.display();
    return 0;
}
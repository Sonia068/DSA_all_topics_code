// Priority Queue :
#include <iostream>
using namespace std;
#define size 5

class pq{
    int data[size];
    int priority[size];
    int n;

    public:
    pq(){
    n=0;
}

//  Insert without priority:
void enq(int d,int p){
    if(n==size){
        cout<<"Q is full"<<endl;
        return;
    }
    else{
        data[n]=d;
        priority[n]=p;
        n++;
    }
}

void display(){
    if(n==0){
        cout<<"Q is empty"<<endl;
    }
    else{
        for(int i=0;i<n;i++){
          cout<<" Element:"<<data[i]<<" Priority :"<<priority[i]<<endl;
        }
    }
    }

// Deletion with highest priority :
void dq(){
    if(n==0){
        cout<<"q is empty"<<endl;
    }
    else{
        int index=gethighestpriority();
         cout<<"Deleted element index:"<<index<<", data:"<<data[index]<<", priority:"<<priority[index]<<endl;
        for(int i=index;i<n;i++){
            data[i]=data[i+1];
            priority[i]=priority[i+1];
        }
        n--;
        }
    }


int gethighestpriority(){
    int getMax=0;
    for(int i=1;i<n;i++){
        if(priority[i]>priority[getMax]){
            getMax=i;
        }
    }
    return getMax;
}

void enqpr(int d,int p){
    int i;
    if(n==size){
        for( i=n-2;i>=0 && priority[i]<p;i--){
            data[i+1]=data[i];
            priority[i+1]=priority[i];
        }
        data[i+1]=d;
        priority[i+1]=p;
}
else{
     for( i=n-1;i>=0 && priority[i]<p;i--){
            data[i+1]=data[i];
            priority[i+1]=priority[i];
        }
        data[i+1]=d;
        priority[i+1]=p;
        n++;
}

}


};

int main(){
    pq p;
    int n;
    do{
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Insert the element in queue(without checking priority)"<<endl;
    cout<<"2. Delete the element from queue(with checking priority)"<<endl;
    cout<<"3. Insert the element in queue(with checking priority)"<<endl;
    cout<<"4. Display the elements in queue"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"\n";
    cout<<"Enter the choice :"<<endl;
    cin>>n;

    switch(n){

        case 1:
        int j,k;
        cout<<"Enter the data and priority:"<<endl;
        cin>>j>>k;
         p.enq(j,k);
         break;

        case 2:
         p.dq();
         break;

        case 3:
        int j1,k1;
         cout<<"Enter the data and priority:"<<endl;
         cin>>j1>>k1;
         p.enqpr(j1,k1);
         break;

        case 4:
         p.display();
         break;

        case 5:
         break;

         default:
         cout<<"Invalid Choice !"<<endl;

    }
    }
     while(n!=5);
return 0;
}

    
/*simulate a ticketing system where customers raise support tickets and
are added to a queue. The support team dequeues and resolves tickets.
Allow urgent issues to be placed at the front.Write a program for
above scenario.*/

#include <iostream>
using namespace std;
#define size 3

class ticket{
    int seat[size];
    int priority[size];
    int n;

    public:
    ticket(){
    n=0;
}

//  Insert without priority:
void bookticket(int d,int p){
    if(n==size){
        cout<<"All Seats are booked "<<endl;
        return;
    }
    else{
        seat[n]=d;
        priority[n]=p;
        n++;
    }
}

void showticket(){
    if(n==0){
        cout<<"All seats are empty"<<endl;
    }
    else{
        for(int i=0;i<n;i++){
          cout<<" Element:"<<seat[i]<<" Priority :"<<priority[i]<<endl;
        }
    }
    }

// Deletion with highest priority :
void cancelticket(){
    if(n==0){
        cout<<"All seats are empty"<<endl;
    }
    else{
        int index=gethighestpriority();
         cout<<"Cancel Ticket: pos: "<<index<<", Seat: "<<seat[index]<<", priority: "<<priority[index]<<endl;
        for(int i=index;i<n;i++){
            seat[i]=seat[i+1];
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

//Insertion with highest priority:
void urgentticket(int d,int p){
    int i;
    if(n!=size ){
        for( i=n-1;i>=0 && priority[i]<p;i--){
            seat[i+1]=seat[i];
            priority[i+1]=priority[i];
        }
        seat[i+1]=d;
        priority[i+1]=p;
        n++;
    }

    else{
         for( i=n-2;i>=0 && priority[i]<p;i--){
            seat[i+1]=seat[i];
            priority[i+1]=priority[i];
        }
        seat[i+1]=d;
        priority[i+1]=p;
        n++;
    }

    }


};

int main(){
    ticket p;

        int n;
    do{
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Book the seat number (without checking priority)"<<endl;
    cout<<"2. Cancel the  seat number(with checking(highest) priority)"<<endl;
    cout<<"3. BOOK the seat number with urgent issues (with checking priority)"<<endl;
    cout<<"4. Show all the tickets"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"\n";
    cout<<"Enter the choice :"<<endl;
    cin>>n;

    switch(n){

        case 1:
        int j,k;
        cout<<"Enter the seat number you want to book and its priority:"<<endl;
        cin>>j>>k;
         p.bookticket(j,k);
         break;

        case 2:
         p.cancelticket();
         break;

        case 3:
        int j1,k1;
         cout<<"Enter the seat number and priority:"<<endl;
         cin>>j1>>k1;
         p.urgentticket(j1,k1);
         break;

        case 4:
         p.showticket();
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

    
    


    


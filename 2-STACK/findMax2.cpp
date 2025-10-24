 // Find the max  element in the stack. Original stack must remain intact after finding the max.
// using two stack and without header
#include <iostream>
using namespace std;
#define size 5



class stack{
    
    int top;
    int stck[size];

    public:
    stack(){
        top=-1;
    }


    void push(int val){
    if(top==size-1){
      cout<<"Can't push";
    }
    else{
        top++;
        stck[top]=val;
    }
}

int pop(){
    if(top==-1){
        cout<<"Can't pop!";
    }
   
        int  data=stck[top];
        top--;
        return data;
}


int  top1(){
        if (top == -1) {
            cout << "Stack Underflow !Peek operation is not possible " << endl;
        } 
            int data = stck[top];
           return data;
        
    }


bool empty(){
    if(top==-1){
      return true;
    }
 
        return false;
  
}


};





int fmax(stack &s1) {
    stack  s2;
    int max = s1.top1();  

    
    while (!s1.empty()) {
        int data = s1.top1();
        s2.push(data);
        s1.pop();

        if (data > max) {
            max = data;
        }
    }

    
    while (!s2.empty()) {
        int data = s2.top1();
        s1.push(data);
        s2.pop();
    }

    return max;
}


void display(stack  s1) {
          while(!s1.empty()){
            cout<< s1.top1() << " ";
             s1.pop();
          
            }
             cout<<endl;

        }



int main() {
    stack  s1;
    int  n;
    cout<<"Enter the stack size:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int val;
        cout<<"Enter the value "<<i+1<<":";
        cin>>val;
        s1.push(val);
    }

     cout<<"Stack before fmax():";
     display(s1);
    
    int result = fmax(s1);

    cout << "Maximum element: " << result << endl;


      cout << "Stack after fmax(): ";
      display(s1);
   


    return 0;
}



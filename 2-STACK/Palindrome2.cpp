// CHECK THE STRING IS PALINDROME OR NOT USING TWO STACK:
#include <iostream>
using namespace std;
#include <string>
#define size 100



class stack1{
    public:
    int top;
    char stck[size];

       stack1(){
        top=-1;
    }

    void push(char c);
    char pop();
    bool isempty();
};

class stack2{
    public:
    int top1;
    char stck1[size];

    stack2(){
        top1=-1;
    }

    void push1(char c);
    char pop1();
    bool isempty1();


};


void  stack1::push(char c){
    if(top==size-1){
        cout<<"Stack overflow !Can't push"<<endl;
    }
    else{
        top++;
        stck[top]=c;
    }
}



  char stack1::pop(){
    if(top==-1){
        cout<<"Stack is empty.Can't pop"<<endl;
        return ' ';
    }
   
     char data1=stck[top];
        top--;
        return data1;
       
}


  char stack2::pop1(){
    if(top1==-1){
        cout<<"Stack is empty.Can't pop"<<endl;
        return ' ';
    }
   
     char data1=stck1[top1];
        top1--;
        return data1;
       
}




void  stack2::push1(char c){
    if(top1==size-1){
        cout<<"Stack overflow !Can't push"<<endl;
    }
    else{
        top1++;
        stck1[top1]=c;
    }
}

bool stack1::isempty(){
    if(top==-1){
        return true;
    }

    else{
        return false;
    }

}


bool stack2::isempty1(){
    if(top1==-1){
        return true;
    }

    else{
        return false;
    }

}

string palindrome(string &s,stack1 &s1,stack2 &s2){
    for(int i=0;i<s.length();i++){
        char c=s[i];
        s1.push(c);
    }

    for(int i=s.length()-1;i>=0;i--){
        char c=s[i];
        s2.push1(c);
    }

int flag = 0;   
while (!s1.isempty() && !s2.isempty1()) {
    char c1 = s1.pop();
    char c2 = s2.pop1();

    if (c1 != c2) {
        flag++;  
    }
}

if (flag == 0) {
    return "String is Palindrome";  // no mismatches
} else {
    return "String is not Palindrome";
}

}

 

    
    
 int main(){
    stack1 s1;
    stack2 s2;
    string s;
    cout<<"Enter the infix expression :"<<endl;
    getline(cin,s);
   
    
    string result=palindrome(s,s1,s2);
    cout<<"Result:"<< result << endl;

    return 0;

 }




/*
// ALSO DONE USING BOOL :

bool flag = true;   
while (!s1.isempty() && !s2.isempty1()) {
    char c1 = s1.pop();
    char c2 = s2.pop1();

    if (c1 != c2) {
        flag = false;  
       break;
    }
}
if (flag==true)            // if(flag)
    return "String is Palindrome";
else 
    return "String is not Palindrome";

}

*/



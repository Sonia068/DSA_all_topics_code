// CHECK THE PALINDROME USING ONE STACK:
#include <iostream>
#include <string>
using namespace std;
#define size 100

class stack{
    public:
    int top;
    char stck[size];

    stack(){
        top=-1;
    }
   
    void push(char c){
        if(top==size-1){
            cout<<"Can't push";
        }
        else{
            top++;
            stck[top]=c;
        }
    }

    char pop(){
        if(top==-1){
            cout<<"Can't  pop!";
            return '\0';    // null char 
        }
        else{
            char data=stck[top];
            top--;
          return data;
    }
    return 0;
}
};

    
  string palindrome(string &s,stack &s1){
    for(int i=0;i<s.length();i++){
            s1.push(s[i]);
    }

    for(int i=0;i<s.length();i++){
      char c=s1.pop();
       if(s[i]!=c){
         return "Not Palindrome";
       }
    }
    return "Palindrome";
}


      
int main(){
    string s;
    stack  s1;
    cout<<"Enter the String:";
    getline(cin,s);

    string result=palindrome(s,s1);
    cout<<"Result:"<<result<<endl;
}
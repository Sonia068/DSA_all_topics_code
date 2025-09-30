// INFIX TO POSTFIX CONVERSION(using stack header):
#include <iostream>
#include <stack>
#include <string>
using namespace std;




int precedence(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='/' || c=='*' ){
        return 2;
    }

      if(c=='-'  || c=='+'){
        return 1;
    }
    return -1;
}


string infixTopostfix(string infix){
    stack<char>st;
    string postfix=" ";
 
    for(int i=0;i<infix.length();i++){
          char c=infix[i];
        if(isalnum(c)){
            postfix +=c;
    }
       else if(c=='('){
            st.push(c);
       }

       else if(c==')'){
    // while(!st.empty() && st.top()!='('){
         while(st.top()!='('){
            postfix+=st.top();
               st.pop();
         }
          st.pop();
       }

       else{
        while(!st.empty()  && precedence(c)<=precedence(st.top())){
              postfix+=st.top();
              st.pop();
        }
              st.push(c);
        }
       }

       while(!st.empty()){
            postfix+=st.top();
            st.pop();
       }
       return postfix;
    }


    int main(){
        string s;
        cout<<"Enter the Infix expression:";
        getline(cin,s);

        string result=infixTopostfix(s);
        cout<<"Postfix expression :"<<result<<endl;

        return 0;
    }
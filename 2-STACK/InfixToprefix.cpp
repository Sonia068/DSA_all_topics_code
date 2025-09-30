// INFIX TO PREFIX CONVERSION(using stack header):
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


string reverseString(string prefix) {
    string revprefix = "";
    for (int i = prefix.length() - 1; i >= 0; i--) {
        revprefix += prefix[i];  
    }
    return revprefix;
}

// IN prefix(for solving brackets two ways:1)  assign another bracket in another else if bracket.  2)Swap  the conditions of else if )

string infixToprefix(string infix){
    stack<char>st;
    string prefix=" ";
 
    for(int i=infix.length()-1;i>=0;i--){
          char c=infix[i];
        if(isalnum(c)){
            prefix +=c;
    }
    // Below we assign the value  and commented part is swap the conditions :
       else if(c=='('){
            c=')';
            st.push(c);
       }
       else if(c==')'){
    // while(!st.empty() && st.top()!='('){
          c='(';
         while(st.top()!='('){
            prefix+=st.top();
               st.pop();
         }
          st.pop();
       }
       
/*
        else if(c==')'){
            st.push(c);
       }
       else if(c=='('){

         while(st.top()!=')'){
            prefix+=st.top();
               st.pop();
         }
          st.pop();
       }
          */

       else{
        while(!st.empty()  && precedence(c)<=precedence(st.top())){
              prefix+=st.top();
              st.pop();
        }
              st.push(c);
        }
       }

       while(!st.empty()){
            prefix+=st.top();
            st.pop();
       }

     string rev= reverseString( prefix);
         return rev;

return rev;
}


  int main(){
        string s;
        cout<<"Enter the Infix expression:";
        getline(cin,s);

        string result=infixToprefix(s);
        cout<<"Prefix expression:"<<result<<endl;

        return 0;
    }


/* 
// REVERSE USING SECOND METHOD :

int n = prefix.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[n - i - 1];
        prefix[n - i - 1] = temp;
    }
               or

int n = prefix.length();
    for (int i = 0; i < n / 2; i++) {
        swap(prefix[i],prefix[n-i-1]);
    }
        
 
 // REVERSE USING HEADER (STL):

   #include <algorithm>
    reverse(prefix.begin(),prefix.end());
    return prefix;
}


// REVERSE USINF STRING HEADER :
  #include <string>
string rev;
for (int i = prefix.length() - 1; i >= 0; i--) {
    rev.push_back(prefix[i]);
}

*/
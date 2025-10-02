// Valid Parentheses using header  stack:
#include <iostream>
#include <stack>
using namespace std;


bool parentheses(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('|| s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }

        else{
            if(st.empty()) return false;
            else{
                char c=st.top();
                st.pop();
             if(s[i]==')' && c!='(' || s[i]=='}' && c!='{' || s[i]==']' &&  c!='[' ){
                return false;
        }
    }
        }
    }
        return st.empty();
    }

    int main(){
        string s;
        cout<<"Enter the string :";
        getline(cin,s);

        bool result=parentheses(s);
        if(result==true){
            cout<<"Balanced";
        }
        else{
            cout<<"Unbalanced";
        }

        return 0;
    }


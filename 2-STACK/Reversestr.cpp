// Reverse a string (using  two  stack))
#include <iostream>
#include <string>
#include <stack>
using namespace std;

    


    void reversefunc(string &n){
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<n.length();i++){
            char c=n[i];
            s1.push(c);
        }

        while(!s1.empty()){
         char data=s1.top();
          s2.push(data);
              s1.pop();
        }

        cout<<"Reversed String:"<<endl;
        for(int i=0;i<s2.size();i++){
            
        }

        cout<<endl;

    
    }




int main(){
    string n;
    cout<<"Enter the String:"<<endl;
    getline(cin,n);

    reversefunc(n);


return 0;
}




//Reverse a string (without header and using one Stack and reverse the string first)
#include <iostream>
#include <string>
using namespace std;
#define size 100



class st{
    int top;
    char stck[size];

    public:
    st(){
        top=-1;
    }

    void push(char c){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
        }

        else{
             top++;
            stck[top]=c;
        }
    }

    char pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
        }

        else{
            char data2=stck[top];
            top--;
            return data2;

            // or 
         //   return stck[top--];
        }
        return ' ';
    }
    

    void reversefunc(string &n){
        for(int i=n.length()-1;i>=0;i--){
            char c=n[i];
            push(c);
        }


          cout << "Reversed String: ";
        for(int i=n.length()-1;i>=0;i--){
            n[i] = pop();
        }
        cout << n<< endl;
    }
};




int main() {
    st s1;
    string n;
    cout << "Enter the String:" << endl;
    getline(cin, n);

    s1.reversefunc(n);

    return 0;
}

    
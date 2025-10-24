// Find the max  element in the stack. Original stack must remain intact after finding the max.
// using two stack and header
#include <iostream>
#include <stack>
using namespace std;

int fmax(stack<int> &s1) {
    stack<int> s2;
    int max = s1.top();  

    
    while (!s1.empty()) {
        int data = s1.top();
        s2.push(data);
        s1.pop();

        if (data > max) {
            max = data;
        }
    }

    
    while (!s2.empty()) {
        int data = s2.top();
        s1.push(data);
        s2.pop();
    }

    return max;
}


void display(stack <int> s1) {
          while(!s1.empty()){
            cout<< s1.top() << " ";
             s1.pop();
          
            }
             cout<<endl;

        }
  



int main() {
    stack<int> s1;
    int  n;
    cout<<"Enter the stack size:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int val;
        cout<<"Enter the value "<<i+1<<":";
        cin>>val;
        s1.push(val);
    }

     display(s1);
    
    int result = fmax(s1);

    cout << "Maximum element: " << result << endl;


      cout << "Stack after fmax(): ";
      display(s1);
   


    return 0;
}








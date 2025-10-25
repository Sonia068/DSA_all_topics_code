// Find max in stack (using recursion)
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int findMax(stack <int> &s1){
    // Base case
    if(s1.size()==1){
        return s1.top();
    }

    // top element :
    int topElement = s1.top();
    s1.pop();

    // recursive call on smaller stack:(depth)
    int restElement=findMax(s1);

  // After recursion returns or get the base case,execution starts from here  (unwinding)
    int currMax=max(topElement,restElement);  // check every depth

    s1.push(topElement);

    return currMax;
}
 
    
int main() {
    stack<int> s;
    int n, element;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    cout << "Enter " << n << " elements :\n";
    for (int i = 0; i < n; i++) {
        cin >> element;
        s.push(element);
    }

    cout << "Max element: " << findMax(s) << endl;

    
    cout << "Stack after operation : ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;


    return 0;
}




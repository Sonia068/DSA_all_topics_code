//Construct an algorithm to sort a stack in ascending order using only one extra stack:
#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& s1) {
    stack<int> s2; 

    while (!s1.empty()) {
        int temp = s1.top();
        s1.pop();


        while (!s2.empty() && s2.top() > temp) {   // "<" -> for descending
            s1.push(s2.top());
            s2.pop();
        }

        s2.push(temp);
    }

    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }

    
    cout << "Stack in ascending order (top to bottom): ";
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    int n, num;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        s.push(num);
    }

    sortStack(s);

    return 0;
}



// Construct a function that takes a string as input and returns the string in reverse order using a stack.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString( const string &s) {
    stack<char> st;
    string reversed = s; 

 
    for (int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }


    for (int i = 0; i < s.size(); i++) {
        reversed[i] = st.top();
        st.pop();
    }

    return reversed;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string result = reverseString(s);
    cout << "String after reversing: " << result << endl;

    return 0;
}


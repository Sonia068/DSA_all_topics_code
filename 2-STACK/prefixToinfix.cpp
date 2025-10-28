// Prefix to infix conversion :
#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


string prefixToInfix(string &s) {
    stack<string> st;


    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];

        if (c == ' ')
            continue; 

        
        if (isalnum(c)) {
            string op(1, c);
            st.push(op);
        }
        else if (isOperator(c)) {
            if (st.size() < 2) {
                cout << "Invalid Prefix Expression" << endl;
                return "";
            }

            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string exp = "(" + op1 + string(1, c) + op2 + ")";
            st.push(exp);
        }
    }

    if (st.size() != 1) {
        cout << "Invalid Expression!" << endl;
        return "";
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    getline(cin, prefix);

    string result = prefixToInfix(prefix);

    if (!result.empty())
        cout << "Infix Expression: " << result << endl;

    return 0;
}
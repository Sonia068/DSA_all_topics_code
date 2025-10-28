// Postfix to infix Conversion :

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '*' || c == '+' || c == '-' || c == '/' || c == '^');
}

string postfixToInfix(string &s) {
    stack<string> st;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == ' ')
            continue; 

        if (isalnum(c)) {
            string op(1, c);
            st.push(op);
        }

        else if (isOperator(c)) {
            if (st.size() < 2) {
                cout << "Invalid Postfix Expression!" << endl;
                return "";
            }

            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

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
    string postfix;
    cout << "Enter Postfix Expression: ";
    getline(cin, postfix);r

    string result = postfixToInfix(postfix);

    if (!result.empty())
        cout << "Infix Expression: " << result << endl;

    return 0;
}


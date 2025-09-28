// EVALUATE INFIX EXPRESSIONN:
#include <iostream>
using namespace std;
#include <string>
#define size 50   

class intstack {
public:
    int top1;
    int stack[size];

    intstack() { 
         top1 = -1; 
        }

    void push1(int val);
    int pop1();
    void peek1();
    bool isempty();
};

class charstack {
public:
    int top2;
    char stack[size];

    charstack() { top2 = -1; }

    void push2(char c);
    char pop2();
    void peek2();
    bool isempty();
};

void intstack::push1(int val) {
    if (top1 == size - 1) {
        cout << "Stack overflow !Can't push" << endl;
    } else {
        top1++;
        stack[top1] = val;
    }
}

void charstack::push2(char c) {
    if (top2 == size - 1) {
        cout << "Stack overflow !Can't push" << endl;
    } else {
        top2++;
        stack[top2] = c;
    }
}

int intstack::pop1() {
    if (top1 == -1) {
        cout << "Stack is empty. Can't pop" << endl;
    } else {
        int data1 = stack[top1];
        top1--;
        return data1;
    }
   return 0;
}

char charstack::pop2() {
    if (top2 == -1) {
        cout << "Stack is empty. Can't pop" << endl;
    } else {
        char data2 = stack[top2];
        top2--;
        return data2;
    }
    return 0;
}

void intstack::peek1() {
    if (top1 == -1) {
        cout << "Stack is empty. Can't peek" << endl;
    } else {
        cout << "Peek:" << stack[top1] << endl;
    }
}

void charstack::peek2() {
    if (top2 == -1) {
        cout << "Stack is empty. Can't peek" << endl;
    } else {
        cout << "Peek:" << stack[top2] << endl;
    }
}


bool intstack::isempty(){
    if(top1==-1){
        return true;
    }
    else{
       return false;
    }

    }

bool charstack::isempty(){
    if(top2==-1){
       return true;
    }
    else{
      return false;
    }

    }



bool isoperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return true;
    }
    return false;
}

int priority(char c) {
    if (c == '(') return 0;   
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}

int add(int a, int b, char c) {
    if (c == '+') return b + a;
    else if (c == '-') return b - a;
    else if (c == '*') return b * a;
    else if (c == '/') {
        if (a == 0) {
            cout << "Error! Division by zero" << endl;
            return 0;
        }
        return b / a;
    }
    return 0;
}

int evaluate(string s, intstack &is, charstack &cs) {
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == ' ') continue;  
        if (isdigit(ch)) {
            is.push1(ch - '0');     // changes ascii value to real value
        }
        else if (ch == '(') {
            cs.push2(ch);
        }
        else if (ch == ')') {
            while (!cs.isempty() && cs.stack[cs.top2] != '(') {
                int t1 = is.pop1();
                int t2 = is.pop1();
                char op = cs.pop2();
                int res = add(t1, t2, op);
                is.push1(res);
            }
            cs.pop2(); // pop the '('
        }
        else if (isoperator(ch)) {
            while (!cs.isempty() && priority(ch) <= priority(cs.stack[cs.top2])) {
                int t1 = is.pop1();
                int t2 = is.pop1();
                char op = cs.pop2();
                int res = add(t1, t2, op);
                is.push1(res);
            }
            cs.push2(ch);
        }
    }

    // Copy remaining operators
    while (!cs.isempty()) {
        int t1 = is.pop1();
        int t2 = is.pop1();
        char op = cs.pop2();
        int res = add(t1, t2, op);
        is.push1(res);
    }

     int result = is.pop1();
     return result;
}

int main() {
    charstack c;
    intstack i;

    string s;
    cout << "Enter the infix expression you want to evaluate :" << endl;
    getline(cin, s);

    cout << "Infix Expression: " << s << endl;

    int result = evaluate(s, i, c);
    cout << "Result: " << result << endl;

    return 0;
}


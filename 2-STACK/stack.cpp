// STACK SIMPLE OPERATIONS :(push,pop,peek)
#include <iostream>
using namespace std;
#define size 5

class stack {
    int top;
    int stck[size];

public:
    stack() {
        top = -1;
    }

    // Push operation :
    void push(int val) {
        if (top == size - 1) {
            cout << "Stack Overflow !Can't push" << endl;
        } else {
            top++; // stck[++top]=val;
            stck[top] = val;
            cout << "Element " << val << " pushed at position " << top << endl;
        }
    }

    // PUSH POSITION :
    void push_pos(int value, int pos) {
        if (top == size - 1) {
            cout << "Stack Overflow! Can't push." << endl;
            return;
        }
        if (pos < 0 || pos > top + 1) {
            cout << "Invalid position! Can't push." << endl;
            return;
        }
        // Shift elements to the right
        for (int i = top; i >= pos; i--) {
            stck[i + 1] = stck[i];
        }

        // Insert the new value
        stck[pos] = value;
        top++;

        cout << "Element " << value << " pushed at position " << pos << endl;
    }

    // POP operation :
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow !Can't pop" << endl;
        } else {
            while (top != -1) {
                int data = stck[top];
                cout << "Element " << data << " pop from position " << top << endl;
                top--;
            }
        }
    }

    // pop value from middle :
    void pop_value(int value) {
        if (top == -1) {
            cout << "Stack Underflow! Can't pop." << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            if (stck[i] == value) {
                // Shift elements above down
                for (int j = i; j < top; j++) {
                    stck[j] = stck[j + 1];
                }
                cout << "Element " << value << " popped from position " << i << endl;
                top--;
                return;
            }
        }

        cout << "Element " << value << " not found in stack." << endl;
    }

    // pop using pos :
    void pop_pos(int pos) {
        if (top == -1) {
            cout << "Stack Underflow! Can't pop." << endl;
            return;
        }
        if (pos < 0 || pos > top) {
            cout << "Invalid position! Can't pop." << endl;
            return;
        }
        cout << "Element " << stck[pos] << " popped from position " << pos << endl;

        for (int i = pos; i < top; i++) {
            stck[i] = stck[i + 1];
        }
        top--;
    }

    // PEEK operation :
    void peek() {
        if (top == -1) {
            cout << "Stack Underflow !Peek operation is not possible " << endl;
        } else {
            int data = stck[top];
            cout << "Peek element " << data << " from position " << top << endl;
        }
    }

    // isempty() operation :
    void isempty() {
        if (top == -1) {
            cout << "Stack is empty " << endl;
        } else {
            cout << "Stack is not empty " << endl;
        }
    }

    // size ():
    void sizeofstack() {
        if (top == -1) {
            cout << "Stack is empty, size is 0" << endl;
        } else {
            cout << "Size of stack is: " << (top + 1) << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty " << endl;
        } else {
            cout << "Stack Elements : ";
            for (int i = 0; i <= top; i++) {
                cout << stck[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    stack s;

    int choice;

    do {
        cout << "\n";
        cout << "MENU :\n";
        cout << "1) PUSH OPERATION \n";
        cout << "2) PUSH OPERATION(using value and position) \n";
        cout << "3) POP OPERATION \n";
        cout << "4) POP OPERATION(using value) \n";
        cout << "5) POP OPERATION (Using position)\n";
        cout << "6) PEEK THE TOPMOST ELEMENT \n";
        cout << "7) OPERATION TO CHECK WHETHER THE STACK IS EMPTY OR NOT \n";
        cout << "8) SIZE OF STACK \n";
        cout << "9) DISPLAY \n";
        cout << "10) EXIT \n";

        cout << "Enter the choice :" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter the number of elements to push:";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter the element " << i + 1 << ":" << endl;
                int l;
                cin >> l;
                s.push(l);
            }
            break;
        }

        case 2: {
            cout << "Enter the value and position of elements to push:";
            int x, y;
            cin >> x >> y; // FIXED
            s.push_pos(x, y);
            break;
        }

        case 3:
            cout << "POP all the elements :" << endl;
            s.pop();
            break;

        case 4: {
            cout << "Enter the value which you want to POP ?";
            int t;
            cin >> t;
            s.pop_value(t);
            break;
        }

        case 5: {
            cout << "Enter the position from where you want to POP the elements ?";
            int z;
            cin >> z;
            s.pop_pos(z);
            break;
        }

        case 6:
            cout << "Topmost element :" << endl;
            s.peek();
            break;

        case 7:
            cout << "CHECK THE STACK :" << endl;
            s.isempty();
            break;

        case 8:
            cout << "Size of Stack :" << endl;
            s.sizeofstack();
            break;

        case 9:
            s.display();
            break;

        case 10:
            cout << "EXIT" << endl;
            break;

        default:
            cout << "Invalid choice !" << endl;
        }
    } while (choice != 10);
    return 0;
}


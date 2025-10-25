// Construct a function to remove all integers greater than the given integer using standard Stack Operations.
#include <iostream>
#include <stack>
using namespace std;


void removeGreater(stack <int> &s,int num){
     stack <int> s1;

     while(!s.empty()){
     int  data=s.top();
     if(data<=num){
        s1.push(data);
        s.pop();
     }

     else{
        s.pop();
     }
    }

    while(!s1.empty()){
        int data=s1.top();
        s.push(data);
        s1.pop();
    }

}


void printStack(stack<int> s) {
cout<<"Stack (top to bottom) :"<<endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}


int main() {
    stack<int> s;
    int choice, num;

    do {
        cout << "--- Stack Menu ---\n";
        cout << "1. Push element onto stack\n";
        cout << "2. Remove all integers greater than a number\n";
        cout << "3. Display stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> num;
                s.push(num);
                cout << num << " pushed onto stack.\n";
                break;
            case 2:
                cout << "Enter number to remove elements greater than: ";
                cin >> num;
                removeGreater(s, num);
                cout << "Elements greater than " << num << " removed.\n";
                break;
            case 3:
                printStack(s);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
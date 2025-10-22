#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Wordstack {
    vector<string> s;  

public:
    void push(string &word) {
        s.push_back(word);
        cout << "Pushed word: " << word << endl;
    }

    string pop() {
        if (s.empty()) {
            cout << "Stack is empty. Can't pop!" << endl;
            return "";
        } else {
            string topWord = s.back();
            cout << "Popped word: " << topWord << endl;
            s.pop_back();
            return topWord;
        }
    }

    string peek() {
        if (s.empty()) {
            cout << "Stack is empty. Can't peek!" << endl;
            return "";
        } else {
            string peekWord = s.back();
            cout << "Peek word: " << peekWord << endl;
            return peekWord;
        }
    }

    void display() {
        if (s.empty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack contents :" << endl;
            for (int i = 0; i < s.size(); i++) {
                cout << s[i] << endl;
            }
        }
    }

    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    Wordstack stack;
    int choice;
    string word;

    do {
        cout << "\n---- WORD STACK MENU ----" << endl;
        cout << "1. Push a word" << endl;
        cout << "2. Pop a word" << endl;
        cout << "3. Peek top word" << endl;
        cout << "4. Display all words" << endl;
        cout << "5. Check if stack is empty" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter word to push: ";
                getline(cin, word);
                stack.push(word);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.peek();
                break;

            case 4:
                stack.display();
                break;

            case 5:
                if (stack.isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

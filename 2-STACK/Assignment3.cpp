/* Construct an editor which allows ‘undo’
operation. ‘Undo’ will help you to bring back the last deleted
word from the editor*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UndoStack {
    vector<string> stack;  

public:

    void store(const string &word) {
        stack.push_back(word);
        cout << "Stored deleted word: " << word << endl;
    }

  
    string undo() {
        if (stack.empty()) {
            cout << "Nothing to undo!" << endl;
            return "";
        } else {
            string lastDeleted = stack.back();
            stack.pop_back();
            cout << "Undo: Restored word '" << lastDeleted << "'" << endl;
            return lastDeleted;
        }
    }


    string peek() {
        if (stack.empty()) {
            cout << "Stack is empty!" << endl;
            return "";
        } else {
            return stack.back();
        }
    }


    void display() {
        if (stack.empty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Deleted words :" << endl;
            for (int i = stack.size() - 1; i >= 0; i--) {
                cout << stack[i] << endl;
            }
        }
    }


    bool isEmpty() {
        return stack.empty();
    }
};

int main() {
    UndoStack editor;
    string word;
    int choice;

    do {
        cout << "\n--- Editor Undo Menu ---\n";
        cout << "1. Delete word (store)\n";
        cout << "2. Undo last delete\n";
        cout << "3. Peek last deleted word\n";
        cout << "4. Display all deleted words\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter word to delete: ";
                getline(cin, word);
                editor.store(word);
                break;
            case 2:
                editor.undo();
                break;
            case 3:
                word = editor.peek();
                if (!word.empty())
                    cout << "Last deleted word: " << word << endl;
                break;
            case 4:
                editor.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

/*Implement a Text Editor where each operation(insert,delete,modify) is stored in DLL.Use backward traversal  
for undo and forward traversal for redo */
#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string content;
    node* next;
    node* prev;

    node() {
        content = " ";
        next = NULL;
        prev = NULL;
    }

    node(string text) {
        content = text;
        next = NULL;
        prev = NULL;
    }
};

class TextEditor {
public:
    node* head;
    node* current; 

    TextEditor() {
        head = NULL;
        current = NULL;
    }

    void insertText(string text);
    void deleteText();
    void modifyText(string newText);
    void undo();
    void redo();
    void printCurrentText();
};

void TextEditor::insertText(string text) {
    node* newnode = new node(text);
    if (head == NULL) {
        head = newnode;
        current = head;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
        current = newnode; 
    }
    cout << "Inserted Text: " << newnode->content << endl;
}

void TextEditor::deleteText() {
    if (head == NULL) {
        cout << "Text Editor is empty, Nothing to delete" << endl;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    current = temp->prev;
    cout << "Deleted Text: " << temp->content << endl;
    delete temp;
}

void TextEditor::modifyText(string newText) {
    if (current == NULL) {
        cout << "Nothing to modify!" << endl;
        return;
    }
    string oldText = current->content;
    current->content = newText;
    cout << "Modified Text: " << oldText << " -> " << newText << endl;
}


void TextEditor::undo() {
    if (current == NULL) {
        cout << "Nothing to undo" << endl;
        return;
    }
    cout << "Undo Text: " << current->content << endl;
    current = current->prev; 
}

void TextEditor::redo() {
    if (current == NULL) {
        if (head != NULL)
         current = head; 
        else {
            cout << "Nothing to redo" << endl;
            return;
        }
       }

       else if (current->next != NULL) {
        current = current->next; 
    } 
    
      else {
        cout << "Nothing to redo" << endl;
        return;
    }
    cout << "Redo Text: " << current->content << endl;
}



void TextEditor::printCurrentText() {
    if (current == NULL){
      cout << "Text Editor is empty" << endl;
    }
    else{
     cout << "Current Text: " << current->content << endl;
}
}


int main() {
    TextEditor obj;
   int choice;
    string text;

    do {
        cout << "\n--- Text Editor Menu ---\n";
        cout << "1. Insert Text "<<endl;
        cout << "2. Delete Last Text"<<endl;
        cout << "3. Modify Current Text"<<endl;
        cout << "4. Undo"<<endl;
        cout << "5. Redo"<<endl;
        cout << "6. Print Current Text"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        cin.ignore(); 

        switch(choice) {
            case 1:
                cout << "Enter text to insert: ";
                getline(cin, text);
                obj.insertText(text);
                break;

            case 2:
                obj.deleteText();
                break;

            case 3:
                cout << "Enter new text: ";
                getline(cin, text);
                obj.modifyText(text);
                break;

            case 4:
                obj.undo();
                break;

            case 5:
                obj.redo();
                break;

            case 6:
                obj.printCurrentText();
                break;

            case 7:
                cout << "Exiting Text Editor...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

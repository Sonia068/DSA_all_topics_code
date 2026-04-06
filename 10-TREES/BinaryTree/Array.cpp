//<------Array representation(Sequential) of a binary tree------>
#include <iostream>
using namespace std;

char tree[100];

// Initialize tree with '\0'
void initialize() {
    for (int i = 0; i < 100; i++) {
        tree[i] = '\0';
    }
}

// Create root
void root(char value) {
    if (tree[0] != '\0') {
        cout << "Root node already exists.\n";
    } else {
        tree[0] = value;
    }
}

// Set left child
void set_left(char key, int parent) {
    if (tree[parent] == '\0') {
        cout << "Can't set left child at index " << 2 * parent + 1 << ", parent not found\n";
    } else {
        tree[2 * parent + 1] = key;
    }
}

// Set right child
void set_right(char key, int parent) {
    if (tree[parent] == '\0') {
        cout << "Can't set right child at index " << 2 * parent + 2 << ", parent not found\n";
    } else {
        tree[2 * parent + 2] = key;
    }
}

// Print tree
void print() {
    cout << "\nTree (array form):\n";
    for (int i = 0; i < 10; i++) {  
        if (tree[i] != '\0')
            cout << tree[i] << " ";
        else
            cout << "- ";
    }
    cout << endl;
}

int main() {
    initialize();

    char value;
    cout << "Enter root node: ";
    cin >> value;
    root(value);

    int choice;
    char key;
    int parent;

    do {
        cout << "\n1. Insert Left Child";
        cout << "\n2. Insert Right Child";
        cout << "\n3. Display Tree";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter parent index: ";
                cin >> parent;
                cout << "Enter value: ";
                cin >> key;
                set_left(key, parent);
                break;

            case 2:
                cout << "Enter parent index: ";
                cin >> parent;
                cout << "Enter value: ";
                cin >> key;
                set_right(key, parent);
                break;

            case 3:
                print();
                break;
        }

    } while (choice != 4);

    return 0;
}


/*
if the node is at index i=0, then
1. left child is at index (2*i )+ 1   
2. right child is at index (2*i )+ 2
3. parent is at index (i-1)/2   (floor value)


if the array is started from index i=1, then
1. left child is at index (2*i)  = 3
2. right child is at index ([2*i)+1)] = 4
3. parent is at index (i/2) = 0  (floor value)

*/

// Array representation of Binary Search Tree (BST) 

#include <iostream>
using namespace std;

class BSTArray {
    int tree[100];

public:
    BSTArray() {
        for (int i = 0; i < 100; i++) {
            tree[i] = -1;
        }
    }

    // Insert function(Recurive)
    void insert(int value, int index = 0) {
        if (index >= 100) {
            cout << "Tree overflow!\n";
            return;
        }


        if (tree[index] == -1) {
            tree[index] = value;
            return;
        }

        // BST logic
        if (value < tree[index]) {
            insert(value, 2 * index + 1);   // go left
        } else {
            insert(value, 2 * index + 2);   // go right
        }
    }


    
    // Display tree (array form)
    void display() {
        cout << "\nArray Representation:\n";
        for (int i = 0; i < 20; i++) {
            if (tree[i] != -1)
                cout << tree[i] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
};

int main() {
    BSTArray bst;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        bst.insert(value);
    }

    bst.display();

    return 0;
}





/*
    // Iterative insert (NO recursion)
    void insert(int value) {
        int index = 0;

        while (true) {
            // Overflow check
            if (index >= 100) {
                cout << "Tree overflow!\n";
                return;
            }

            // If empty position found
            if (tree[index] == -1) {
                tree[index] = value;
                return;
            }

            // Move left or right
            if (value < tree[index]) {
                index = 2 * index + 1;   // go left
            } else {
                index = 2 * index + 2;   // go right
            }
        }
    }

    */
  

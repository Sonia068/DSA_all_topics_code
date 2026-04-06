#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left, *right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST (recursive)
node* insert(node* root, int val) {
    if (root == NULL) {
        return new node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    else{
        break;  // return root;
    }

    return root;
}

// Create BST using user input
node* createBST() {
    int x;
    node* root = NULL;

    cout << "Enter values (-1 to stop): ";
    while (true) {
        cin >> x;
        if (x == -1) break;

        root = insert(root, x);
    }

    return root;
}

// Inorder traversal
void inorder(node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = createBST();

    cout << "Inorder traversal (BST sorted): ";
    inorder(root);

    return 0;
}
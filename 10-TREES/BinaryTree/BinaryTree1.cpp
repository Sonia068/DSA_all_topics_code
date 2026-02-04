// Create and  Declare Binary tree :
#include <iostream>
using namespace std;

// Declare node:
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

// Print :
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);          
    cout << root->data << " ";    
    inorder(root->right);         
}

int main() {
  // Create:
    Node* firstNode = new Node(2);
    Node* secondNode = new Node(3);
    Node* thirdNode = new Node(4);
    Node* fourthNode = new Node(5);


    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;

    cout << "Inorder Traversal Output: ";
    inorder(firstNode);

    return 0;
}

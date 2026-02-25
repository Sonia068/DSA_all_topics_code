//<----------BST- Add duplicates(using count)------------->
#include <iostream>
using namespace std;

class node{
  private:
    int data;
    int count;
    node* left,*right;

    public:
      node(){
      data=0;
      count=0;
      left=right=NULL;
    }  



    node(int v){
      data=v;
      count=1;
      left=right=NULL;
    }  

// Insertion :

// Non-recursive:
// Using count:
node* insert(node* root,int k){
   if(root == NULL){
       return new node(k);
   }

   node* temp = root;
   while(true){

       if(k == temp->data){      
           temp->count++;        
           break;
       }

       else if(k < temp->data){
           if(temp->left == NULL){
               temp->left = new node(k);
               break;
           }
           temp = temp->left;
       }

       else{

           if(temp->right == NULL){
               temp->right = new node(k);
               break;
           }
           temp = temp->right;
       }
   }

   return root;
}

// Recursive :
node* Rinsert(node* root, int key) {
    if (root== nullptr) 
        return new node(key);

    if (key == root->data) {
        root->count++;
        return root;
    }

    if (key < root->data)
        root->left = Rinsert(root->left, key);
    else
        root->right = Rinsert(root->right, key);

    return root;
}

// Inorder :
void inorder(node* root){
    if(root != NULL){
        inorder(root->left);

        cout << root->data << " appears " 
             << root->count << " times\n";

        inorder(root->right);
    }
}
};


int main() {
    node nn;
    node* root = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        root = nn.insert(root, val);
    }

    cout<<"Inorder Traversal: ";
    nn.inorder(root);

    return 0;
}
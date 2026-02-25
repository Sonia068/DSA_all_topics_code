//<----------BST- handle duplicates------------->
#include <iostream>
using namespace std;

class node{
  private:
    int data;
    node* left,*right;

    public:
      node(){
      data=0;
      left=right=NULL;
    }  



    node(int v){
      data=v;
      left=right=NULL;
    }  

// Insertion :

// Non-recursive:
// Insert duplicate element on right subtree or left subtree: (Naive  Approach):
node* insert(node* root,int k){
   if(root==NULL) {
     return new node(k);
   }

   node* nn=new node(k);
   node* temp=root;

   while(temp!=NULL){

       if(temp->data > nn->data && temp->left!=NULL){
            temp=temp->left;
       }

       else if(temp->data <= nn->data && temp->right!=NULL){
            temp=temp->right;
       }

       else{
            break;
       }
   }

   if(temp->data > nn->data){
        temp->left=nn;
   }
   else{
        temp->right=nn;
   }

   return root;
}

// Recursive :
node* Rinsert(node* root,int k){
   if(root==NULL){
    return new node(k);
   }

   if(k<root->data){
    root->left=Rinsert(root->left,k);
   }
   else{
     root->right=Rinsert(root->right,k);
   }

   return root;
}



// Inorder :

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
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
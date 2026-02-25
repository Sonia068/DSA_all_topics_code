//<----------INORDER SUCCESSOR  (BST)  ------------->
#include <iostream>
#include <stack>
#include <queue>
#include <string>
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
node* insert(node* root,int k){
    node* nn=new node(k);
   if(root==NULL) {
     root=new node(k);
     return root;
   }

    node* temp=root;
        while(temp!=NULL){
           if(temp->data>nn->data && temp->left!=NULL){
            temp=temp->left;
           }

           else if(temp->data<nn->data && temp->right!=NULL){
            temp=temp->right;
           }

           else{
            break;
           }

        }

        if(temp->data>nn->data){
            temp->left=nn;
        }
        else{
            temp->right=nn;
        }

        return root;

            
        }



    int leftmost(node* n){
       node* curr=n;
       while(curr->left!=NULL){
           curr=curr->left;
       }
       return curr->data;
    }
    
    
    int inOrderSuccessor(node *root, node *x) {
    
       if(root==NULL) return 0;
       
       if(x->data==root->data && root->right!=NULL){
           return leftmost(root->right);
       }
      
       node* curr=root;
       node* succ=NULL;
       while(curr!=NULL){
           if(x->data<curr->data){
               succ=curr;
               curr=curr->left;
           }
           
           else if(x->data>=curr->data){
               curr=curr->right;
           }
       }
       
       if(succ!=NULL) {
           return succ->data;
       }
       
       return -1;
    }   

    node* search(node* root, int key) {
    while (root != NULL) {
        if (key < root->data)
            root = root->left;
        else if (key > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

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

    
    int key;
    cout << "Enter value to find successor: ";
    cin >> key;

    node* x = nn.search(root, key);

    if(x == NULL) {
        cout << "Value not found in tree";
        return 0;
    }

    int result = nn.inOrderSuccessor(root, x);

    if(result != -1)
        cout << "Inorder Successor of " << key << " is: " << result;
    else
        cout << "No Inorder Successor exists";

    return 0;
}



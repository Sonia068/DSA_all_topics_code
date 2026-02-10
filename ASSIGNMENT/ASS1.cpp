/*
Consider the Dictionary Implementations which allow for efficient storage and retrieval of
key-value pairs using binary search trees. Each node in the tree store (key, value) pair. The
dictionary should support the following operations efficiently:
1. Insert word (Handle insertion of duplicate entry)
2. Delete word
3. Search specific word
4. Display dictionary (Traversal)
5. Mirror image of dictionary
6. Create a copy of dictionary
7. Display dictionary level wise
*/


#include <iostream>
#include <stack>
#include <queue>
using namespace std;


class node
{
    public:
    string key;
    int value;
    node *left,*right;
   
    node(string k,int v){
        key=k;
        value=v;
        left=NULL;
        right=NULL;
    }
};

// 1. Insert word (Handle insertion of duplicate entry)
node* insert(node* root ,string k,int v){
    node* nn= new node(k,v);
    if(root==NULL){
        root=nn;
        return root;
    }
   node* temp=root;
       while(temp!=NULL){
           if(k<temp->key && temp->left!=NULL){
               temp=temp->left;
           }
           else if(k>temp->key && temp->right!=NULL){
               temp=temp->right;
           }
           
           else{
               break;
           }
       }    
       
       if(k<temp->key){
           temp->left=nn;
       }
       
        if(k>temp->key){
           temp->right=nn;
       }
       return root;
    }


 //successor
node* findMin(node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// 2. Delete word
node* deleteNode(node* root, string key) {
    if (root == NULL)
        return root;

    if (key< root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1: no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root=NULL;
            return root;
        }
        // Case 2: one child
        else if (root->left == NULL) {
            node* temp = root;
            root=root->right;
            delete temp;
            return root;
        }
        else if (root->right == NULL) {
            node* temp = root;
            root=root->left;
            delete temp;
            return root;
        }
       
        // Case 3: two children
        else {
            node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
   
    return root;
}


// predecessor
node* findMax(node* root) {  
    while (root->right != NULL)
        root = root->right;
    return root;
}




// 3. Search specific word
node* search(node* root,string key){
    if(root==NULL) return root;

    while(root!=NULL){
        if(key==root->key)
            return root;

        else if(key < root->key)
            root=root->left;

        else
            root=root->right;
    }

    return NULL;
}

// 4. Display dictionary (Traversal)
// Recursive approach :
void inorderrec(node* root){
    if(root==NULL) return;
    else{
        inorderrec(root->left);
        cout<<root->key<<":"<<root->value<<" ";
        inorderrec(root->right);
     
    }
}

void postorderrec(node* root){
    if(root==NULL) return;
    else{
        postorderrec(root->left);
        postorderrec(root->right);
        cout<<root->key<<":"<<root->value<<" ";
    }
}

void preorderrec(node* root){
    if(root==NULL) return ;
    else{
        cout<<root->key<<":"<<root->value<<" ";
        preorderrec(root->left);
        preorderrec(root->right);
    }
}

// Non-Recursive approach :
void inorder(node* root){
    stack<node*>s;
    node* curr=root;
    while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            node* nn=s.top();
            s.pop();
            cout<<nn->key<<" "<<nn->value<<" ";
            curr=nn->right;
        }
        }
    }
   

void preorder(node* root){
    stack<node*>s;
    node* curr=root;
    while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            cout<<curr->key<<" "<<curr->value<<" ";
            s.push(curr);
            curr=curr->left;
    }
        else{
            node* nn=s.top();
            s.pop();
            curr=nn->right;
        }
        }
    }
   
// Using one stack :
void postorder(node* root){
    if(root==NULL) return ;
    stack<node*>s1,s2;
    s1.push(root);
    node* curr=root;
   
    while(!s1.empty()){
        node* s=s1.top();
        s1.pop();
        s2.push(s);
       
      if(s->left!=NULL){
          s1.push(s->left);
      }
     
      if(s->right!=NULL){
          s1.push(s->right);
      }
    }
   
     while(!s2.empty()){
        node* s=s2.top();
        s2.pop();
        cout<<s->key<<":"<<s->value<<" ";
       
     }
}

// 5. Mirror image of dictionary:
void mirror(node* root){
    if(root){
         mirror(root->left);
         mirror(root->right);
         node* temp=root->left;
         root->left=root->right;
         root->right=temp;
    }
    return ;
}



// 6. Create a copy of dictionary:
node* copyTree(node* root){
    node* curr=root;
    return curr;
}


// 7. Display dictionary level wise
void levelOrder(node* root)
{
    if(root==NULL) return ;
    queue<node*> q;
    q.push(root);

    while(q.size()>0){
         node* curr=q.front();
         q.pop();
       cout<<curr->key<<":"<<curr->value<<" ";

         if(curr->left!=NULL){
           q.push(curr->left);
         }

         if(curr->right!=NULL){
           q.push(curr->right);
         }
    }
}
   
int main(){

    node* root=NULL;
    node* copiedTree=NULL;

    int choice;
    string key;
    int value;

    do{

        cout<<"\n========= DICTIONARY MENU =========\n";
        cout<<"1. Insert word\n";
        cout<<"2. Delete word\n";
        cout<<"3. Search word\n";
        cout<<"4. Inorder Traversal\n";
        cout<<"5. Preorder Traversal\n";
        cout<<"6. Postorder Traversal\n";
        cout<<"7. Level Order Traversal\n";
        cout<<"8. Mirror Tree\n";
        cout<<"9. Copy Tree\n";
        cout<<"10. Display Copied Tree\n";
        cout<<"11. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

        // INSERT
        case 1:
            cout<<"Enter word: ";
            cin>>key;
            cout<<"Enter meaning value: ";
            cin>>value;

            root = insert(root,key,value);
            cout<<"Word inserted successfully!\n";
            break;

        // DELETE
        case 2:
            cout<<"Enter word to delete: ";
            cin>>key;

            if(search(root,key)==NULL){
                cout<<"No such node is there\n";
            }
            else{
                root = deleteNode(root,key);
                cout<<"Node deleted successfully\n";
            }
            break;

        // SEARCH
        case 3:
            cout<<"Enter word to search: ";
            cin>>key;

            if(search(root,key)==NULL)
                cout<<"Word not found\n";
            else
                cout<<"Word found\n";
            break;

        // INORDER
        case 4:
            cout<<"Inorder Traversal:\n";
            inorderrec(root);
            cout<<"\n";
            break;

        // PREORDER
        case 5:
            cout<<"Preorder Traversal:\n";
            preorderrec(root);
            cout<<"\n";
            break;

        // POSTORDER
        case 6:
            cout<<"Postorder Traversal:\n";
            postorderrec(root);
            cout<<"\n";
            break;

        // LEVEL ORDER
        case 7:
            cout<<"Level Order Traversal:\n";
            levelOrder(root);
            cout<<"\n";
            break;

        // MIRROR
        case 8:
            mirror(root);
            cout<<"Tree mirrored successfully!\n";
            break;

        // COPY TREE
        case 9:
            copiedTree = copyTree(root);
            cout<<"Tree copied successfully!\n";
            break;

        // DISPLAY COPIED TREE
        case 10:
            if(copiedTree==NULL)
                cout<<"No copied tree available\n";
            else{
                cout<<"Copied Tree (Inorder):\n";
                inorderrec(copiedTree);
                cout<<"\n";
            }
            break;

        // EXIT
        case 11:
            cout<<"Exiting program...\n";
            return 0;

        default:
            cout<<"Invalid choice! Try again.\n";
        }
    }while(choice!=0);


    return 0;
}



 


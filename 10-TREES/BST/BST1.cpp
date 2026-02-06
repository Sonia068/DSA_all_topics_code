// Binary Search tree(BST)(Operations- Insert,Delete,Search,Traversal(DFS(pre,post,in)):
// Using recursion and iterative approach:

#include <iostream>
#include <stack>
using namespace std;



class node{
    public:
    int data;
    node*left,*right;

    node(){
        data=0;
        left=NULL;
        right=NULL;
    }

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// SEARCH :
// Using iterative approach:
bool search(node* root,int key){
    if(root==NULL) return false;

    node* temp=root;
    while(temp!=NULL){
        if(key==temp->data){
            return true;
        }
        else if(key<temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}


// Using recursive Approach :
bool Rsearch(node* root,int key){
    if(root==NULL) return false;

    if(root->data==key){
        return true;
    }

    if(key<root->data){
        return Rsearch(root->left,key);
    }
    else{
        return Rsearch(root->right,key);
    }

}


//INSERT:

// Using iterative approach:
node* insert(node* root,int data){
    node* nn=new node(data);
    if(root==NULL){
        root=nn;
        return root;
    }

    node* temp=root;
    while(temp!=NULL){
       if(temp->data > nn->data && temp->left!=NULL){
           temp=temp->left;
       }

       else if(temp->data < nn->data && temp->right!=NULL){
          temp=temp->right;
       }
       else{ break;
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

// Using recursive approach :
node*  Rinsert(Node* root, int key) {
        if(root==NULL){
            return new node(key);
        }
        
        if(key<root->data){
            root->left= insert(root->left,key);
        }
        else{
            root->right= insert(root->right,key);
        }
        return root;
    }

// DELETE:

// DELETE 1:
// Using iterative approach (Without calling func):
node* deleteNode(node* root, int key) {
    if (root == NULL) return NULL;

    node* parent = NULL;
    node* curr = root;

    // 1. Find the node and its parent
    while (curr != NULL && curr->data != key) {
        parent = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    // Key not found
    if (curr == NULL) return root;

    // 2. Case: node with two children
    if (curr->left != NULL && curr->right != NULL) {
        node* succParent = curr;
        node* succ = curr->right;

        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        curr->data = succ->data;
        curr = succ;
        parent = succParent;
    }

    // 3. Case: node with one child or no child
    node* child = (curr->left != NULL) ? curr->left : curr->right;

    // If deleting root
    if (parent == NULL) {
        delete curr;
        return child;
    }

    if (parent->left == curr)
        parent->left = child;
    else
        parent->right = child;

    delete curr;
    return root;
}



// DELETE 2:
// Using recursive approach and functions :
Node* getSuccessor(Node* curr) {
    curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

// Delete a node with value x from BST
Node* delNode(Node* root, int x) {
    if (root == nullptr)
        return root;

    if (root->data > x)
        root->left = delNode(root->left, x);
    else if (root->data < x)
        root->right = delNode(root->right, x);
    else {
        // Node with 0 or 1 child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with 2 children
        Node* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}

// DELETE 3 :
node* delete(node* root,int key){
    if(root==NULL) return root;

    if(root->data==key){
        return helper(root);
    }

    node* temp=root;
    while(root!=NULL){
        if(root->data>key){
            if(root->left!=NULL && node->left->data==key ){
                root->left=helper(root->left);
                break;
            }
            else{
                root=root->left;
            }
        }

        else{
               if(root->right!=NULL && node->left->data==key ){
                root->right=helper(root->left);
                break;
            }
            else{
                root=root->right;
            }
        }
        }
    return temp;

    }


node* helper(node* root ){
    if(root->left==NULL){
        return root->right;
    }

     if(root->right==NULL){
        return root->left;
    }

    node* Rightchild=root->right;
    node* smallest=findlastsmallest(root->left);
    return root->left;
    
}


node* findlastsmallest(node* root){
     if(root->right==NULL){
        return root;
     }
     return findlastsmallest(root->right);
}




// DFS (TRAVERSAL):

// Recursive postorder,preorder,inorder:

    void Rinorder(node*root){
        if(root==NULL ){
            return;
        }
        else{
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);

        }
        
    }

    void Rpostorder(node* root){
        if(root==NULL){
            return ;
        }
        else{
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }


    void Rpreorder(node* root){
        if(root==NULL){
            return ;
        }
        else{
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }




// Non-recursive preorder,postorder and inorder:
void inorder(node* root){
    stack<node*>st;
  node* temp=root;
  
  while(temp!=NULL || !st.empty()){
     if(temp!=NULL){
        st.push(temp);
        temp=temp->left;
  }
  else{
    node* s=st.top();
    st.pop();
    cout<<s->data<<" ";
    temp=s->right;
  }
}
}


void preorder(node* root){
    stack<node*>st;
  node* temp=root;
  while(temp!=NULL || !st.empty()){
     if(temp!=NULL){
        cout<<temp->data<<" ";
        st.push(temp);
        temp=temp->left;
  }
  else{
    node* s=st.top();
    st.pop();
    temp=s->right;
  }
}
}

// Post order using one stack and postorder using two stack :
// Using two stack:
void Tpostorder(node* root){
  if (root == NULL) return;
    stack <node*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        node* s=st1.top();
        st1.pop();
        st2.push(s);

        if(s->left!=NULL){
            st1.push(s->left);
        }

        if(s->right!=NULL){
            st1.push(s->right);
        }
    }

    while(!st2.empty()){
        node* d=st2.top();
        st2.pop();
        cout<<d->data<<" ";
    }
}

//Using one stack:
void Opostorder(node* root){
    if(root==NULL) return ;
    stack <node*> st;
    node* lastNode=NULL;

    node* temp=root;
    while(temp!=NULL || !st.empty()){
      if(temp!=NULL){
        st.push(temp);
        temp=temp->left;
    }
    
    else{
        node* topNode=st.top();
        if(topNode->right!=NULL && lastNode!=topNode->right){
            temp=topNode->right;
        }

        else{
            cout<<topNode->data<<" ";
            lastNode=topNode;
            st.pop();
        }
    }
}



}


// Using flag:
void Fpostorder(node* root){
    if (root==NULL) return ;
    stack <pair<node*,int>> st;
    st.push({root,0});
    while(!st.empty()){
     auto topNode=st.top();
     st.pop();

     node*curr=topNode.first;
     int flag=topNode.second;

     if(flag==1){
       cout<<curr->data<<" ";
     }
     else{
        st.push({curr,1});

        if(curr->right!=NULL){
            st.push({curr->right,0});
        }

        if(curr->left!=NULL){
            st.push({curr->left,0});
        }
     }
    }
}


    int main() {
    node* root = NULL;
    int choice, tchoice, value;

    do {
        cout << "\n====== BST MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (search(root, value) ? "Found\n" : "Not Found\n");
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;

        case 4:
            do {
                cout << "\n--- Traversal Menu ---\n";
                cout << "1. Recursive Inorder\n";
                cout << "2. Recursive Preorder\n";
                cout << "3. Recursive Postorder\n";
                cout << "4. Iterative Inorder\n";
                cout << "5. Iterative Preorder\n";
                cout << "6. Iterative Postorder\n";
                cout << "7. Back\n";
                cout << "Enter choice: ";
                cin >> tchoice;

                switch (tchoice) {
                case 1:
                    cout << "Recursive Inorder: ";
                    Rinorder(root);
                    cout << endl;
                    break;

                case 2:
                    cout << "Recursive Preorder: ";
                    Rpreorder(root);
                    cout << endl;
                    break;

                case 3:
                    cout << "Recursive Postorder: ";
                    Rpostorder(root);
                    cout << endl;
                    break;

                case 4:
                    cout << "Iterative Inorder: ";
                    inorder(root);
                    cout << endl;
                    break;

                case 5:
                    cout << "Iterative Preorder: ";
                    preorder(root);
                    cout << endl;
                    break;

                case 6:
                    cout << "Iterative Postorder: ";
                    Opostorder(root);   
                    cout << endl;
                    break;
                }
            } while (tchoice != 7);
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
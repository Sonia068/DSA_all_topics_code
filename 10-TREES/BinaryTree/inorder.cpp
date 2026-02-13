//<----------------INORDER TRAVERSAL ------------------------------>
#include <iostream>
#include <stack>
#include <queue>
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
// TC-O(n)  ,  SC-O(n):
node* insert(node* root,int k){
   if(root==NULL) {
     root=new node(k);
     return root;
   }

     queue<node*>q;
     q.push(root);
        while(!q.empty()){
            node* curr=q.front();
            q.pop();

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            else{
                curr->left=new node(k);
                return root;
            }


            
            if(curr->right!=NULL){
                q.push(curr->right);
            }
            else{
                curr->right=new node(k);
                return root;
            }

            
        }

        return root;
     }

// Inorder Traversal :
     // Recursive approach:
   void inorderrec(node* root){
      if(root==NULL) return ;

    inorderrec(root->left);
    cout<<root->data<<" ";
    inorderrec(root->right);

}

// Non recursive approach :
// or   (Iterative):
    void inOrder(node* root) {
       stack <node*> st;
       node* curr=root;
       while(curr!=NULL || !st.empty()){
         if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
         }
         else{
              node* res=st.top();
              st.pop();
              cout<<res->data<<" ";
              curr=res->right;
         }
       }
       return ;
    }
};





int main(){
    node nn;
    node* root=NULL;

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    int value;
    cout<<"Enter "<<n<<" values:\n";

    for(int i=0;i<n;i++){
        cin>>value;
        root = nn.insert(root,value);
    }

    cout<<"\nInorder Traversal (Recursive): ";
    nn.inorderrec(root);


    cout<<"\nInorder Traversal (Iterative): ";
    nn.inOrder(root);

    return 0;



}





/*
//Binary tree Inorder Traversal :

// Recursive
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

//      or (Global)

class Solution {
public:
    vector<int> result; // renamed ans → result

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        result.push_back(root->val);  // use result instead of ans
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        result.clear(); // make sure it’s empty before use
        inorder(root);
        return result;
    }
};


// or   (Iterative)
class Solution {
  public:
    vector<int> inOrder(Node* root) {
      vector<int>ans;
       stack <Node*> st;
       Node* curr=root;
       while(curr!=NULL || !st.empty()){
         if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
         }
         else{
              Node* res=st.top();
              st.pop();
              ans.push_back(res->data);
              curr=res->right;
         }
       }
       return ans;
    }
};
    
//   or (Built in )

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return {};

        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};

// Or 
vector<int> inorder(TreeNode* root) {
    if (!root) return {};
    vector<int> left = inorder(root->left);
    vector<int> right = inorder(root->right);
    
    left.push_back(root->val);           // add root in between
    left.insert(left.end(), right.begin(), right.end()); // merge right
    return left;                         // return combined vector
}

*/


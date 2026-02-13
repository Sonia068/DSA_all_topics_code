//<----------------PREORDER TRAVERSAL ------------------------------>
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

// Preorder Traversal :
     // Recursive approach:
   void preorderrec(node* root){
      if(root==NULL) return ;

    cout<<root->data<<" ";
    preorderrec(root->left);
    preorderrec(root->right);

}

// Non recursive approach :
// or   (Iterative):
    void preOrder(node* root) {
       stack <node*> st;
       node* curr=root;
       while(curr!=NULL || !st.empty()){
         if(curr!=NULL){
            st.push(curr);
            cout<<curr->data<<" ";
            curr=curr->left;
         }
         else{
              node* res=st.top();
              st.pop();
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

    cout<<"\nPreorder Traversal (Recursive): ";
    nn.preorderrec(root);


    cout<<"\nPreorder Traversal (Iterative): ";
    nn.preOrder(root);

    return 0;



}





/*
//Binary tree preorder Traversal :

// Recursive
class Solution {
  public:
  
  void pre(Node*root,vector<int>&ans){
       if(root==NULL){
            return ;
}
            ans.push_back(root->data);
            pre(root->left,ans);
            pre(root->right,ans);
            
            return ;
        } 
    vector<int> preOrder(Node* root) {
        vector<int>ans;
           pre(root,ans);
           return ans;
        }
        
    };

//Non-recursive :
class Solution {
  public:
    vector<int> preOrder(Node* root) {
      vector<int>ans;
       stack <Node*> st;
       Node* curr=root;
       while(curr!=NULL || !st.empty()){
         if(curr!=NULL){
            st.push(curr);
            ans.push_back(res->data);
            curr=curr->left;
         }
         else{
              Node* res=st.top();
              st.pop();
              curr=res->right;
         }
       }
       return ans;
    }
};

*/

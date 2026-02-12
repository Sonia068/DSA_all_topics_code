// ------DELETE A NODE IN A BINARY TREE:
// Starting at the root, find the deepest and rightmost node in the binary tree and the node which we want to delete. 
// Replace the deepest rightmost node’s data with the node to be deleted. 
// Then delete the deepest rightmost node.

#include <iostream>
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


     void delDeepest(node* root,node* delnode){
        queue<node*> q;
        q.push(root);

        node* curr;
        while(!q.empty()){
          curr=q.front();
          q.pop();

          if(curr==delnode){
             curr=NULL;
             delete (delnode);
             return;
          }

          if(curr->left){
            if(curr->left==delnode){
              curr->left=NULL;
              delete(delnode);
              return;
            }
             q.push(curr->left);
            
          }
`
          if(curr->right){
            if(curr->right==delnode){
              curr->right=NULL;
              delete(delnode);
              return;
            }
             q.push(curr->right);
            
          }

        }
        }
     



     //DELETION :
     node* del(node* root,int key){
       if(root==NULL){
         return root;
       }

      if(root->left==NULL && root->right==NULL){
        if(root->data==key){
          delete root;
           return NULL;
       }
       return root;
     }

     queue<node*> q;
     node* curr;
     node* keynode=NULL;
     q.push(root);

     while(!q.empty()){
         curr=q.front();
         q.pop();

         if(curr->data==key){
          keynode=curr;
         }

         
         if(curr->left){
           q.push(curr->left);
         }

         if(curr->right){
           q.push(curr->right);
         }

     }
  
     if(keynode!=nullptr){
       int x=curr->data;
       keynode->data=x;
       delDeepest(root,curr);
        
     }

     return root;
    }




     // Recursive approach:
   void inorderrec(node* root){
      if(root==NULL) return ;

    inorderrec(root->left);
    cout<<root->data<<" ";
    inorderrec(root->right);

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

     cout<<"\nInorder Before Deletion: ";
    nn.inorderrec(root);

    int key;
    cout<<"\nEnter value to delete: ";
    cin>>key;

    root = nn.del(root,key);

    cout<<"\nInorder After Deletion: ";
    nn.inorderrec(root);

    return 0;
}



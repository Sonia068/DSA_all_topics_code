//<----------level of key in the binary tree ------------->
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

// With recursion :
int countrec(node* root){
    if(!root) return 0;

    if(!root->left && !root->right) return 1;

    return countrec(root->left)+countrec(root->right);
}


// Without recursion:  (using queue)

int getLevel(node* root,int key) {
    if(!root)  return 0;
   
    queue<node*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
      int size=q.size();
      for(int i=0;i<size;i++){
        node* curr= q.front();
        q.pop();

        if(curr->data==key){return level;}

        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }

     level++;
    }

    return 0;
}


// With recursion: 
int RgetLevel(node* root,int target,int level ){
    if(!root) return 0;

    if(root->data==target){
        return level;
    }

    int leftLevel=RgetLevel(root->left,target,level+1);
    if(leftLevel!=0){
        return leftLevel;
    }

    return RgetLevel(root->right,target,level+1);

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

    int key;
    cout<<"Enter  the key:"<<endl;
    cin>>key;

    cout<<"Level of key node (without recursion (using queue)):"<<endl;
    cout<<nn.getLevel(root,key)<<endl;

    cout<<"Level of key node (with recursion):"<<endl;
    cout<<nn.RgetLevel(root,key,1)<<endl;
    return 0;

}
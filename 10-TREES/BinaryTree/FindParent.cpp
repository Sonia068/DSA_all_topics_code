//<----------Find parent node ------------->
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



// Without recursion:  (using queue)
int findParent(node* root, int target) {
    if (root == NULL) {
        return -1;
    }

    if (root->data == target) {
        return -1;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        if (current->left) {
            if (current->left->data == target) {
                return current->data;  
            }
            q.push(current->left);
        }

        if (current->right) {
            if (current->right->data == target) {
                return current->data;  
            }
            q.push(current->right);
        }
    }

    return -1; 
}




// With recursion: 
int RfindParent(node* root,int target,int parent){
    if(!root) return -1;

    if(root->data==target){
        return parent;
    }

    int leftSearch=RfindParent(root->left,target,root->data);
    
    if(leftSearch!=-1){
        return leftSearch;
    }


  return RfindParent(root->right,target,root->data);

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

  cout<<"Parent Node (with recursion):"<<endl;
   cout<<nn.RfindParent(root,key,-1);
  

  cout<<endl;


  cout<<"Parent Node (without recursion(queue)):"<<endl;
  cout<<nn.findParent(root, key)<<endl;


  cout<<endl;



    return 0;

}
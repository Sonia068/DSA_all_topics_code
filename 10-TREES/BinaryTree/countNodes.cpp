//<----------Count all Nodes------------->
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

// Without Recursion :(level order approach)
     int countNodes(node* root){
        int count=0;
        if(!root) return 0;

        queue<node*>q;
        q.push(root);

        while(!q.empty()){
            node* curr=q.front();
            q.pop();
            count+=1;

            if(curr->left!=NULL){
                q.push(curr->left);
            }

            
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        return count;
     }

// With recursion :
int countrec(node* root){
    if(!root) return 0;

    return 1+countrec(root->left)+countrec(root->right);
}

// Without Recursion :(DFS approach)
int countnodes(node* root){
    stack<node*>s;
    int count=0;
    node* curr=root;
    while(curr!=NULL ||!s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }

        else{
            node* n=s.top();
            s.pop();
            count+=1;
            curr=n->right;
        }
    }
    return count;
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


    cout<<"Count Of Nodes(Without recursion):"<<endl;
    cout<<nn.countNodes(root)<<endl;

    cout<<"Count Of Nodes(With recursion):"<<endl;
    cout<<nn.countrec(root)<<endl;

    cout<<"Count Of Nodes:"<<endl;
    cout<<nn.countnodes(root)<<endl;
    return 0;

}
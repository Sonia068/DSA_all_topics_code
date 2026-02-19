//<----------Maximum Depth or Height Of  a Binary Tree------------->
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


// With  recursion :
  int heightrec(node* root) {
        if(!root) return -1;
        
        if(!root->left && !root->right){
            return 0;
        }
        
        int lheight=height(root->left);
         int rheight=height(root->right);
        
        return max(lheight,rheight)+1;
        
    }


// Without Recursion :
int height(node* root){
       queue<node*>q;
       q.push(root);
       int depth=0;

       while(!q.empty()){
           int levelsize=q.size();
           
           for(int i=0;i<levelsize;i++){
               node* curr=q.front();
               q.pop();
           
           
           if(curr->left)   q.push(curr->left);
           if(curr->right)  q.push(curr->right);
           }
           
       depth++;
       }
       return  depth-1;
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


   
    cout<<"Height Of Tree(Without recursion):"<<endl;
    cout<<nn.height(root)<<endl;

    cout<<"Height Of Tree(With recursion):"<<endl;
    cout<<nn.heightrec(root)<<endl;

   return 0;

}
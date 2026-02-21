//<----------MIN VALUE (BST)  ------------->
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

// Using inorder traversal :
void inorder(node* root, vector<int>& sortedInorder) {
  
    if (root == nullptr) return;

    inorder(root->left, sortedInorder);

    sortedInorder.push_back(root->data);

    inorder(root->right, sortedInorder);
}


int InorderminValue(node* root) {
    if (root == nullptr) {
        return -1;
    }
    
    vector<int> sortedInorder;

    inorder(root, sortedInorder);
    
    return sortedInorder[0];
}



// Iterative Approach :
   int minValue(node* root) {
        if(root==NULL) return 0;
        
        node* curr=root;
        while(curr->left!=NULL){
            curr=curr->left;
        }
        return curr->data;
        
    }




// Recursive approach :
   int RminValue(node* root) {
        if(root==NULL) return 0;

        if(root->left==NULL){
            return root->data;
        }

        minValue(root->left);
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

   cout<<"Min Value(iterative)):"<<endl;
   cout<<nn.minValue(root);
  

  cout<<endl;

  cout<<"Min Value (recursive):"<<endl;
  cout<<nn.RminValue(root)<<endl;


  cout<<endl;
   
  cout<<"Min Value (inorder):"<<endl;
  cout<<nn.InorderminValue(root)<<endl;


    return 0;

}
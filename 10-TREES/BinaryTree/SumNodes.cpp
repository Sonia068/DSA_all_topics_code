//<----------------SUM OF NODES ------------------------------>
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


// Without Recursion:
int sumNodes(node* root){
    if(root == NULL)
        return 0;

    stack<node*> st;
    st.push(root);

    int sum = 0;

    while(!st.empty()){
        node* curr = st.top();
        st.pop();

        sum += curr->data;

        if(curr->right)
            st.push(curr->right);

        if(curr->left)
            st.push(curr->left);
    }

    return sum;
}

// With Recursion:
int sumNodesrec(node* root){
    if(root == NULL)
        return 0;

    return root->data 
           + sumNodes(root->left)
           + sumNodes(root->right);
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

    cout<<"\nSum of Nodes (Non-Recursive): "<<nn.sumNodes(root);


    cout<<"\nSum of Nodes (Recursive): "<< nn.sumNodesrec(root);




    return 0;
}


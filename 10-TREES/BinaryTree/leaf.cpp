//<----------Count all leaf Nodes------------->
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


// Wihtout recursion:  (using stack)
int ScountLeafNodes(node* root) {
    if (root == NULL)
        return 0;

    stack<node*> st;
    st.push(root);
    int count = 0;

    while (!st.empty()) {
        node* temp = st.top();
        st.pop();

        if (temp->left == NULL && temp->right == NULL)
            count++;

        if (temp->right)
            st.push(temp->right);

        if (temp->left)
            st.push(temp->left);
    }

    return count;
}


// Wihtout recursion:  (using queue)
#include <queue>

int QcountLeafNodes(node* root) {
    if (root == NULL)
        return 0;

    queue<node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp->left == NULL && temp->right == NULL)
            count++;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
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


    cout<<"Count Of leaf Nodes(With recursion):"<<endl;
    cout<<nn. countrec(root)<<endl;

    cout<<"Count Of leaf Nodes(Without recursion(stacck)):"<<endl;
    cout<<nn.ScountLeafNodes(root)<<endl;

    cout<<"Count Of leaf Nodes(using queue):"<<endl;
    cout<<nn.QcountLeafNodes(root)<<endl;
    return 0;

}
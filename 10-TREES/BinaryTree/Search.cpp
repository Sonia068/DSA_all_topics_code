//<----------Search of key in the binary tree ------------->
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
// Using string type is a bad practice:
string searchNode(node* root,int key) {
    if(!root)  return "root doesn't exist";
   
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr= q.front();
        q.pop();

        if(curr->data==key){return "key is found";}

        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }

    return "key is not found";

    }




// Without recursion:  (using stack)
    string SsearchNode(node* root, int key) {
    if (!root)
        return "root doesn't exist";

    stack<node*> st;
    st.push(root);

    while (!st.empty()) {
        node* curr = st.top();
        st.pop();

        if (curr->data == key)
            return "key is found";

        if (curr->right)
            st.push(curr->right);


        if (curr->left)
            st.push(curr->left);
    }

    return "key is not found";
}


// With recursion: 
bool RsearchNode(node* root,int target){
    if(!root) return false;

    if(root->data==target){
        return true;
    }

    bool res1=RsearchNode(root->left,target);
    if(res1) return true;


    bool res2=RsearchNode(root->right,target);
    return res2;

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

  cout<<"Search key node (with recursion):"<<endl;
  bool s=nn.RsearchNode(root,key);
  if(s==0){
    cout<<"key is not found"<<endl;
  }
  else{
    cout<<"key is found"<<endl; 
  }

  cout<<endl;


  cout<<"Search key node (without recursion(queue)):"<<endl;
  cout<<nn.searchNode(root, key)<<endl;


  cout<<endl;
  
  cout<<"Search key node (without recursion(stack)):"<<endl;
  cout<<nn.SsearchNode(root, key)<<endl;



    return 0;

}
//<----------------POSTORDER TRAVERSAL ------------------------------>
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

// Postorder Traversal :
     // Recursive approach:
   void postorderrec(node* root){
      if(root==NULL) return ;

    postorderrec(root->left);
    postorderrec(root->right);
    cout<<root->data<<" ";
}

// Non recursive approach :(Using two stack)
    void NNpostOrder(node* root) {
        if(root==NULL) return;
       stack <node*> st1,st2;
       st1.push(root);
       while(!st1.empty()){
        node*s=st1.top();
         st1.pop();
         st2.push(s);
         
         if(s->left!=NULL){
            st1.push(s->left);
         }

           
         if(s->right!=NULL){
            st1.push(s->right);
         }
        }



         while(!st2.empty()){
            node*d=st2.top();
            st2.pop();
            cout<<d->data<<" ";
         }
         }


    // Using One stack :
    void NpostOrder(node* root){
        if(root==NULL) return;
        node* temp=root;
        stack <node*>st;
        node* lastNode=NULL;

        while(temp!=NULL || !st.empty()){
            if(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }

            else{
                node* topNode=st.top();
                if(topNode->right!=NULL  && lastNode!=topNode->right){
                    temp=topNode->right;
                }

                else{
                    cout<< topNode->data<<" ";
                    lastNode=topNode;
                    st.pop();
                }
            }
        }
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

    cout<<"\nPostorder Traversal (Recursive): ";
    nn.postorderrec(root);


    cout<<"\nPostorder Traversal (Non-Recursive- Using Two stack): ";
    nn.NNpostOrder(root);

    cout<<"\nPostorder Traversal (Non-Recursive-Using one stack): ";
    nn.NpostOrder(root);

    return 0;



}


/*

// Using flag 
struct stackNode{
    node* ptr;
    int flag;
}

void postOrder(node* root){
    if(root==NULL)  return;

    stack(stackNode(root,0));           // stack <pair<node*,int>>st;  (if using built in without struct)
    st.push({root,0});
    while(!st.empty()){
      node* topNode=st.top();
      st.pop(); 
      node* curr=topNode.ptr;          // node* curr=topNode.first;
      int flag=topNode.flag;           // int flag=topNode.second;

      if(flag==1){
        cout<<curr->data<<" ";
      }

      else{
        st.push({curr,1});
        if(curr->right!=NULL) {
            st.push({curr->right,0});
        }

        if(curr->left!=NULL) {
            st.push({curr->left,0});
        }
      }
    }
}

*/
//<----Binary tree creation(User's input) --------->
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*left,*right;

    node(){
        data=0;
        left=NULL;
        right=NULL;
    }

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* create(){
    int x;
    node* nn=new node;
    cout<<"Enter the data(-1 or any other data)" <<endl;
    cin>>x;
    if(x==-1){
        return 0;
    }

    nn->data=x;
    cout<<"Enter left of "<<x<<endl;
    nn->left=create();

    cout<<"Enter the right of "<<x<<endl;
    nn->right=create();

    return nn;


    }

    void inorder(node*root){
        if(root==NULL ){
            return;
        }
        else{
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);

        }
        
    }

int main(){

    node* root=create();
    inorder(root);

    return 0;

}



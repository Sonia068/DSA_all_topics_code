//<--------- HANDLE DUPLICATES (COUNT) IN AVL TREE------------>
#include <iostream>
#include <algorithm>
using namespace std;

class node{

private:
    int player_id;
    int scores;
    node* left;
    node* right;
    int height;
    int count ;

public:

    node(){
        player_id=0;
        scores=0;
        left=NULL;
        right=NULL;
        height=1;
        count=1;
    }

    node(int id,int s){
        player_id=id;
        scores=s;
        left=NULL;
        right=NULL;
        height=1;
        count=1;
    }

    int getHeight(node* root){
        if(root==NULL) return 0;
        return root->height;
    }

    int getbalance(node* root){
        if(root==NULL) return 0;
        return getHeight(root->left)-getHeight(root->right);
    }

    node* rightRotate(node* y){

        node* x=y->left;
        node* T2=x->right;

        x->right=y;
        y->left=T2;

        y->height=1+max(getHeight(y->left),getHeight(y->right));
        x->height=1+max(getHeight(x->left),getHeight(x->right));

        return x;
    }

    node* leftRotate(node* x){

        node* y=x->right;
        node* T2=y->left;

        y->left=x;
        x->right=T2;

        x->height=1+max(getHeight(x->left),getHeight(x->right));
        y->height=1+max(getHeight(y->left),getHeight(y->right));

        return y;
    }

    node* minValueNode(node* root){

        node* curr=root;

        while(curr->left!=NULL)
            curr=curr->left;

        return curr;
    }


// RECURSIVE INSERT
    node* Rinsert(node* root,int id,int scores){

        if(root==NULL)
            return new node(id,scores);

        if(id < root->player_id)
            root->left=Rinsert(root->left,id,scores);

        if(id > root->player_id)
            root->right=Rinsert(root->right,id,scores);

        if(id == root->player_id && scores == root->scores){
           root->count++;
            return root;
}
        root->height=1+max(getHeight(root->left),getHeight(root->right));

        int balance=getbalance(root);

        // LL
        if(balance>1 && id < root->left->player_id)
            return rightRotate(root);

        // RR
        if(balance<-1 && id > root->right->player_id)
            return leftRotate(root);

        // LR
        if(balance>1 && id > root->left->player_id){
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }

        // RL
        if(balance<-1 && id < root->right->player_id){
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }


// RECURSIVE DELETE
    node* Rdelete(node* root,int id,int scores){

        if(root==NULL)
            return root;

        if(id < root->player_id)
            root->left=Rdelete(root->left,id,scores);

        else if(id > root->player_id)
            root->right=Rdelete(root->right,id,scores);

        

            if(id == root->player_id && scores == root->scores){
             // Handle duplicates
             if(root->count > 1){
                 root->count--;
                 return root;
             }
             // Node with only one child or no child
             if(root->left==NULL || root->right==NULL){

                node* temp;

                if(root->left)
                    temp=root->left;
                else
                    temp=root->right;

                if(temp==NULL){
                    temp=root;
                    root=NULL;
                }
                else
                    // One child case
                node *temp = root->left ? root->left : root->right;
				delete root; 
				return temp; 
        }
            

            else{
                // Node with two children: Get the inorder successor (smallest in the right subtree) or predecessor (largest in the left subtree)

                node* temp=minValueNode(root->right);

                root->player_id=temp->player_id;
                root->scores=temp->scores;

                root->right=Rdelete(root->right,temp->player_id,temp->scores);
            }
        }

        if(root==NULL)
            return root;

        root->height=1+max(getHeight(root->left),getHeight(root->right));

        int balance=getbalance(root);

        // LL
        if(balance>1 && getbalance(root->left)>=0)
            return rightRotate(root);

        // LR
        if(balance>1 && getbalance(root->left)<0){
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }

        // RR
        if(balance<-1 && getbalance(root->right)<=0)
            return leftRotate(root);

        // RL
        if(balance<-1 && getbalance(root->right)>0){
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }


    void inorder(node* root){

        if(root!=NULL){

            inorder(root->left);
            cout<<"ID:"<<root->player_id<<" Score:"<<root->scores<< "("<<root->count << ")"<< " ";
            inorder(root->right);

        }
    }
};


int main(){

    node nn;
    node* root=NULL;

    int n,id,scores;

    cout<<"Enter number of players: ";
    cin>>n;

    for(int i=0;i<n;i++){

        cout<<"Enter player ID and score "<<i+1<<": ";
        cin>>id>>scores;

        root=nn.Rinsert(root,id,scores);
    }

    cout<<"\nInorder Traversal:\n";
    nn.inorder(root);

    int delID;
    int delScores;

    cout<<"\nEnter player ID and score to delete: ";
    cin>>delID>>delScores;

    root=nn.Rdelete(root,delID,delScores);

    cout<<"\nAfter Deletion:\n";
    nn.inorder(root);

}
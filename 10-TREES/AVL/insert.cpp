#include <iostream>
#include <stack>
using namespace std;

class node{
private:
    int player_id;
    int scores;
    node* left;
    node* right;
    int height;

public:
    node(){
        player_id=0;
        scores=0;
        left=NULL;
        right=NULL;
        height=1;
    }

    node(int d,int s){
        player_id=d;
        scores=s;
        left=NULL;
        right=NULL;
        height=1;
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


//  RECURSIVE INSERT
    node* Rinsert(node* root,int id,int scores){

        if(root==NULL)
            return new node(id,scores);

        if(id < root->player_id)
            root->left=Rinsert(root->left,id,scores);

        else if(id > root->player_id)
            root->right=Rinsert(root->right,id,scores);

        else
            return root;

        root->height=1+max(getHeight(root->left), getHeight(root->right));

        int balance=getbalance(root);

        // LL
        if(balance>1 && id < root->left->player_id)
            return rightRotate(root);

        // RR
        else if(balance<-1 && id > root->right->player_id)
            return leftRotate(root);

        // LR
        else if(balance>1 && id > root->left->player_id){
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }

        // RL
        else if(balance<-1 && id < root->right->player_id){
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }


// NON-RECURSIVE INSERT
    node* insert(node* root, int id,int s) {

        stack<node*> st;
        node* curr = root;
        node* parent = NULL;

        while (curr != NULL) {
            parent = curr;
            st.push(curr);

            if (id < curr->player_id)
                curr = curr->left;
            else if (id > curr->player_id)
                curr = curr->right;
            else
                return root;
        }

        node* newNode = new node(id,s);

        if (parent == NULL)
            return newNode;

        if (id < parent->player_id)
            parent->left = newNode;
        else
            parent->right = newNode;

        while (!st.empty()) {

            node* temp = st.top();
            st.pop();

            temp->height = 1 + max(getHeight(temp->left),getHeight(temp->right));

            int balance = getbalance(temp);

            // LL
            if (balance > 1 && id < temp->left->player_id) {
                if (st.empty())
                    root = rightRotate(temp);
                else {
                    node* p = st.top();
                    if (p->left == temp)
                        p->left = rightRotate(temp);
                    else
                        p->right = rightRotate(temp);
                }
            }

            // RR
            else if (balance < -1 && id > temp->right->player_id) {
                if (st.empty())
                    root = leftRotate(temp);
                else {
                    node* p = st.top();
                    if (p->left == temp)
                        p->left = leftRotate(temp);
                    else
                        p->right = leftRotate(temp);
                }
            }

            // LR
            else if (balance > 1 && id > temp->left->player_id) {
                temp->left = leftRotate(temp->left);
                if (st.empty())
                    root = rightRotate(temp);
                else {
                    node* p = st.top();
                    if (p->left == temp)
                        p->left = rightRotate(temp);
                    else
                        p->right = rightRotate(temp);
                }
            }

            // RL
            else if (balance < -1 && id < temp->right->player_id) {
                temp->right = rightRotate(temp->right);
                if (st.empty())
                    root = leftRotate(temp);
                else {
                    node* p = st.top();
                    if (p->left == temp)
                        p->left = leftRotate(temp);
                    else
                        p->right = leftRotate(temp);
                }
            }
        }

        return root;
    }

    void inorder(node* root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->player_id<<" ";
            inorder(root->right);
        }
    }
};


int main(){

    node nn;
    node* root=NULL;

    int n,id,scores;

    cout<<"Enter number of nodes: ";
    cin>>n;

//  cout<<"Enter "<<n<<" values:\n";
//     for(int i=0;i<n;i++){
//      cout<<"Enter id and scores "<<i+1<<":"<<endl;
//         cin>>id>>scores;
//         root = nn.insert(root,id,scores);
//     }

//     cout<<"Inorder Traversal: ";
//     nn.inorder(root);


 cout<<"Enter "<<n<<" values:\n";
    for(int i=0;i<n;i++){
     cout<<"Enter id and scores "<<i+1<<":"<<endl;
        cin>>id>>scores;
        root = nn.Rinsert(root,id,scores);
    }

    cout<<"Inorder Traversal: ";
    nn.inorder(root);

    return 0;
}
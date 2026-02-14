//<----------------LEVELORDER TRAVERSAL ------------------------------>
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

void levelOrder(node*root){
    if(root==NULL) return ;

    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
        q.push(curr->right);
    }
}

}


// Level Wise Print :
void levelWisePrint(node* root){
    if(root == NULL) return;

    queue<node*> q;
    q.push(root);

    int level = 0;

    while(!q.empty()){
        int size = q.size();   

        cout << "Level " << level << ": ";

        for(int i = 0; i < size; i++){
            node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if(curr->left)  q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        cout << endl;
        level++;
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

    cout<<"\nLevelorder Traversal (Non-Recursive): ";
    nn.levelOrder(root);


    
    cout<<"\nLevelorder Traversal (Non-Recursive): ";
    nn.levelWisePrint(root);




    return 0;
}


/*

// Using Recursion :
int height(node* root){
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

void printGivenLevel(node* root, int level){
    if(root == NULL) return;

    if(level == 1){
        cout << root->data << " ";
        return;
    }

    printGivenLevel(root->left, level - 1);
    printGivenLevel(root->right, level - 1);
}


void levelWiseRecursive(node* root){
    int h = height(root);

    for(int i = 1; i <= h; i++){
        cout << "Level " << i-1 << ": ";
        printGivenLevel(root, i);
        cout << endl;
    }
}

*/


//<----------FLOOR VALUE (BST)  ------------->
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


// Iterative Approach :
 int Rfloor(node* root, int x) {
       int floorValue=-1;
       
       while(root!=NULL){
           
         if(x>root->data){
            floorValue=root->data;
            root=root->right;
    }
    
         else if(x<root->data){
           root=root->left;
       }
       
         else {
            return root->data;
       }
       }
       
    return floorValue;
        
    }



//Recursive approach :

int floor(node* root, int x) {
  
  
   if (root == nullptr) {
        return -1; 
    }

    if (root->data == x) {
        return root->data;
    }

   
    if (root->data > x) {
        return floor(root->left, x);
    }


    int floorValue = floor(root->right, x);


    return (floorValue <= x && floorValue != -1)
                              ? floorValue : root->data;
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
    int  y;

    cout<<"Enter the value :"<<endl;
    cin>>y;

   cout<<"Floor Value(iterative)):"<<endl;
   cout<<nn.floor(root,y);
  

  cout<<endl;

  cout<<"Floor Value (recursive):"<<endl;
  cout<<nn.Rfloor(root,y)<<endl;




    return 0;

}
//Merge two sorted lists :
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list2;

        ListNode dummy;    // dummy means before head so that we do not need to do cases for head 
        ListNode*tail=&dummy;  // here we points the tail to dummy pointer 
        while(list1 && list2){
            if(list1->val<list2->val){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }

        if(list1) tail->next=list1;
        if(list2) tail->next=list2; 

        return dummy.next;  
    }


          
void createlist(ListNode*&head,int val){
    ListNode*nn=new ListNode(val);
    if(head==NULL){
        head=nn;
    }
    else{
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
           temp->next=nn;
    }
}


void print(ListNode* &head){
    if(head==NULL){
        cout<<"LL is empty";
    }
    else{
        ListNode*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
}
};



int main(){
    Solution s;
    ListNode* head1 = NULL; 
    ListNode* head2 = NULL; 

    int n1,n2;

    cout << "Enter number of values : ";
    cin >> n1;
    for(int i = 0; i < n1; i++){
        int val;
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        s.createlist(head1, val);
    }

     cout << "Enter number of values : ";
    cin >> n2;
    for(int i = 0; i < n2; i++){
        int val;
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        s.createlist(head2, val);
    }

   cout<<"First Linked List:";
    s.print(head1);


     cout<<"Second Linked List:";
    s.print(head2);


    ListNode* result = s.mergeTwoLists(head1,head2);
    cout << "Merged two linked List : ";
    s.print(result);

    return 0;
}

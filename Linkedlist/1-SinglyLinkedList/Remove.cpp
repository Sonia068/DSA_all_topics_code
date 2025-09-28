// REMOVE NTH NODE FROM END OF LIST :
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* first=head;
       ListNode*second=head;

       for(int i=0;i<n;i++){
        if(second==NULL) return head;
        second=second->next;
       }
       if(second==NULL){
        ListNode*temp=head;
        head=head->next;
        delete temp;
        return head;

       }

       while(second->next!=NULL){
        first=first->next;
        second=second->next;
       }
       
       ListNode*temp=first->next;
       first->next=first->next->next;
       delete temp;

       return head;
    
        
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
    ListNode* head = NULL; 

    int n1;

    cout << "Enter number of values : ";
    cin >> n1;
    for(int i = 0; i < n1; i++){
        int val;
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        s.createlist(head, val);
    }

    cout<<"Before removing the node from the  Linked List:";
    s.print(head);

    int n;
    cout<<"Enter the node index you want to delete:"<<endl;
    cin>>n;
    ListNode* result = s.removeNthFromEnd(head,n);
    cout << "After removing, the linked list : ";
    s.print(result);

    return 0;
}

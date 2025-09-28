// SWAP  NODES  IN PAIRS:
#include <iostream>
#include <vector>
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
    ListNode* swapPairs(ListNode* head){
    ListNode dummy(0);
    dummy.next=head;
    ListNode*prev=&dummy;

    
    while(head!=NULL && head->next!=NULL){
        ListNode*first=head;
        ListNode* second=head->next;

        prev->next=second;
        first->next=second->next;
        second->next=first;

        prev=first;
        head=first->next;

    }

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


int main() {
Solution s;
ListNode* head = nullptr;

int n;
cout << "Enter number of values in the list: ";
cin >> n;

for (int i = 0; i < n; i++) {
    int val;
    cout << "Enter value " << i + 1 << ": ";
    cin >> val;
    s.createlist(head, val);
}

cout << "Original Linked List: ";
s.print(head);

ListNode* result = s.swapPairs(head);

cout << "Linked List after swapping pairs: ";
s.print(result);

return 0;


}

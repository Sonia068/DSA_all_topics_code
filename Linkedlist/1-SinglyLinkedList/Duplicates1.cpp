//REMOVE DUPLICATES FROM SORTED LIST I:
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
    ListNode* deleteDuplicates(ListNode* head) {
     if(head==NULL) return NULL;
     if(head->next==NULL) return head;
     else{
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->val==curr->next->val){
                curr->next=curr->next->next;
             //   ListNode*temp=curr->next;
             //   delete temp;
            }
            else{
                curr=curr->next;
            }
        }

        }
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

ListNode* result = s.deleteDuplicates(head);

cout << "Linked List after removing duplicates: ";
s.print(result);

return 0;


}

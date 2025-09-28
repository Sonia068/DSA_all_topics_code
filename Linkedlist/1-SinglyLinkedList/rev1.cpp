// REVERSE SUBLIST(between)
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* node = nullptr;

  
        for (int i = 0; i < right - left; i++) {
            node = curr->next;
            curr->next = node->next;
            node->next = prev->next;
            prev->next = node;
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

int l;
cout<<"Enter the left value:";
cin>>l;

int r;
cout<<"Enter the right value:";
cin>>r;


ListNode* result = s.reverseBetween(head,l,r);

cout << "Linked List after reversing: ";
s.print(result);

return 0;


}

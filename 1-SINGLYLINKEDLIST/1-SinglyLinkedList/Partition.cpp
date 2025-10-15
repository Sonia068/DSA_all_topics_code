//PARTITION LIST (all nodes less than x come before nodes greater than or equal to x.)
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
    ListNode* partition(ListNode* head, int x) {
         if(head==NULL || head->next==NULL) return head;

        ListNode* smallerhead=NULL;
        ListNode* smallertail=NULL;
        ListNode* biggerhead=NULL;
        ListNode* biggertail=NULL;
        ListNode* temp=head;

        while(temp!=  NULL){
            if(temp->val>=x){
                if(biggerhead==NULL){
                    biggerhead=biggertail=temp;
                }
                else{
                    biggertail->next=temp;
                    biggertail=temp;
                }
            }

            else{
                if(smallerhead==NULL){
                    smallerhead=smallertail=temp;
                }
                else{
                    smallertail->next=temp;
                    smallertail=temp;
                }
            }
            temp=temp->next;
        
        }

        if(biggertail)    biggertail->next=NULL;

        if(!smallerhead)  return biggerhead;

        smallertail->next=biggerhead;
        return smallerhead;
       
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

int x;
cout<<"Enter the partition value:";
cin>>x;
ListNode* result = s. partition(head,x);

cout << "Linked List after removing duplicates: ";
s.print(result);

return 0;


}

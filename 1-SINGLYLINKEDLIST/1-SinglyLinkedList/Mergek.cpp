//Merge K sorted lists :
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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        ListNode* merged = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            merged = mergeTwoLists(merged, lists[i]);
        }
        return merged;
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
int k;
cout << "Enter number of linked lists: ";
cin >> k;


vector<ListNode*> lists(k);

for (int i = 0; i < k; i++) {
    int n;
    cout << "Enter number of values for list " << i + 1 << ": ";
    cin >> n;
    for (int j = 0; j < n; j++) {
        int val;
        cout << "Enter value " << j + 1 << ": ";
        cin >> val;
        s.createlist(lists[i], val);
    }
    cout << "List " << i + 1 << ": ";
    s.print(lists[i]);
}

ListNode* result = s.mergeKLists(lists);
cout << "Merged K linked list: ";
s.print(result);

return 0;

}

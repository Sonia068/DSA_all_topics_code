//SUM OF TWO LINKED LIST :
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        int carry=0;
        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            ListNode*node=new ListNode(sum%10);
            if(head==NULL){
                head=tail=node;
            }
            else{
                tail->next=node;
                tail=node;
            }
            l1=l1->next;
            l2=l2->next;
        }

        while(l1){
            int sum=l1->val+carry;
            carry=sum/10;
            ListNode*node=new ListNode(sum%10);
            tail->next=node;
            tail=node;
            l1=l1->next;
        }

        while(l2){
            int sum=l2->val+carry;
            carry=sum/10;
            ListNode*node=new ListNode(sum%10);
            tail->next=node;
            tail=node;
            l2=l2->next;
        }

        if(carry){
            ListNode* node=new ListNode(carry);
            tail->next=node;
            tail=node;
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



int main(){
    Solution s;
    ListNode* head1 = NULL; 
    ListNode* head2 = NULL; 
    int n1, n2;

    cout << "Enter number of values for first list: ";
    cin >> n1;
    for(int i = 0; i < n1; i++){
        int val;
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        s.createlist(head1, val);
    }

 
    cout << "Enter number of values for second list: ";
    cin >> n2;
    for(int i = 0; i < n2; i++){
        int val;
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        s.createlist(head2, val);
    }

    cout << "First linked list: ";
    s.print(head1);
    cout << "Second linked list: ";
    s.print(head2);

    ListNode* result = s.addTwoNumbers(head1, head2);
    cout << "Sum of the two linked lists: ";
    s.print(result);

    return 0;
}

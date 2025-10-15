// Polynomial addition using SLL:
#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int pow;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void create(int coeff, int pow) {
        Node* newNode = new Node(coeff, pow);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->pow;
            if (temp->next)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }


    static Node* polyAdd(Node* h1, Node * h2) {
        Node* dummy = new Node(0, 0);
        Node* tail = dummy;

        while (h1 && h2) {
            if (h1->pow == h2->pow) {
                tail->next = new Node(h1->coeff + h2->coeff, h1->pow);
                h1 = h1->next;
                h2 = h2->next;
            } else if (h1->pow > h2->pow) {
                tail->next = new Node(h1->coeff, h1->pow);
                h1 = h1->next;
            } else {
                tail->next = new Node(h2->coeff, h2->pow);
                h2 = h2->next;
            }
            tail = tail->next;
        }

        while (h1) {
            tail->next = new Node(h1->coeff, h1->pow);
            tail = tail->next;
            h1 = h1->next;
        }

        while (h2) {
            tail->next = new Node(h2->coeff, h2->pow);
            tail = tail->next;
            h2 = h2->next;
        }

        Node* result = dummy->next;
        delete dummy;
        return result;
    }
};

int main() {
    LinkedList poly1, poly2;

    // First polynomial: 3x^2 + 2x^1 + 1
    poly1.create(3, 2);
    poly1.create(2, 1);
    poly1.create(1, 0);

    // Second polynomial: 4x^2 + 5x^1 + 6
    poly2.create(4, 2);
    poly2.create(5, 1);
    poly2.create(6, 0);

    cout << "Polynomial 1: ";
    poly1.display();

    cout << "Polynomial 2: ";
    poly2.display();

    Node* result = LinkedList::polyAdd(poly1.head, poly2.head);

    cout << "Sum: ";
    LinkedList resultList;
    resultList.head = result;
    resultList.display();

    return 0;
}            
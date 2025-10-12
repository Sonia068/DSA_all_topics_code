// Railway reservation system
#include <iostream>
using namespace std;
#define size 5

class q {
    int front;
    int rear;
    int arr[size];

public:
    q() {
        front = -1;
        rear = -1;
    }

    void book(int val) {
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
            cout << "All Seats are booked. Adding to waiting list" << endl;
            return;
        }

        // If first element, initialize front and rear
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = val;
        cout << "Ticket booked successfully! Seat Number: " << val << " Position: " << rear << endl;
    }

    void cancel() {
        if (front == -1) {
            cout << "Queue is empty. No tickets to cancel." << endl;
        } else {
            int element = arr[front];
            cout << "Cancelled Ticket Number: " << element << endl;

            // Reset queue if it was the last element
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
        }
    }

    void Viewtickets() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Current booked tickets: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }
};

int main() {
    q s;
    int n;

    do {
        cout << "\n------BOOKING DETAILS------ " << endl;
        cout << "1: BOOK the ticket" << endl;
        cout << "2: View the ticket" << endl;
        cout << "3: Cancel the ticket" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter the choice: ";
        cin >> n;

        switch (n) {
        case 1: {
            int val;
            cout << "Enter seat number to book: ";
            cin >> val;
            s.book(val);
            break;
        }
        case 2:
            s.Viewtickets();
            break;
        case 3:
            s.cancel();
            break;
        case 4:
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (n != 4);

    return 0;
}

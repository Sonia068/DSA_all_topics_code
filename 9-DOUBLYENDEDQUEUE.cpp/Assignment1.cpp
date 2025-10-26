// Browser History using double ended Queue:
#include <iostream>
#include <deque>
#include <string>
using namespace std;

class BrowserHistory {
    deque<string> history;
    int curr_index;
    int max_capacity;

public:
    BrowserHistory(string homepage, int capacity) {
        max_capacity = capacity;
        history.push_back(homepage);
        curr_index = 0;
    }

    void visit(string url) {
        while (history.size() > curr_index + 1) {
            history.pop_back();
        }

       
        if (history.size() == max_capacity) {
            history.pop_front();
            if (curr_index > 0) curr_index--;  
        }

   
        history.push_back(url);
        curr_index++;
        
      
        cout << history[curr_index] << endl;
    }

    void back(int steps) {
        curr_index = max(0, curr_index - steps);
        cout << history[curr_index] << endl;
    }

    void forward(int steps) {
        curr_index = min((int)history.size() - 1, curr_index + steps);
        cout << history[curr_index] << endl;
    }

    void display() {
        cout << "Browser History: ";
        for (int i = 0; i < history.size(); i++) {
            cout << history[i];
            if (i != history.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Current page: " << history[curr_index] << endl;
    }
};

int main() {
    string homepage;
    int capacity;

    cout << "Enter homepage URL: ";
    cin >> homepage;

    cout << "Enter maximum history size: ";
    cin >> capacity;

    BrowserHistory b(homepage, capacity);

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Visit new page\n";
        cout << "2. Back\n";
        cout << "3. Forward\n";
        cout << "4. Display history\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string url;
                cout << "Enter URL to visit: ";
                cin >> url;
                b.visit(url);
                break;
            }
            case 2: {
                int steps;
                cout << "Enter steps to go back: ";
                cin >> steps;
                b.back(steps);
                break;
            }
            case 3: {
                int steps;
                cout << "Enter steps to go forward: ";
                cin >> steps;
                b.forward(steps);
                break;
            }
            case 4:
                b.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}




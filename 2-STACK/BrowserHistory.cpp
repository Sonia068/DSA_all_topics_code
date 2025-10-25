/*Construct a simple stack-based history feature for a web browser.
Implement methods to visit a new URL (push onto the stack) and
back to the previous URL (pop from the stack). Test your
implementation with a sequence of URL visits.*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BrowserHistory {
private:
    stack<string> history;

public:
    void visit(const string& url) {
        history.push(url);
        cout << "Visited: " << url << endl;
    }

    void back() {
        if (history.empty()) {
            cout << "No history to go back." << endl;
            return;
        }

        string current = history.top();
        history.pop();

        if (history.empty()) {
            cout << "No previous URL. You are at the start page." << endl;
        } else {
            cout << "Back from " << current << " to " << history.top() << endl;
        }
    }

    void current() {
        if (history.empty()) {
            cout << "No current URL." << endl;
        } else {
            cout << "Current URL: " << history.top() << endl;
        }
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string url;

    do {
        cout << "--- Browser Menu ---\n";
        cout << "1. Visit new URL\n";
        cout << "2. Go back\n";
        cout << "3. Show current URL\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter URL to visit: ";
                cin >> url;
                browser.visit(url);
                break;
            case 2:
                browser.back();
                break;
            case 3:
                browser.current();
                break;
            case 4:
                cout << "Exiting browser.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 4);

    return 0;
}
/*Construct a simple stack-based history feature for a web browser.
Implement methods to visit a new URL (push onto the stack) and
back to the previous URL (pop from the stack). Test your
implementation with a sequence of URL visits.*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BrowserHistory {
private:
    stack<string> history;

public:
    void visit(const string& url) {
        history.push(url);
        cout << "Visited: " << url << endl;
    }

    void back() {
        if (history.empty()) {
            cout << "No history to go back." << endl;
            return;
        }

        string current = history.top();
        history.pop();

        if (history.empty()) {
            cout << "No previous URL. You are at the start page." << endl;
        } else {
            cout << "Back from " << current << " to " << history.top() << endl;
        }
    }

    void current() {
        if (history.empty()) {
            cout << "No current URL." << endl;
        } else {
            cout << "Current URL: " << history.top() << endl;
        }
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string url;

    do {
        cout << "--- Browser Menu ---\n";
        cout << "1. Visit new URL\n";
        cout << "2. Go back\n";
        cout << "3. Show current URL\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter URL to visit: ";
                cin >> url;
                browser.visit(url);
                break;
            case 2:
                browser.back();
                break;
            case 3:
                browser.current();
                break;
            case 4:
                cout << "Exiting browser.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 4);

    return 0;
}

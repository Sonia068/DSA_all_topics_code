#include <iostream>
using namespace std;
#define size 5

class Employee {
    int id;
    string name;

public:
    Employee() {
        id = 0;
        name = " ";
    }

    void setid(int i, const string &n) {
        id = i;
        name = n;
    }

    int getid() { 
        return id;
     }

    string getname() {
         return name; 
        }
};

class HashTable {
    Employee table[size];
    bool occupied[size];

public:
    HashTable() {
        for (int i = 0; i < size; i++)
            occupied[i] = false;
    }

    int hash(int id) {
        id=id%size;
        return id;
    }


    void insert(int id, const string &name) {
        int index = hash(id);
        int startindex = index;

        while (occupied[index]) {
            index = (index + 1) % size;
            if (index == startindex) {
                cout << "Hash table is full! Can't insert " << name << endl;
                return;
            }
        }
        table[index].setid(id, name);
        occupied[index] = true;
        cout << "Inserted (" << id << ", " << name << ") at index " << index << endl;
    }

    void display() {
        cout << "\n--- Hash Table ---" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Slot " << i << ": ";
            if (occupied[i])
                cout << "ID=" << table[i].getid() << ", Name=" << table[i].getname();
            else
                cout << "Empty";
            cout << endl;
        }
    }
};


int main() {
    HashTable h;
    int choice;
    int id;
    string name;

    do {
        cout << "\n-----HASH TABLE MENU -------" << endl;
        cout << "1. Insert Employee" << endl;
        cout << "2. Display Hash Table" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin >> name;
            h.insert(id, name);
            break;

        case 2:
            h.display();
            break;

        case 3:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}


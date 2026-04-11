// <-- Graph Traversal using BFS and DFS --> (list and matrix)
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node {
    int data;
    node* next;
};

int v;
int **adjMatrix;
node** adjlist;

// Create Graph using Matrix
void create_Matrix() {
    cout << "Enter number of vertices: ";
    cin >> v;

    adjMatrix = new int*[v];
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = new int[v];
        for (int j = 0; j < v; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter source and destination:\n";
    int s, d;
    for (int i = 0; i < edges; i++) {
        cin >> s >> d;
        adjMatrix[s][d] = 1;
        adjMatrix[d][s] = 1;
    }
}

// Create Graph using List
void create_List() {
    cout << "Enter number of vertices: ";
    cin >> v;

    adjlist = new node*[v];
    for (int i = 0; i < v; i++) {
        adjlist[i] = NULL;
    }

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter source and destination:\n";
    int s, d;

    for (int i = 0; i < edges; i++) {
        cin >> s >> d;

        node* nn = new node();
        nn->data = d;
        nn->next = adjlist[s];
        adjlist[s] = nn;

        nn = new node();
        nn->data = s;
        nn->next = adjlist[d];
        adjlist[d] = nn;
    }
}

void BFS_Matrix() {
    int start;
    cout << "Enter start node: ";
    cin >> start;

    int* visited = new int[v]{0};
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int d = q.front();
        q.pop();
        cout << d << " ";

        for (int i = 0; i < v; i++) {
            if (adjMatrix[d][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void BFS_list() {
    int start;
    cout << "Enter start node: ";
    cin >> start;

    int* visited = new int[v]{0};
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int d = q.front();
        q.pop();
        cout << d << " ";

        node* temp = adjlist[d];
        while (temp != NULL) {
            if (visited[temp->data] == 0) {
                q.push(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

void DFS_Matrix() {
    int start;
    cout << "Enter start node: ";
    cin >> start;

    int* visited = new int[v]{0};
    stack<int> s;

    s.push(start);
    visited[start] = 1;

    while (!s.empty()) {
        int d = s.top();
        s.pop();
        cout << d << " ";

        for (int i = 0; i < v; i++) {
            if (adjMatrix[d][i] == 1 && visited[i] == 0) {
                s.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void DFS_list() {
    int start;
    cout << "Enter start node: ";
    cin >> start;

    int* visited = new int[v]{0};
    stack<int> s;

    s.push(start);
    visited[start] = 1;

    while (!s.empty()) {
        int d = s.top();
        s.pop();
        cout << d << " ";

        node* temp = adjlist[d];
        while (temp != NULL) {
            if (visited[temp->data] == 0) {
                s.push(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\n1. Create Matrix\n2. Create List\n3. BFS Matrix\n4. BFS List\n5. DFS Matrix\n6. DFS List\n7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: create_Matrix(); break;
            case 2: create_List(); break;
            case 3: BFS_Matrix(); break;
            case 4: BFS_list(); break;
            case 5: DFS_Matrix(); break;
            case 6: DFS_list(); break;
            case 7: break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
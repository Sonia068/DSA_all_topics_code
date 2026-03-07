//--------------Adjacency List (Weighted Graph)--------------
// SC = O(V + E)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    // One-based indexing
    vector<pair<int,int>> adj[n+1];

    // Input edges
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < e; i++) {
        int src, dest, wt;
        cin >> src >> dest >> wt;

        adj[src].push_back({dest, wt}); // directed graph
        adj[dest].push_back({src, wt}); // for undirected graph
    }

    // Print adjacency list
    cout << "Weighted Adjacency List:" << endl;

    for (int i = 0; i <= n; i++) {
        cout << i << " : ";

        for (auto it : adj[i]) {    // auto add the datatype of it
            cout << "(" << it.first << "," << it.second << ") ";
        }

        cout << endl;
    }

    return 0;
}
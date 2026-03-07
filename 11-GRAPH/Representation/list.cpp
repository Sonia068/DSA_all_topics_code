//--------------Adjacency list(Graph)--------------(SC-O(E)---if undirected graph,O(2E)----if directed graph)
    // Adjacency matrix(Graph)----------------(SC-O(V^2))
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    // vector<int> graph[n]; // zero-based indexing
    vector<int> graph[n+1]; // one-based indexing
    for (int i = 0; i < e; i++) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest); // Assuming a directed graph
        graph[dest].push_back(src); // For undirected graphs
    }

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i <=n; i++) {
        cout << i << ": ";
        for (int j : graph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}



// Short 
/*
int n,m;
cin>>n>>m;
vector<int> graph[n+1];

 // one-based indexing
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
   graph[u].push_back(v); // Assuming a directed graph
   graph[v].push_back(u); // For undirected graphs
    }
    return 0;
}
*/


   
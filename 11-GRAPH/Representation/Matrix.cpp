//--------------Adjacency matrix(Graph)--------------
#include <iostream>
using namespace std;

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    // Edges -> variable ,so matrix  size is determined by number of vertices (n) not edges (e)

    /*
    // Zero-based indexing in graph 

    // Create an adjacency matrix
    int graph[n][n];            
    
    // Initialize the adjacency matrix with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    */


    // One-based indexing in graph
    
    // Create an adjacency matrix
    int graph[n+1][n+1];

    // Initialize the adjacency matrix with 0s
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges and populate the adjacency matrix
    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < e; i++) {
        int src, dest;
        cin >> src >> dest;
        graph[src][dest] = 1; // Assuming a directed graph
        graph[dest][src] = 1; // For undirected graphs
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Short 
/*
int n,m;
cin>>n>>m;

int adj[n+1][n+1]; // one-based indexing
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
    return 0;
}
*/

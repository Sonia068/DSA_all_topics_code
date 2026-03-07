//------DFS(Undirected, Unweighted)--------

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int n, e;
    vector<int> adj[100];
    int vis[100];

    void DFS(int node) {
        vis[node] = 1;
        cout << node << " ";

        for (auto it : adj[node]) {
            if (!vis[it]) {
                DFS(it);
            }
        }
    }

public:
    void input() {
        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "Enter number of edges: ";
        cin >> e;

        cout << "Enter edges:" << endl;
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);   // remove for directed graph
        }

        for(int i = 0; i < 100; i++)
            vis[i] = 0;
    }

    void dfsTraversal() {
        int start;
        cout << "Enter starting node: ";
        cin >> start;

        cout << "DFS Traversal: ";
        DFS(start);
    }
};

int main() {

    Graph g;

    g.input();
    g.dfsTraversal();

    return 0;
}



/*
// vectors of vectors :  vector<vector<int>>:

// ------Logic Code--------
class Solution {
  private :
  void DFS(int node,vector<vector<int>>&adj,int vis[],vector<int>&ls){
      vis[node]=1;
      ls.push_back(node);
      // Traverse all its neighbours
      for(auto it:adj[node]){
          if(!vis[it]){
              DFS(it,adj,vis,ls);
          }
      }
  }
  
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
       int n=adj.size();
       int vis[n]={0};
       int start=0;
       vector<int>ls;
       DFS(start,adj,vis,ls);
       return ls;
    }
};

*/
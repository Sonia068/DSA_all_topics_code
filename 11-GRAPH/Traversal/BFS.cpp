//------BFS (Undirected, Unweighted) Level Wise--------

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int n, e;
    queue<int> q;
    vector<int> adj[100];
    int vis[100];

    void BFS(int node) {
        vis[node] = 1;
        q.push(node);

        while (!q.empty()) {

            int size = q.size();   // nodes in current level

            while (size--) {     // print Breadth wise 
                int c = q.front();
                q.pop();

                cout << c << " ";

                for (auto it : adj[c]) {   
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }

            cout << endl;  // new line for next level
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
            adj[v].push_back(u);
        }

        for (int i = 0; i < 100; i++)
            vis[i] = 0;
    }

    void BfsTraversal() {
        int start;

        cout << "Enter starting node: ";
        cin >> start;

        cout << "BFS Traversal (Level Wise):" << endl;
        BFS(start);
    }
};

int main() {

    Graph g;

    g.input();
    g.BfsTraversal();

    return 0;
}

/*
// vectors of vectors :  vector<vector<int>>:

// ------Logic Code--------
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
     int n=adj.size();
      int vis[n]={0};
      vis[0]=1;
      vector<int>BFS;
      queue<int>q;
      q.push(0);
      
      while(!q.empty()){
          int c=q.front();
          q.pop();
          BFS.push_back(c);
          
          for(auto it:adj[c]){
              if(!vis[it]){
                  vis[it]=1;
                  q.push(it);
              }
          }
      }
      
      return BFS;
        
    }
};
*/
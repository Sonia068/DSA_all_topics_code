// <--------Create graph using adjacency list and perform DFS and BFS-------->

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;


struct node{
    int data;
    node* next;
    
    node(int d){
        data=d;
        next=NULL;
    }
};

node* createNode(int dd){
    node* nn=new node(dd);
    return nn;
}


struct Graph{
    int V;
    node ** adjlist;
    
};


Graph* createGraph(int v){
    Graph* graph=new Graph;
    graph->V=v;
    graph->adjlist=new node*[v];
    
    for(int i=0;i<v;i++){
        graph->adjlist[i]=NULL;
    }
    return graph;
}


void addEdge (Graph*g,int src,int dest){
    // source to dest
    node* nn=createNode(dest);
    nn->next=g->adjlist[src];
    g->adjlist[src]=nn;
    
    // dest to source
    nn=createNode(src);
    nn->next=g->adjlist[dest];
    g->adjlist[dest]=nn;
}

void display(Graph* g){
    cout<<"\nAdjacency List:\n";
    for(int i=0;i<g->V;i++){
        cout<<i<<" -> ";
        node* temp=g->adjlist[i];
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}



//Non-Recusive :
void dfs(Graph *g,int src ){
    stack<int>st;
    vector<int>vis(g->V,0);
    st.push(src);
    
    while(!st.empty()){
        int t=st.top();
        st.pop();
        
        if(!vis[t]){
            vis[t]=1;
            cout<<t<<" ";
            
            node* temp=g->adjlist[t];
            while(temp!=NULL){
                int adj=temp->data;
                temp=temp->next;
                
                if(!vis[adj]){
                    st.push(adj);
                }
            }
        }
    }
}

// Recursive :

void Rdfs(Graph*g,int src,vector<int>&vis){
    vis[src]=1;
    cout<<src<<" ";
    
    node* temp=g->adjlist[src];
    while(temp!=NULL){
        int adj=temp->data;
   
        
        if(!vis[adj]){
            Rdfs(g,adj,vis);
        }
            temp=temp->next;
    }
}


void callRecursiveDFS(Graph* g, int src){
    vector<int> vis(g->V,0);
    cout<<"DFS (Recursive): ";
    Rdfs(g,src,vis);
    cout<<endl;
}


// BFS
void BFS(Graph*g,int src){
    queue<int>q;
    vector<int>vis(g->V,0);

    q.push(src);
    vis[src]=1;   

    while(!q.empty()){
        int t=q.front();
        q.pop();

        cout<<t<<" ";

        node* temp=g->adjlist[t];
        while(temp!=NULL){
            int adj=temp->data;

            if(!vis[adj]){
                vis[adj]=1;   
                q.push(adj);
            }

            temp=temp->next;
        }
    }
}


int main(){
    int V, choice, src, dest, start;
    
    cout<<"Enter number of vertices: ";
    cin>>V;

    Graph* g = createGraph(V);

    do{
        cout<<"\n===== MENU =====\n";
        cout<<"1. Add Edge\n";
        cout<<"2. Display Graph\n";
        cout<<"3. DFS (Non-Recursive)\n";
        cout<<"4. DFS (Recursive)\n";
        cout<<"5. BFS\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter source and destination: ";
                cin>>src>>dest;
                if(src < V && dest < V){
                    addEdge(g,src,dest);
                } else {
                    cout<<"Invalid vertices!\n";
                }
                break;

            case 2:
                display(g);
                break;

            case 3:
                cout<<"Enter starting node: ";
                cin>>start;
                dfs(g,start);
                break;

            case 4:
                cout<<"Enter starting node: ";
                cin>>start;
                callRecursiveDFS(g,start);
                break;

            case 5:
                cout<<"Enter starting node: ";
                cin>>start;
                BFS(g,start);
                break;

            case 6:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid choice!\n";
        }

    }while(choice != 6);

    return 0;
}


// int main(){
//     int vv;
//     cout<<"Enter the no. of vertices:"<<endl;
//     cin>>vv;
    
//     Graph*g=createGraph(vv);
//     addEdge(g,1,2);
//     addEdge(g,2,4);
//     addEdge(g,1,3);
//     addEdge(g,3,4);
    
//     int s;
//     cout<<"Enter the source:"<<endl;
//     cin>>s;
//     dfs(g,s);
    
// }







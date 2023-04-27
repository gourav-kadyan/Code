#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int,list<int>> &adj,
         unordered_map<int,bool> &visited,vector<int> & component)
{
    component.push_back(node);
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;

    //make adj list
    unordered_map<int, list<int> > adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //dfs call if node is not visited
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++) {
      if (!visited[i]){
          vector<int> component;
          dfs(i,adj,visited,component);
          ans.push_back(component);
      }
    }
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }


    vector<vector<int>> ans = depthFirstSearch(V, E, edges);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Component " << i << ": ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

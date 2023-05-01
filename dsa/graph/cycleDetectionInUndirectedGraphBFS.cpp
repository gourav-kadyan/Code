//if node is visited and node is not a parent then it is cycle is present

#include<bits/stdc++.h>

using namespace std;

void find_cycle_in_undirected_graph(vector<vector<int>> &edges){
    //firstly make adjancy list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //bfs 
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for(int i=0;i<n;i++){
        int u;
        int v;
        cin >> u >> v;
        vector<int> lol;
        lol.push_back(u);
        lol.push_back(v);
        edges.push_back(lol);
    }
    find_cycle_in_undirected_graph(edges);
}
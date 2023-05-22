//cycle detection in directed graph using dfs 
//we made a two visited this time first is visited and second is dfs visited so here is code

#include <bits/stdc++.h>
using namespace std;


bool dfs(int node, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited,
        unordered_map<int, bool> &dfsVisited)
{

    visited[node] = true;
    dfsVisited[node] = true;
    for(auto padosi:adj[node]){
        if(!visited[padosi]){
            bool ans = dfs(padosi,adj,visited,dfsVisited);
            if(ans == true)
                return true;
        }
        else if(dfsVisited[padosi])
            return true;
    }

    dfsVisited[node] = false;
    return false;
}

bool checkCycle(vector<vector<int>> &edges,int m,int n){
    //firstly make an adjancy list
    unordered_map<int, list<int> > adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    //dfs
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = dfs(i,adj,visited,dfsVisited);
            if(ans == true)
                return true;
        }
    }

    return false;
}


int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>> u >> v;
        vector<int> lol;
        lol.push_back(u);
        lol.push_back(v);
        edges.push_back(lol);
    }

    bool ans = checkCycle(edges,m,n);
    if(ans == true){
        cout << "Cycle is present " << endl;
    }
    else{
        cout << "Cycle is not present " << endl;
    }
}


/*

5
4
1 2
2 3
3 4
4 5
false

2
1
1 2
false

1
5
6
1 2
4 1
2 4
3 4
5 2
1 3
true

*/
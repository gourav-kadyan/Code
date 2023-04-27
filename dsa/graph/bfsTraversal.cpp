#include <bits/stdc++.h> 
using namespace std;


void makeList(unordered_map<int,set<int>> &adjlist, vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }    
}

void bfs(unordered_map<int, set<int> > &adjlist, unordered_map<int, bool> &visited
         ,vector<int> &ans,int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);
        for(auto i: adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }            
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int> > adjlist;
    unordered_map<int, bool> visited;
    vector<int> ans;

    //making adjlist 
    makeList(adjlist,edges);

    //traverse all the components  like those are disconnected
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjlist,visited,ans,i);
        }
    }

    return ans;
    
}

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;

    vector<pair<int, int>> edges(edge);
    for (int i = 0; i < edge; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> ans = BFS(vertex, edges);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

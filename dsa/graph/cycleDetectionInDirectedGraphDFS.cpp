//if node is visited and node is not a parent then it is cycle is present

#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

bool dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,unordered_map<int,list<int>> &adj)
{
	visited[node] = true;
	dfsVisited[node] = true;
	for(auto neighbour:adj[node]){
		if(!visited[neighbour]){
			bool cycle = dfs(neighbour,visited,dfsVisited,adj);
			if(cycle == true){
				return true;
			}
		}
		else if(dfsVisited[neighbour] == true){
			return true;
		}
	}
	dfsVisited[node] = false;
	return false;
}


bool find_cycle_in_undirected_graph(vector<vector<int>> &edges,int n, int m){
    //firstly make adjancy list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    //bfs 
    unordered_map<int,bool> dfsVisited;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = dfs(i,visited,dfsVisited,adj);
            if(ans == true){
                return true;
            }
        }
    }
    return false;

}

int main(){
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u;
        int v;
        cin >> u >> v;
        vector<int> lol;
        lol.push_back(u);
        lol.push_back(v);
        edges.push_back(lol);
    }
    
    bool ans = find_cycle_in_undirected_graph(edges,n,m);
    cout << ans << endl;
    return 0;
}
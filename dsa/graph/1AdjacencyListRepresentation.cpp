#include <bits/stdc++.h>
 

#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 

using namespace std;

class graph {
    public:

    unordered_map<int,list<int>> adj;

    void addEdges(int u, int v, bool direction){
        // direction == 0 means undirected graph
        // direction == 1 means directed graph

        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
        for(auto it: adj){
            cout << it.first << " -> ";
            for(auto i:it.second){
                cout << i << ", ";
            }
            cout << endl;
        }
    }

};


void krdiyasuru()
{
    cii(n,m);//n = no. of  nodes , m = no. of edges
    graph g;
    for(int i=0;i<n;i++){
        cii(u,v);
        g.addEdges(u,v,0);
    }

    g.printAdj();
    cout << endl;
 
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
    //    krosuru
    {
        krdiyasuru();
    }
}
 
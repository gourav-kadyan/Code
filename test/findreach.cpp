# include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void dfs(vector <vector<ll>> &graph,vector <bool> &visited,ll i)
{
    visited[i]=true;
    for(auto x: graph[i])
    {
        if(!visited[x])
            dfs(graph,visited,x);
    }
}
int main()
{
    ll t,i,j,k,n;
    cin>>n;
    map <ll,ll> m;
    for(i=0;i<n;i++)
    {
        cin>>j;
        m[j]=i;
    }
    ll q;
    cin>>q;
    vector <vector<ll>> graph(n);
    while(q--)
    {
        ll x1,x2;
        cin>>x1>>x2;
        graph[m[x1]].push_back(m[x2]);
    }
    ll x1,x2;
    cin>>x1>>x2;
    x1=m[x1];
    x2=m[x2];
    vector <bool> visited(n,false);
    dfs(graph,visited,x1);
    if(visited[x2])
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
}
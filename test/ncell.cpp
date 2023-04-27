#include<bits/stdc++.h>
using namespace std;

vector<int> chotaPath(vector<int> adj[], int count1, int n){
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    q.push(count1);
    distance[count1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &v: adj[u]){
            if(distance[v] > distance[u] + 1){
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
    return distance;
}
int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--){
        int n;
        cin>>n;
        vector<int> konne(n);
        for(int i=0 ; i<n ; i++){
            cin >> konne[i];
        }
        int count1, count2;
        cin>>count1>>count2;
        vector<int> adj[n];
        for(int i=0 ; i<n ; i++){
            if(konne[i] == -1) continue;
            adj[i].push_back(konne[i]);
        }
        vector<int> array1 = chotaPath(adj, count1, n);
        vector<int> array2 = chotaPath(adj, count2, n);
        int mn = INT_MAX, answer = -1;
        for(int i=0 ; i<n ; i++){
            if (array1[i] == INT_MAX || array2[i] == INT_MAX){
                continue;
            }
            if (array1[i] + array2[i] < mn){
                mn = array1[i] + array2[i];
                answer = i;
            }
        }
        cout << answer << endl;
    }    

}
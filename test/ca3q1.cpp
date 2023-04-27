#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n;
int a[MAXN][MAXN];
int vis[MAXN];
int ans;

void dfs(int u, int cnt) {
    ans = max(ans, cnt);
    for(int v = 1; v <= n; v++) {
        if(a[u][v] && !vis[v]) {
            vis[v] = 1;
            dfs(v, cnt + 1);
            vis[v] = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vis[1] = 1; // start from location 1
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
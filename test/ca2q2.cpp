#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;

ll solve(ll x, vector<ll>& v, vector<ll>& ax) {
    if (x >= v.size())
        return 0;
    
    ll l = 0, r = 0;
    if ((x * 2) < v.size())
        l = solve(x * 2, v, ax);
    if ((x * 2 + 1) < v.size() )
        r = solve(x * 2 + 1, v, ax);
    if(ax[x]==1)
    return v[x] + max(l, r);
    return max(l, r);
}



void krdiyasuru()
{
    ci(n);
    vector<ll> v(n + 1), ax(n + 1);
    for (int x = 1; x < n + 1; x++)
        cin >> v[x];
    for (int x = 1; x < n + 1; x++)
        cin >> ax[x];
    cout << solve(1, v, ax) << endl;
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
     //   krosuru
    {
        krdiyasuru();
    }
}
 
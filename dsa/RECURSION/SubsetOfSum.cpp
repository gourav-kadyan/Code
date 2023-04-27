#include <bits/stdc++.h>
 
const long long SZ = 4e3 + 7;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;
const long long mod = 1e9 + 7;
long long opnmbr = 1;
 
#define ll                  long long
#define ld                  long double
 
#define pb                  push_back
#define mp                  make_pair
#define eb                  emplace_back
 
#define pll                 pair<ll, ll>
#define vi                  vector<ll>
#define vs                  vector<string>
#define vpl                 vector<pll>
#define qi                  queue<ll>
#define si                  set<ll>
#define mi                  map<ll, ll>
#define umi                 unordered_map<ll, ll>
 
#define fi                  first
#define se                  second
 
#define sz(x)               (ll)x.size()
 
#define all(c)              (c).begin(), (c).end()
#define allr(c)             (c).rbegin(), (c).rend()
 
#define Max(a,b)            ((a > b) ? a : b)
#define Min(a,b)            ((a < b) ? a : b)
 
#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define dbg(x)              cout<<#x<<"="<<(x)<<endl;
#define dbg2(x,y)           cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<endl;
#define dbg3(x,y,z)         cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<endl;
#define dbg4(x,y,z,w)       cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<" "<<#w<<"="<<(w)<<endl;
 
#define ons()               cout<<"Case #"<<opnmbr++<<": ";
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
#define inf                 1e18
 
#define forn(i, n)          for(ll i = 0; i < (n); i++)
#define fore(i, n)          for(ll i = 1; i <= (n); i++)
#define forl(i, l, r)       for(ll i = l; i < (r); i++)
#define forr(i, l, r)       for(ll i = l; i >= (r); i--)
 
#define ms0(X)              memset((X), 0, sizeof((X)))
#define ms1(X, V)           memset((X), -1, sizeof((X)))
#define flv(X, V)           fill(all((X)), V)
 
using namespace std;
//subset of sum 
// complexity is 2^n + (2^n-1) == theta 2^n
/* //mine solution
void subset(int arr[],int sum,int n,int curr,int &res){
    if(n == 0){
        if(curr == sum){
            res++;
            return;
        } 
        else return;
    }
    subset(arr,sum,n-1,curr,res);
    subset(arr,sum,n-1,curr+arr[n-1],res);
}
*/
int subset(int arr[],int n,int sum){
    if(n == 0){
        return (sum == 0) ? 1 : 0;
    }
    return subset(arr,n-1,sum ) + subset(arr,n-1,sum - arr[n-1]);
}
void krdiyasuru()
{
    ci(n);
    int arr[n];
    forn(i,n) cin>>arr[i];
    ci(sum);
   // ll curr = 0;
   // int res = 0;       //mine sol
    //subset(arr,sum,n,curr,res);  //mine sol
    //cout<<res<<endl;    //mine sol
    cout<<subset(arr,n,sum)<<endl;
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
 
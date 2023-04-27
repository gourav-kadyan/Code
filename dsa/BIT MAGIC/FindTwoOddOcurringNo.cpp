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
//ques == find two odd ocurring number in array
//time  = theta n
/*
    basically logic is
    ex =  1 1 2 2 3 4
    1. xor all the elements each other like 
    2. after that we get 3 ^ 4 right   // 3 ^ 4 = 1 1 1 == 5
    3. we make two grp first one which has rightmost bit of this expression equal to 1 0 0 == 4
       and another grp chk other bits and also the the grp member is odd ocurring :)
    4. how to get right most bit so we need to do like in this example 5 & ~(5-1) so that we get the right most bit   
*/
void krdiyasuru()
{
    ci(n);
    int XOR = 0, res1 = 0, res2 = 0;
    int arr[n];
    forn(i,n) cin>>arr[i];
    forn(i,n) XOR = XOR ^ arr[i];
    int rmb = XOR & ~(XOR-1);
    forn(i,n){
        if(arr[i] & rmb != 0)
            res1 = res1 ^ arr[i];
        else
            res2 = res2 ^ arr[i];    
    }   
    cout<<res1<<" "<<res2<<endl;
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
 
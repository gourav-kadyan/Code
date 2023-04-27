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
//tower of hanoi
/*rules

   move only one disk at a time
   smaller disk always above the bigger
   only the top disk of a tower can be move
*/ 
//logic
//ex n = 

/*
     at first all disk in tower A
     our destination is to move disks to C without voilating rule
     so first we move small disk to tower A to C
     then after that we move middle disk to tower A to B
     after that we move  smaller disk to towe C to B
     then we move biggest disk to tower A to C
     then we move smaller disk to tower B to A
     after that we move middle disk to tower B to C
     and then we move smaller disk to tower A to C

*/
void toh(int n, char A ,char B, char C){
    if(n == 1){
        cout<<"Move Disk "<<n<<"  "<<A<<" to "<<C<<endl;
        return;
    }
    toh(n-1,A,C,B);
    cout<<"Move Disk "<<n<<"  "<<A<<" to "<<C<<endl;
    toh(n-1,B,A,C);

}
void krdiyasuru()
{
   ci(n);
   ll move = pow(2,n) -1;
   cout<<"There would be "<<move<<" moves need to do it --- "<<endl;
   toh(n,'A','B','C'); 
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
 
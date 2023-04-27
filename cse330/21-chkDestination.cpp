//check destinaeion is reachable or not 
// (x,y) -- (x, x+y) or (x+y, y)
#include <bits/stdc++.h>
 
#define ll long long 
#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 

#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
bool dest(int n1, int n2, int k1, int k2){
    if(n1 == k1 && n2 == k2){
        return true;
    }
    if(n1 > k1 || n2 > k2){
        return false;
    }
    return dest(n1 + n2, n2 , k1, k2) || dest(n1 , n2 + n1, k1 , k2);
} 
void krdiyasuru()
{
    ciiii(source1,source2,  destination1, destination2);
    bool ans = dest(source1, source2,destination1, destination2);
    cout << ans << endl;
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
 
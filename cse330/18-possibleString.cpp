#include <bits/stdc++.h>
 

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 

#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
void posString(string &s, int n, int i, string lol){
    if(i == n){
        cout << lol << " ";
        
        return;
    }

    posString(s, n, i+1,lol);
    posString(s, n, i+1, lol + s[i]);
}
void krdiyasuru()
{
    string s;
    cin >> s;
    int n = s.length();
    string lol = "";
    posString(s, n, 0,lol);
    reverse(s.begin(), s.end());
    posString(s, n, 0, lol);
}
 
int main()
{
    //yehbhitheekhai;
    //    solve();
    //    krosuru
    {
        krdiyasuru();
    }
}
 
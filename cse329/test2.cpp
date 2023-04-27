#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
 
void krdiyasuru()
{
 
    ci(n);
    int st[n];
    int end[n];
    for(int i=0;i<n*2;i++){
        cin >> st[i];
        cin >> end[i];
    }
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        p[i]  = make_pair(end[i],st[i]);
    }
    sort(p,p+n);
    int count = 1;
    int curr = p[0].first;
    for(int i=1;i<n;i++){
        if(p[i].second >=  curr){
            count++;
            curr = p[i].first;
        }
    }
    cout << count << endl;
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
 
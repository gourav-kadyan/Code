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
    cii(n,k);
    vector<int> ans;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        ans.push_back(temp);
    }
    int var = ans[k];
    swap(ans[k],ans[n-1]);
    sort(ans.begin(),ans.end()-1);
    // for(int i=0;i<n;i++){
    //     cout << ans[i] << " ";
    // }
    cout << endl;
    for(int i=n-1;i>k;i--){
        ans[i] = ans[i-1];
    }
    ans[k] = var;
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;

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
 
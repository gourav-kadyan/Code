#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
unordered_map<int,int> mp;
void primeFactors(int n)
{
    if(n % 2 == 0){
        mp[2]++;
        while (n % 2 == 0)
        {
        n = n/2;
        }
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
       if(n%i == 0){
         mp[i]++;
            while (n % i == 0)
            {
                n = n/i;
            }
       }
    }

    if (n > 2)
        mp[n]++;
}
void krdiyasuru()
{
    ci(n);
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        primeFactors(arr[i]);
    }
    int ans=1;
    for(auto it : mp){
        if(it.second == n){
            ans = max(ans,it.first);
        }
    }
    cout << ans << endl;
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
 
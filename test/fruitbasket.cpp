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
    int arr[n];
    ll sum=0;
    for(int i=0; i<n; i++){
        cin>> arr[i];
        sum += arr[i];
    }
    ci(k);
    ll take = 0;
    priority_queue<int> pq(arr,arr+n);
    while(k--){
        int t = pq.top();
        int fl = floor(sqrt(t));
        pq.pop();
        pq.push(fl);
        take += t -fl;
    }
    cout << sum -take << endl;

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
 
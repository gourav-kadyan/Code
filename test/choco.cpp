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
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    ll take = 0;
    priority_queue<int,vector<int>,greater<>> pq(arr,arr+n);
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        take += (first + second);
        pq.push(first+second);
    }
    cout << take << endl;
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
 
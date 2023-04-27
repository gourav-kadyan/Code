#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
//in this find min and max rupees to buy all candy
void krdiyasuru()
{
    cii(n,k);
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int mini = 0;
    int free = n-1;
    int buy = 0;
    while(buy <= free){
        mini  += arr[buy];
        buy++;
        free = free - k;
    }
    int maxi=0;
    buy = n-1;
    free = 0;
    while(buy >= free){
        maxi += arr[buy];
        buy--;
        free = free + k;
    }
    cout << mini << " " << maxi << endl;
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
        krosuru
    {
        krdiyasuru();
    }
}
 
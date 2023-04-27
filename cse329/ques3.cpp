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
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> val;
    for(int i=0;i<n;i++){
        if(arr[i] < 10){
            val.push_back(arr[i]);
        }
        else if(arr[i] < 100){
            val.push_back(arr[i]/10);
        }
        else if(arr[i] < 1000){
            val.push_back(arr[i]/100);
        }
        else if(arr[i] < 10000){
            val.push_back(arr[i]/1000);
        }
        else if(arr[i] < 100000){
            val.push_back(arr[i]/10000);
        }
        else if(arr[i] < 1000000){
            val.push_back(arr[i]/100000);
        }
        else if(arr[i] < 10000000){
            val.push_back(arr[i]/1000000);
        }
        else if(arr[i] < 100000000){
            val.push_back(arr[i]/10000000);
        }
        else if(arr[i] < 1000000000){
            val.push_back(arr[i]/100000000);
        }
        else{
            break;
        }
    }
    if(n == 1){
        cout << val[0] << endl;
    }
    else{
        sort(val.begin(),val.end(),greater<>());
        long ans = val[0];
        int len = val.size();
        swap(val[len-1],val[len-2]);
        for(int i=1;i<val.size();i++){
            ans = ans*10 + val[i];
        }
        cout << ans << endl;
    }
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
 
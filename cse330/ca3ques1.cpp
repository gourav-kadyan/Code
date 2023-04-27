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
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int sum2=0;
    int count =0;
    for(int i=0;i<n;i++){
        sum2+=arr[i];
        if(sum == sum2){
            count++;
            break;
        }
    }
    if(count == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
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
 
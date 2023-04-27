#include <bits/stdc++.h>
 

#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 

using namespace std;
//Allocate the max min pages to readers

//naive recursive sol
int hum(int arr[], int k, int n){
    int summ=0;
    for(int i=k;i<=n;i++){
        summ += arr[i];
    }
    return summ;
}
int minPages(int arr[],int n, int k){
    if(k == 1){
        return hum(arr, 0, n-1);
    }
    if(n == 1){
        return arr[0];
    }
    int res = INT_MAX;
    for(int i=0;i<n;i++){
        res = min(res,max(minPages(arr,i,k-1), hum(arr,i,n-1)));
    }
    return res;

}



void krdiyasuru()
{
    cii(n,k);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int res = minPages(arr, n,k);
    cout << res << endl;
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
 
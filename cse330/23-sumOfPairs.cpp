//given an array a[] and value x. find all pairs of element from array having sum = x
#include <bits/stdc++.h>
 
#define ll long long
#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 

#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
 
void krdiyasuru()
{
    cii(n,sum);
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int low = 0;
    int high = n-1;
    while(low < high){
        if((arr[low]+arr[high]) == sum){
            cout << "{" << arr[low] << "," << arr[high] << "}"<< endl;
            low--;
            high++;
        }
        else if((arr[low]+arr[high]) > sum){
            high = high - 1;
        }
        else{
            low = low + 1;
        }
    }
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

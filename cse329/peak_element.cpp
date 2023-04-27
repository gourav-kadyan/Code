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
    if(n == 0){
        cout << "-1" << endl;
    }
    else if(arr[0] >= arr[1] || n == 1){
        cout << "0" << endl;
    }
    else if(arr[n-1] >= arr[n-2]){
        cout << n-1 << endl;
    }
    else{
        int lol = 0;
        for(int i=1;i<n-1;i++){
            if(arr[i] >= arr[i+1] && arr[i] >= arr[i-1]){
                lol++;
                cout << "i" << endl;
                break;
            }
        }
        if(lol == 0){
            cout << "-1" << endl;
        }
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
 
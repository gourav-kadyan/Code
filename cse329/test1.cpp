#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;

//  int wow(vector<vector<int>>& ans) {
//         sort(ans.begin(),ans.end());
//         int count = 0;
//         for(int i=0;i<ans.size()-1;i++){
//             if(ans[i][1] > ans[i+1][0]) {
//                count++;
//                ans[i+1][1] = min(ans[i][1],ans[i+1][1]);
//             }
//         }
        
//         return count;
//     }
bool isprime(int n)
{
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    else
    {
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
    }
    return true;
}
void krdiyasuru()
{
    //ci(n);
    // vector<vector<int>> lol(n,vector<int>(2,0));
    // for(int i=0;i<n;i++){
    //     vector<int> v;
    //     for(int j=0;j<n;j++){
    //         int temp ;
    //         cin >> temp;
    //         v.push_back(temp);
    //     }
    //     lol.push_back(v);
    // }
    // int ans = wow(lol);
    // cout << n - ans <<endl;
    int arr[10000];
    int i=0;
    int j=2;
    while(i < 10000){
        if(isprime(j) == true){
            arr[i++] = j;
        }
        j++;
    }
    ci(n);
    int lol[n];
    for(int i=0;i<n;i++){
        cin>>lol[i];
    }
    int ans=0;
    int diff = INT_MAX;
    for(int i=0;i<n;i++){
            int x = 0;
            while(x < 10000){
                int lol = abs(arr[i] - arr[x]);
                if(lol < diff){
                    diff = lol;
                    ans = arr[x];
                    cout << ans << " ";
                }
                if(lol > arr[i]*2 && arr[x] > arr[i]){
                    break;
                }
                x++;
            }
    }
    cout << endl ;
    cout << ans << endl;
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
 
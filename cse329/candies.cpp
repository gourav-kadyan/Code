#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
long candies(int n, vector<int> arr) {
    long ans = 0;
    vector<int> nums = {1};
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]){
            nums.push_back(nums[nums.size() - 1]+1);
        }
        else{
            nums.push_back(1);
        }
    }
    reverse(nums.begin(), nums.end());
    reverse(arr.begin(), arr.end());
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1] && nums[i] <= nums[i-1]){
            nums[i] = nums[i-1]+1;
        }
    }
    for(int i =0; i < nums.size(); i++){
        ans+=nums[i];
    }
    return ans;
} 
void krdiyasuru()
{
    ci(n);
    vector<int> arr;
    for(int i=0;i<n;i++){
        int tmep;
        cin >> tmep;
        arr.push_back(tmep);
    }
    long ans = candies(n,arr);
    cout << ans <<endl;
}
 
int main()
{
    yehbhitheekhai;
    {
        krdiyasuru();
    }
}
 
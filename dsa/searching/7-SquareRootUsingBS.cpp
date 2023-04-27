#include<bits/stdc++.h>
using namespace std;

// square root using binary search
// time is big o of log n
// space is theta 1
int Sqrt(int n){
    int low = 0;
    int high = n;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        int midsq = mid * mid;
        if(midsq == n){
            return mid;
        }
        else if(midsq > n){
            high = mid - 1;
        }
        else {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int root =  Sqrt(n);
    cout << root <<endl;
}
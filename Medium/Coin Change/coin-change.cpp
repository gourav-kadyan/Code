//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long solve(int n, int sum, int coins[], vector<vector<long long>> &dp){
        if(n == 0 && sum == 0){
            return 1;
        }
        if(n == 0 && sum != 0){
            return 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        if(coins[n-1] <= sum){
            return dp[n][sum] = solve(n,sum-coins[n-1],coins,dp) + solve(n-1,sum,coins,dp);
        }
        return dp[n][sum] = solve(n-1,sum,coins,dp);
        
    }
  
  
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N+1,vector<long long>(sum+1,-1));
        return solve(N,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
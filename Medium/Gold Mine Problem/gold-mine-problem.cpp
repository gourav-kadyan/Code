//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int row, int col,int ridx,int index,vector<vector<int>> &v,vector<vector<int>> &dp ){
        if(ridx < 0 || ridx >= row || index >= col){
            return 0;
        }
        if(dp[ridx][index] != -1){
            return dp[ridx][index];
        }
        
        int val1 = v[ridx][index] + solve(row,col,ridx,index+1,v,dp);
        int val2 = v[ridx][index] + solve(row,col,ridx-1,index+1,v,dp);
        int val3 = v[ridx][index] + solve(row,col,ridx+1,index+1,v,dp);
        
        if(index == col-1){
            return dp[ridx][index] = v[ridx][index];
        }
        
        return dp[ridx][index] =  max(val1,max(val2,val3));
        
    }
    int maxGold(int n, int m, vector<vector<int>> v)
    {
        // code here
        int ans = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            int val = solve(n,m,i,0,v,dp);
            ans = max(ans,val);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
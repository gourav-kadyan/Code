#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
int solve(string &s1, string &s2, int m, int n, int dp[][1001])
        {
            if (m == 0 || n == 0)
            {
                return 0;
            }
            if (dp[m][n] != -1)
            {
                return dp[m][n];
            }
            if (s1[m - 1] == s2[n - 1])
            {
                return dp[m][n] = 1 + solve(s1, s2, m - 1, n - 1, dp);
            }
            else
            {
                return dp[m][n] = max(solve(s1, s2, m - 1, n, dp), solve(s1, s2, m, n - 1, dp));
            }
        }
    int longestCommonSubsequence(string s1, string s2)
    {
        int dp[1001][1001];
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                dp[i][j] = -1;
            }
        }
        int m = s1.length();
        int n = s2.length();
        return solve(s1, s2, m, n, dp);
    }
void krdiyasuru()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2) << endl;
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
 
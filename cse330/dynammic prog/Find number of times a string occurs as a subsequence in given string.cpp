// A Memoization DP C++ program to find the number of
// times the second string occurs in the first string,
// whether continuous or discontinuous
#include <bits/stdc++.h>
using namespace std;

// Memoization DP function to find the number of times
// the second string occurs in the first string,
// whether continuous or discontinuous
int count(string a, string b, int m, int n,
		vector<vector<int> >& dp)
{
	// If both first and second string is empty,
	// or if second string is empty, return 1
	if ((m == 0 && n == 0) || n == 0)
		return 1;

	// If only first string is empty and second
	// string is not empty, return 0
	if (m == 0)
		return 0;

	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	// If last characters are same
	// Recur for remaining strings by
	// 1. considering last characters of both strings
	// 2. ignoring last character of first string
	if (a[m - 1] == b[n - 1])
		return dp[m][n] = count(a, b, m - 1, n - 1, dp)
						+ count(a, b, m - 1, n, dp);
	else
		// If last characters are different, ignore
		// last char of first string and recur for
		// remaining string
		return dp[m][n] = count(a, b, m - 1, n, dp);
}

// Driver code
int main()
{
	string a = "GeeksforGeeks";
	string b = "Gks";
	vector<vector<int> > dp(a.size() + 1,
							vector<int>(b.size() + 1, -1));
	cout << count(a, b, a.size(), b.size(), dp) << endl;

	return 0;
}

// Dynamic Programming C++ implementation to find
// minimum number of deletions and insertions
// using memoization technique
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

// Returns length of longest common subsequence
int lcs(string& s1, string& s2, int i, int j)
{
	if (i == 0 || j == 0) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s1[i - 1] == s2[j - 1]) {
		return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1);
	}
	else {
		return dp[i][j] = max(lcs(s1, s2, i, j - 1),
							lcs(s1, s2, i - 1, j));
	}
}

// function to find minimum number
// of deletions and insertions
void printMinDelAndInsert(string str1, string str2)
{
	int m = str1.size();
	int n = str2.size();

	dp[m][n];

	// initialising dp array as -1
	memset(dp, -1, sizeof(dp));

	int len = lcs(str1, str2, m, n);

	cout << "Minimum number of deletions = " << (m - len)
		<< endl;

	cout << "Minimum number of insertions = " << (n - len)
		<< endl;
}

// driver code
int main()
{
	string str1 = "heap";
	string str2 = "pea";

	// Function Call
	printMinDelAndInsert(str1, str2);

	return 0;
}

// This code is contributed by Arun Bang.

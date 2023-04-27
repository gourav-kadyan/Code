// C++ program to check if any
// valid sequence is divisible by M
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

bool isPossible(int n, int index, int sum,
		int M, int arr[], int dp[][MAX])
{

	// Base case
	if (index == n) {

		// check if sum is divisible by M
		if ((sum % M) == 0)
			return true;
		return false;
	}

	// check if the current state
	// is already computed
	if (dp[index][sum] != -1)
		return dp[index][sum];
	
	// 1.Try placing '+'
	bool placeAdd = isPossible(n, index + 1,
			sum + arr[index], M, arr, dp);

	// 2. Try placing '-'
	bool placeMinus = isPossible(n, index + 1,
				sum - arr[index], M, arr, dp);

	// calculate value of res for recursive case
	bool res = (placeAdd || placeMinus);

	// store the value for res for current
	// states and return for parent call
	dp[index][sum] = res;
	return res;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 6 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int M = 4;

	int dp[n + 1][MAX];
	memset(dp, -1, sizeof(dp));

	bool res;
	res = isPossible(n, 0, 0, M, arr, dp);

	cout << (res ? "True" : "False") << endl;
	return 0;
}

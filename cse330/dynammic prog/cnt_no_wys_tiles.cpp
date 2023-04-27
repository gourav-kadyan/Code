// C++ implementation to count number of ways to
// tile a floor of size n x m using 1 x m tiles
#include <bits/stdc++.h>

using namespace std;

// function to count the total number of ways
int countWays(int n, int m)
{

	// table to store values
	// of subproblems
	int count[n + 1];
	count[0] = 0;

	// Fill the table upto value n
	for (int i = 1; i <= n; i++) {

		// recurrence relation
		if (i > m)
			count[i] = count[i - 1] + count[i - m];

		// base cases and for i = m = 1
		else if (i < m || i == 1)
			count[i] = 1;

		// i = = m
		else
			count[i] = 2;
	}

	// required number of ways
	return count[n];
}

// Driver program to test above
int main()
{
	int n = 7, m = 4;
	cout << "Number of ways = "
		<< countWays(n, m);
	return 0;
}

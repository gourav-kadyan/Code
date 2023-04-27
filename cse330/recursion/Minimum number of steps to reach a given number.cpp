// CPP program to find minimum number
// of steps to reach M from N
#include <bits/stdc++.h>
using namespace std;

// Function to find a minimum number
// of steps to reach M from N
int Minsteps(int n, int m)
{
	int ans = 0;
	
	// Continue till m is greater than n
	while(m > n)
	{
		// If m is odd
		if(m&1)
		{
			// add one
			m++;
			ans++;
		}
		
		// divide m by 2	
		m /= 2;
		ans++;
	}
	
	// Return the required answer
	return ans + n - m;
}

// Driver code
int main()
{
	int n = 4, m = 6;
	
	cout << Minsteps(n, m);
	
	return 0;
}

// Recursive C++ program to count total number of handshakes
// when a person can shake hand with only one.
#include <bits/stdc++.h>
using namespace std;

// Function to find all possible handshakes
int handshake(int n)
{

	// When n becomes 0 that means all the persons have done
	// handshake with other
	if (n == 0)
		return 0;
	else
		return (n - 1) + handshake(n - 1);
}

// Driver code
int main()
{
	int n = 9;
	cout << " " << handshake(n);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

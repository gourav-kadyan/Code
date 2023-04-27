// C++ program to find n-th Fortunate number
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
	// Corner cases
	if (n <= 1) return false;
	if (n <= 3) return true;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n%2 == 0 || n%3 == 0) return false;

	for (int i=5; i*i<=n; i=i+6)
		if (n%i == 0 || n%(i+2) == 0)
		return false;

	return true;
}

// Function to Find primorial of order n
// (product of first n prime numbers).
long long int primorial(long long int n)
{
	long long int p = 2;
	n--;
	for (int i = 3; n != 0; i++) {
		if (isPrime(i)) {
			p = p * i;
			n--;
		}
		i++;
	}
	return p;
}

// Function to find next prime number greater
// than n
long long int findNextPrime(long long int n)
{
	// Note that difference (or m) should be
	// greater than 1.
	long long int nextPrime = n + 2;

	// loop continuously until isPrime
	// returns true for a number above n
	while (true) {

		// Ignoring the prime number that
		// is 1 greater than n
		if (isPrime(nextPrime))
			break;

		nextPrime++;
	}

	return nextPrime;
}

// Returns n-th Fortunate number
long long int fortunateNumber(int n)
{
long long int p = primorial(n);
return findNextPrime(p) - p;
}

// Driver function
int main()
{
	long long int n = 5;
	cout << fortunateNumber(n) << "\n";
	return 0;
}

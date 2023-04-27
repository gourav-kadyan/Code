//complexity o(root n log n)

// C++ program to find product of
// unique prime factors of a number
#include <bits/stdc++.h>
using namespace std;

// A function to print all prime
// factors of a given number n
long long int productPrimeFactors(int n)
{
	long long int product = 1;

	// Handle prime factor 2 explicitly
	// so that can optimally handle
	// other prime factors.
	if (n % 2 == 0) {
		product *= 2;
		while (n % 2 == 0)
			n = n / 2;
	}

	// n must be odd at this point.
	// So we can skip one element
	// (Note i = i + 2)
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		// While i divides n, print
		// i and divide n
		if (n % i == 0) {
			product = product * i;
			while (n % i == 0)
				n = n / i;
		}
	}

	// This condition is to handle the
	// case when n is a prime number
	// greater than 2
	if (n > 2)
		product = product * n;

	return product;
}

// Driver Code
int main()
{
	int n = 44;
	cout << productPrimeFactors(n);
	return 0;
}

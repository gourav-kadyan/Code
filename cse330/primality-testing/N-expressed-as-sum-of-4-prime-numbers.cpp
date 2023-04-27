// CPP program to express n as sum of 4 primes.
#include <bits/stdc++.h>
using namespace std;

// function to check if a number is prime or not
int isPrime(int x)
{
	// does square root of the number
	int s = sqrt(x);

	// traverse from 2 to sqrt(n)
	for (int i = 2; i <= s; i++)

		// if any divisor found then non prime
		if (x % i == 0)
			return 0;

	// if no divisor is found then it is a prime
	return 1;
}

void Num(int x, int& a, int& b)
{
	// iterates to check prime or not
	for (int i = 2; i <= x / 2; i++) {

		// calls function to check if i and x-i
		// is prime or not
		if (isPrime(i) && isPrime(x - i)) {

			a = i;
			b = x - i;

			// if two prime numbers are found,
			// then return
			return;
		}
	}
}

// function to generate 4 prime numbers adding upto n
void generate(int n)
{
	// if n<=7 then 4 numbers cannot sum to
	// get that number
	if (n <= 7)
		cout << "Impossible to form" << endl;

	// a and b stores the last two numbers
	int a, b;

	// if it is not even then 2 and 3 are first
	// two of sequence
	if (n % 2 != 0) {

		// calls the function to get the other
		// two prime numbers considering first two
		// primes as 2 and 3 (Note 2 + 3 = 5)
		Num(n - 5, a, b);

		// print 2 and 3 as the firsts two prime
		// and a and b as the last two.
		cout << "2 3 " << a << " " << b << endl;
	}

	// if it is even then 2 and 2 are first two
	// of sequence
	else {

		/// calls the function to get the other
		// two prime numbers considering first two
		// primes as 2 and 2 (Note 2 + 2 = 4)
		Num(n - 4, a, b);

		// print 2 and 2 as the firsts two prime
		// and a and b as the last two.
		cout << "2 2 " << a << " " << b << endl;
	}
}

// driver program to test the above function
int main()
{
	int n = 28;
	generate(n);
	return 0;
}

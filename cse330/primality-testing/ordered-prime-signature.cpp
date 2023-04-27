// CPP to find total number of divisors of a
// number, using ordered prime signature
#include <bits/stdc++.h>
using namespace std;

// Finding primes upto entered number
vector<int> primes(int n)
{
	bool prime[n + 1];
	
	// Finding primes by Sieve
	// of Eratosthenes method
	memset(prime, true, sizeof(prime));
	
	for (int i = 2; i * i <= n; i++)
	{
		
		// If prime[i] is not changed,
		// then it is prime
		if (prime[i] == true) {
			
			// Update all multiples of p
			for (int j = i * 2; j <= n; j += i)
				prime[j] = false;
		}
	}
	
	vector<int> arr;
	
	// Forming array of the prime numbers found
	for (int i = 2; i <= n; i++)
	{
		if (prime[i])
			arr.push_back(i);
	}
	return arr;
}

// Finding ordered prime signature of the number
vector<int> signature( int n)
{
	vector<int> r = primes(n);
	
	// Map to store prime factors and
	// the related exponents
	map<int, int> factor;
	
	// Declaring an iterator for map
	map<int, int>::iterator it;
	vector<int> sort_exp;
	int k, t = n;
	it = factor.begin();
	
	// Finding prime factorization of the number
	for (int i = 0; i < r.size(); i++)
	{
		if (n % r[i] == 0) {
			k = 0;
			while (n % r[i] == 0) {
				n = n / r[i];
				k++;
			}
			
			// Storing the prime factor and
			// its exponent in map
			factor.insert(it, pair<int, int>(r[i], k));
			
			// Storing the exponent in a vector
			sort_exp.push_back(k);
		}
	}
	
	// Sorting the stored exponents
	sort(sort_exp.begin(), sort_exp.end());
	
	// Printing the prime signature
	cout << " The Ordered Prime Signature of " <<
		t << " is : \n{ ";
		
	for (int i = 0; i < sort_exp.size(); i++)
	{
		if (i != sort_exp.size() - 1)
			cout << sort_exp[i] << ", ";
		else
			cout << sort_exp[i] << " }\n";
	}
	return sort_exp;
}

// Finding total number of divisors of the number
void divisors(int n)
{
	int f = 1, l;
	vector<int> div = signature(n);
	l = div.size();
	
	// Adding one to each element present
	for (int i = 0; i < l; i++)
	{
		
		// in ordered prime signature
		div[i] += 1;
		
		// Multiplying the elements
		f *= div[i];
	}
	cout << "The total number of divisors of " <<
		n << " is " << f << "\n";
}

// Driver Method
int main()
{
	int n = 13;
	divisors(n);
	return 0;
}

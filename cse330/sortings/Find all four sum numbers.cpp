// A hashing based CPP program
// to find if there are
// four elements with given sum.
#include <bits/stdc++.h>
using namespace std;

// The function finds four
// elements with given sum X
void findFourElements(int arr[], int n, int X)
{
	// Store sums of all pairs
	// in a hash table
	unordered_map<int, pair<int, int> > mp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			mp[arr[i] + arr[j]] = { i, j };

	// Traverse through all pairs and search
	// for X - (current pair sum).
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];

			// If X - sum is present in hash table,
			if (mp.find(X - sum) != mp.end()) {

				// Making sure that all elements are
				// distinct array elements and an element
				// is not considered more than once.
				pair<int, int> p = mp[X - sum];
				if (p.first != i && p.first != j
					&& p.second != i && p.second != j) {
					cout << arr[i] << ", " << arr[j] << ", "
						<< arr[p.first] << ", "
						<< arr[p.second];
					return;
				}
			}
		}
	}
}

// Driver code
int main()
{
	int arr[] = { 10, 20, 30, 40, 1, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int X = 91;
	
	// Function call
	findFourElements(arr, n, X);
	return 0;
}

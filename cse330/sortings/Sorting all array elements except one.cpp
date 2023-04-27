// CPP program to sort all elements except
// element at index k.
#include <bits/stdc++.h>
using namespace std;

int sortExceptK(int arr[], int k, int n)
{
	// Move k-th element to end
	swap(arr[k], arr[n-1]);

	// Sort all elements except last
	sort(arr, arr + n - 1);

	// Store last element (originally k-th)
	int last = arr[n-1];

	// Move all elements from k-th to one
	// position ahead.
	for (int i=n-1; i>k; i--)
	arr[i] = arr[i-1];

	// Restore k-th element
	arr[k] = last;
}

// Driver code
int main()
{
	int a[] = {10, 4, 11, 7, 6, 20 };
	int k = 2;
	int n = sizeof(a) / sizeof(a[0]);
	sortExceptK(a, k, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

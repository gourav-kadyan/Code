/* C++ program to find size of array after repeated
deletion of LIS */
#include <bits/stdc++.h>
using namespace std;

// Function to construct Maximum Sum LIS
vector<int> findLIS(vector<int> arr, int n)
{
	// L[i] - The Maximum Sum Increasing
	// Subsequence that ends with arr[i]
	vector <vector<int> > L(n);

	// L[0] is equal to arr[0]
	L[0].push_back(arr[0]);

	// start from index 1
	for (int i = 1; i < n; i++)
	{
		// for every j less than i
		for (int j = 0; j < i; j++)
		{
			/* L[i] = {MaxSum(L[j])} + arr[i]
			where j < i and arr[j] < arr[i] */
			if (arr[i] > arr[j] && (L[i].size() < L[j].size()))
				L[i] = L[j];
		}

		// L[i] ends with arr[i]
		L[i].push_back(arr[i]);
	}

	// set lis = LIS
	// whose size is max among all
	int maxSize = 1;
	vector<int> lis;
	for (vector<int> x : L)
	{
		// The > sign makes sure that the LIS
		// ending first is chose.
		if (x.size() > maxSize)
		{
			lis = x;
			maxSize = x.size();
		}
	}

	return lis;
}

// Function to minimize array
void minimize(int input[], int n)
{
	vector<int> arr(input, input + n);

	while (arr.size())
	{
		// Find LIS of current array
		vector<int> lis = findLIS(arr, arr.size());

		// If all elements are in decreasing order
		if (lis.size() < 2)
			break;

		// Remove lis elements from current array. Note
		// that both lis[] and arr[] are sorted in
		// increasing order.
		for (int i=0; i<arr.size() && lis.size()>0; i++)
		{
			// If first element of lis[] is found
			if (arr[i] == lis[0])
			{
				// Remove lis element from arr[]
				arr.erase(arr.begin()+i) ;
				i--;

				// Erase first element of lis[]
				lis.erase(lis.begin()) ;
			}
		}
	}

	// print remaining element of array
	int i;
	for (i=0; i < arr.size(); i++)
		cout << arr[i] << " ";

	// print -1 for empty array
	if (i == 0)
		cout << "-1";
}

// Driver function
int main()
{
	int input[] = { 3, 2, 6, 4, 5, 1 };
	int n = sizeof(input) / sizeof(input[0]);

	// minimize array after deleting LIS
	minimize(input, n);

	return 0;
}

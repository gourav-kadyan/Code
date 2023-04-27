/* Dynamic Programming solution to construct
Maximum Sum Increasing Subsequence */
#include <bits/stdc++.h>
using namespace std;

// Function to construct and print the Maximum Sum
// Increasing Subsequence
void constructMaxSumIS(vector<int> arr, int n)
{
	// L[i] stores the value of Maximum Sum Increasing
	// Subsequence that ends with arr[i] and the index of
	// previous element used to construct the Subsequence
	vector<pair<int, int> > L(n);

	int index = 0;
	for (int i : arr) {
		L[index] = { i, index };
		index++;
	}

	// Set L[0].second equal to -1
	L[0].second = -1;

	// start from index 1
	for (int i = 1; i < n; i++) {
		// for every j less than i
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]
				and L[i].first < arr[i] + L[j].first) {
				L[i].first = arr[i] + L[j].first;
				L[i].second = j;
			}
		}
	}

	int maxi = INT_MIN, currIndex, track = 0;

	for (auto p : L) {
		if (p.first > maxi) {
			maxi = p.first;
			currIndex = track;
		}
		track++;
	}

	// Stores the final Subsequence
	vector<int> result;

	// Index of previous element
	// used to construct the Subsequence
	int prevoiusIndex;

	while (currIndex >= 0) {
		result.push_back(arr[currIndex]);
		prevoiusIndex = L[currIndex].second;

		if (currIndex == prevoiusIndex)
			break;

		currIndex = prevoiusIndex;
	}

	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << " ";
}

// Driver Code
int main()
{
	vector<int> arr = { 1, 101, 2, 3, 100, 4, 5 };
	int n = arr.size();

	// Function call
	constructMaxSumIS(arr, n);

	return 0;
}

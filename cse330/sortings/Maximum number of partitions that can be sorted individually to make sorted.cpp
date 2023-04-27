// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum partitions.
int maxPartitions(vector<int>& arr)
{
	int N = arr.size();

	// To keep track of max
	// and min elements at every index
	vector<int> leftMax(arr.size());
	vector<int> rightMin(arr.size());

	leftMax[0] = arr[0];

	for (int i = 1; i < N; i++) {
		leftMax[i] = max(leftMax[i - 1],
						arr[i]);
	}

	rightMin[N - 1] = arr[N - 1];

	for (int i = N - 2; i >= 0; i--) {
		rightMin[i] = min(rightMin[i + 1],
						arr[i]);
	}

	int count = 0;

	for (int i = 0; i < N - 1; i++) {
		if (leftMax[i] <= rightMin[i + 1]) {
			count++;
		}
	}

	// Return count + 1 as the final answer
	return count + 1;
}

// Driver code
int main()
{
	vector<int> arr{ 10, 0, 21, 32, 68 };

	cout << maxPartitions(arr);
	return 0;
}

// A Dynamic Programming based C++ program to find maximum
// number of A's that can be printed using four keys

#include <bits/stdc++.h>
using namespace std;

// This function returns the optimal length string for N keystrokes
int findoptimal(int N)
{
	// The optimal string length is N when N is smaller than 7
	if (N <= 6)
		return N;

	// An array to store result of subproblems
	int screen[N];

	int b; // To pick a breakpoint

	// Initializing the optimal lengths array for until 6 input
	// strokes.
	int n;
	for (n = 1; n <= 6; n++)
		screen[n - 1] = n;

	// Solve all subproblems in bottom-up manner
	for (n = 7; n <= N; n++) {

		// for any keystroke n, we will need to choose between:-
		// 1. pressing Ctrl-V once after copying the
		// A's obtained by n-3 keystrokes.

		// 2. pressing Ctrl-V twice after copying the A's
		// obtained by n-4 keystrokes.

		// 3. pressing Ctrl-V thrice after copying the A's
		// obtained by n-5 keystrokes.
		screen[n - 1] = max(2 * screen[n - 4],
							max(3 * screen[n - 5],
4 * screen[n - 6]));
	}

	return screen[N - 1];
}

// Driver program
int main()
{
	int N;

	// for the rest of the array we will reply on the previous
	// entries to compute new ones
	for (N = 1; N <= 20; N++)
		printf("Maximum Number of A's with %d keystrokes is %d\n",
			N, findoptimal(N));
}

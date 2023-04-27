// C++ program to print all N-bit binary
#include <bits/stdc++.h>
using namespace std;

/* function to generate n digit numbers*/
void printRec(string number, int extraOnes,
			int remainingPlaces)
{
	/* if number generated */
	if (0 == remainingPlaces) {
		cout << number << " ";
		return;
	}

	/* Append 1 at the current number and reduce
	the remaining places by one */
	printRec(number + "1", extraOnes + 1,
			remainingPlaces - 1);

	/* If more ones than zeros, append 0 to the
	current number and reduce the remaining
	places by one*/
	if (0 < extraOnes)
		printRec(number + "0", extraOnes - 1,
				remainingPlaces - 1);
}

void printNums(int n)
{
	string str = "";
	printRec(str, 0, n);
}

// Driver code
int main()
{
	int n = 4;

	// Function call
	printNums(n);
	return 0;
}

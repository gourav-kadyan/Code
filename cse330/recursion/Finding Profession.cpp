// C++ program to find profession of a person at
// given level and position.
#include<bits/stdc++.h>
using namespace std;

/* Function to get no of set bits in binary
representation of passed binary no. */
int countSetBits(int n)
{
	int count = 0;
	while (n)
	{
	n &= (n-1) ;
	count++;
	}
	return count;
}

// Returns 'e' if profession of node at given level
// and position is engineer. Else doctor. The function
// assumes that given position and level have valid values.
char findProffesion(int level, int pos)
{
	// Count set bits in 'pos-1'
	int c = countSetBits(pos-1);

	// If set bit count is odd, then doctor, else engineer
	return (c%2)? 'd' : 'e';
}

// Driver code
int main(void)
{
	int level = 3, pos = 4;
	(findProffesion(level, pos) == 'e')? cout << "Engineer"
									: cout << "Doctor" ;
	return 0;
}

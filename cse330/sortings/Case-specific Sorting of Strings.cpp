// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the sorted string
string getSortedString(string s, int n)
{

	// Vectors to store the lowercase
	// and uppercase characters
	vector<char> v1, v2;
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			v1.push_back(s[i]);
		if (s[i] >= 'A' && s[i] <= 'Z')
			v2.push_back(s[i]);
	}

	// Sort both the vectors
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int i = 0, j = 0;
	for (int k = 0; k < n; k++) {

		// If current character is lowercase
		// then pick the lowercase character
		// from the sorted list
		if (s[k] >= 'a' && s[k] <= 'z') {
			s[k] = v1[i];
			++i;
		}

		// Else pick the uppercase character
		else if (s[k] >= 'A' && s[k] <= 'Z') {
			s[k] = v2[j];
			++j;
		}
	}

	// Return the sorted string
	return s;
}

// Driver code
int main()
{
	string s = "gEeksfOrgEEkS";
	int n = s.length();

	cout << getSortedString(s, n);

	return 0;
}

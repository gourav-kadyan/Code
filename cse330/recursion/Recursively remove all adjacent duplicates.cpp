// C++ Program for above approach

#include <bits/stdc++.h>
using namespace std;

// Recursively removes adjacent
// duplicates from str and
// returns new string. las_removed
// is a pointer to
// last_removed character
string removeDuplicates(string s, char ch)
{

	// If length of string is 1 or 0
	if (s.length() <= 1) {
		return s;
	}

	int i = 0;
	while (i < s.length()) {
		if (i + 1 < s.length() && s[i] == s[i + 1]) {
			int j = i;
			while (j + 1 < s.length() && s[j] == s[j + 1]) {
				j++;
			}
			char lastChar = i > 0 ? s[i - 1] : ch;

			string remStr = removeDuplicates(
				s.substr(j + 1, s.length()), lastChar);

			s = s.substr(0, i);
			int k = s.length(), l = 0;

			// Recursively remove all the adjacent
			// characters formed by removing the
			// adjacent characters
			while (remStr.length() > 0 && s.length() > 0
				&& remStr[0] == s[s.length() - 1]) {

				// Have to check whether this is the
				// repeated character that matches the
				// last char of the parent String
				while (remStr.length() > 0
					&& remStr[0] != ch
					&& remStr[0] == s[s.length() - 1]) {
					remStr
						= remStr.substr(1, remStr.length());
				}
				s = s.substr(0, s.length() - 1);
			}
			s = s + remStr;
			i = j;
		}
		else {
			i++;
		}
	}
	return s;
}

// Driver Code
int main()
{

	string str1 = "mississipie";
	cout << removeDuplicates(str1, ' ') << endl;

	string str2 = "ocvvcolop";
	cout << removeDuplicates(str2, ' ') << endl;
}

// This code is contributed by nirajgusain5

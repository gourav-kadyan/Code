#include <bits/stdc++.h>
using namespace std;
char getMaxCountChar(vector<int>& count)
{
	int max = 0;
	char ch;
	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			ch = 'a' + i;
		}
	}
	return ch;
}
string rearrangeString(string S)
{
	int n = S.size();
	if (n == 0)
		return "";
	vector<int> count(26, 0);
	for (auto& ch : S)
		count[ch - 'a']++;
	char ch_max = getMaxCountChar(count);
	int maxCount = count[ch_max - 'a'];
	if (maxCount > (n + 1) / 2)
		return "";
	string res(n, ' ');
	int ind = 0;
	while (maxCount) {
		res[ind] = ch_max;
		ind = ind + 2;
		maxCount--;
	}

	count[ch_max - 'a'] = 0;
	for (int i = 0; i < 26; i++) {

		while (count[i] > 0) {

			ind = (ind >= n) ? 1 : ind;
			res[ind] = 'a' + i;
			ind += 2;
			count[i]--;
		}
	}

	return res;
}
int main()
{
	string str;
    cin >> str;
	string res = rearrangeString(str);
	if (res == "")
		cout << "Not possible" << endl;
	else
		cout << res << endl;

	return 0;
}

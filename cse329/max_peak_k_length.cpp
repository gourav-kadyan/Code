#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
void findSubArray(int* a, int n, int k)
{
	// Make prefix array to store
	// the prefix sum of peak count
	int pref[n];

	pref[0] = 0;

	for (int i = 1; i < n - 1; ++i) {

		// Count peak for previous index
		pref[i] = pref[i - 1];

		// Check if this element is a peak
		if (a[i] > a[i - 1] && a[i] > a[i + 1])

			// Increment the count
			pref[i]++;
	}

	int peak = 0, left = 0;

	for (int i = 0; i + k - 1 < n; ++i)

		// Check if number of peak in the sub array
		// whose l = i is greater or not
		if (pref[i + k - 2] - pref[i] > peak) {
			peak = pref[i + k - 2] - pref[i];
			left = i;
		}

	// Print the result
	cout << "Left = " << left + 1 << endl;
	cout << "Right = " << left + k << endl;
	cout << "Peak = " << peak << endl;
}
void krdiyasuru()
{
    cii(n,k);
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    findSubArray(arr, n, k);
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
        krosuru
    {
        krdiyasuru();
    }
}
 
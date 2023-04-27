#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isPrime(int n)
    {
    	// Corner cases
    	if (n <= 1) return false;
    	if (n <= 3) return true;
    
    	// This is checked so that we can skip
    	// middle five numbers in below loop
    	if (n%2 == 0 || n%3 == 0) return false;
    
    	for (int i=5; i*i<=n; i=i+6)
    		if (n%i == 0 || n%(i+2) == 0)
    		return false;
    
    	return true;
    }
    long long nthMysterious(long long N){
        // code here
        long long ans = 0;
        for(int i=0;N!=0;i++){
            if(isPrime(i)==true){
                N--;
                ans = i;
            }
        }
        return ans*ans + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.nthMysterious(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
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
    int nthTerm(int n){
        // code here
        int i = 0 , ans;
       for(int check = 2; i < n; check++)
       {       
              if(isPrime(check))
               {
                  ans = check;
                  i++ ;
               }
       }
       return (ans+1)*n;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n;
        Solution ob;
        cout<<ob.nthTerm(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
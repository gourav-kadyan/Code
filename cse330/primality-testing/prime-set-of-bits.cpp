#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool prime(int n){
        if(n==1 or n==0) return false;
        for(int i=2; i<=n/2;i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    int num_set_bits(string s){
        int count=0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='1')
                count++;
        }
        return count;
    }
    string Binary_conversion(int n){
        string ans="";
        
        while(n){
            int d = n%2;
            ans = to_string(d)+ans;
            n/=2;
        }
        return ans;
    }
    int primeSetBits(int left, int right){
        // code here
        int count=0;
        for(int i=left ; i<=right; i++){
            string s = Binary_conversion(i);
            int num = num_set_bits(s);
            
            if(prime(num))
                count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout<<ob.primeSetBits(L,R)<<endl;
    }
    return 0;
}

// } Driver Code Ends
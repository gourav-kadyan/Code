#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {

public:
    bool isprime(long long  n)
   {
   
    if (n <= 1) return false;
    if (n <= 3) return true;
   
    
    if (n%2 == 0 || n%3 == 0) return false;
   
    for (long long int i=5; i*i<=n; i=i+6)
     if (n%i == 0 || n%(i+2) == 0)
     return false;
   
    return true;
   }
   long long primorial(long long n){
       // Code here
       long long pr=1;
       int m=1e9+7;
       for(int i=2;i<=n;i++)
       {
           if(isprime(i))
           {
               pr=(pr*i)%m;
           }
       }
       return pr%m;
   }
};

//{ Driver Code Starts.

int main()
{
    Solution ob;
    int t; cin >> t;
    while(t--)
    {
        long long n;
        cin>>n;
        cout << ob.primorial(n) << endl;
    }
    return 0;
} 
// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool isprime(int n)
{ if (n<2)
return false;
for(int i=2;i*i<=n;i++)
{
if(n%i==0)
return false; }
return true; }

   bool isSumOfKprimes(int n, int k)
   {
       // Code Here
       if(n>=2*k && k==1)
       {
           if(isprime(n))
           {
               return 1;
           }
           return 0;
       }
       if(n>=2*k && k==2)
       {
           if(n%2==0)
           {
               return 1;
           }
           else
           {
               if(isprime(n-2))
               {
                   return 1;
               }
               return 0;
           }
       }
       if(n>=2*k && k>=3)
       {
           return 1;
       }
       else
       return 0;
   }
};


//{ Driver Code Starts.

int main()
{
    Solution ob;
	int t;
	cin>>t;
	while(t--)
	{
		int N,K;
		cin>>N>>K;
        if(ob.isSumOfKprimes(N,K))
		    cout<<"1\n";
        else
             cout<<"0\n";
	}
	return 0;
}
// } Driver Code Ends
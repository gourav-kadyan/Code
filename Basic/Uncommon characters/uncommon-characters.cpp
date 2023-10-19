//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            int arr1[26] = {0};
            int arr2[26] = {0};
            for(int i=0;i<A.length();i++){
                arr1[A[i] - 'a'] = 1;
            }
            for(int i=0;i<B.length();i++){
                arr2[B[i] - 'a'] = 1;
            }
            string s = "";
            for(int i=0;i<A.length();i++){
                if(arr2[A[i]-'a'] == 0){
                    s = A[i] + s;
                }
            }
            for(int i=0;i<B.length();i++){
                if(arr1[B[i] - 'a'] == 0){
                    s = B[i] + s;
                }
            }
            if(s.length() == 0){
                return "-1";
            }
            set<char> st;
            for(auto it:s){
                st.insert(it);
            }
            string ans = "";
            for(auto it:st){
                ans += it;
            }
            return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
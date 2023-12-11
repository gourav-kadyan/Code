//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long long ans = INT_MIN;
        vector<long long> arr(N,0);
        arr[0] = Arr[0];
        for(int i=1;i<N;i++){
            arr[i] = (long long)arr[i-1] + Arr[i];
        }
        ans = arr[K-1];
        for(int i=K;i<N;i++){
            ans = max(ans,arr[i]-arr[i-K]);
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a,Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        int mxd = INT_MIN;
        for(int i=0;i<n;i++){
            mxd = max(mxd,arr[i].dead);
        }
        vector<int> v(mxd+1,-1);
        int count = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int currid = arr[i].id;
            int currpro = arr[i].profit;
            int currdead  = arr[i].dead;
            for(int k = currdead;k > 0;k--){
                if(v[k] == -1){
                    ans += currpro;
                    count++;
                    v[k] = currid;
                    break;
                }
            }
        }
        vector<int> lol;
        lol.push_back(count);
        lol.push_back(ans);
        return lol;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
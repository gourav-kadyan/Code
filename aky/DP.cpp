//LIS
class Solution
{
    public:
    int solve(int x,int ar[],int n, int prev,vector<vector<int>>&dp){
        if(n==x)
            return 0;
        int take=0,notTake=0;
        if(dp[x][prev+1]!=-1)
            return dp[x][prev+1];
        if(prev==-1||ar[x]>ar[prev])
            take=1+solve(x+1,ar,n,x,dp);
        notTake=solve(x+1,ar,n,prev,dp);
        return dp[x][prev+1]=max(take,notTake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int ar[])
    {
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solve(0,ar,n,-1,dp);
    }
};
//LCS
 public:
    int solve(int x,int y,string &s1,string &s2,int m,int n,vector<vector<int>>&dp){
        if(x==m||y==n)
        return 0;
        if(dp[x][y]!=-1)
        return dp[x][y];
        if(s1[x]==s2[y]){
            return dp[x][y]=1+solve(x+1,y+1,s1,s2,m,n,dp);
        }
        else{
            int t1=solve(x+1,y,s1,s2,m,n,dp);
            int t2=solve(x,y+1,s1,s2,m,n,dp);
            return dp[x][y]= max(t1,t2);
        }
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x,vector<int>(y,-1));
        // your code here
        return solve(0,0,s1,s2,x,y,dp);
    }
};

//Binomial

    int solve(int n,int r,vector<vector<int>>&dp){
        if(r>n)
        return 0;
        if(n==0||r==0)
        return 1;
        if(dp[n][r]!=-1)
        return dp[n][r];
        return dp[n][r]=(solve(n-1,r-1,dp)%mod+solve(n-1,r,dp)%mod)%mod;
    }
    int nCr(int n, int r){
        vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        return solve(n,r,dp)%mod;
    }


    //box Stacking

    struct box {
        int l,w,h;
    };
    static bool mycp(box b1,box b2){
        return (b1.l*b1.w)<(b2.l*b2.w);
    }

    int solve(int index,int prev,vector<box>&v,vector<int>&dp){
        if(index<0)
        return 0;
        if(dp[index]!=-1)
        return dp[index];

        int mxHeight=0;
        for(int x=index;x>=0;x--){
            if(prev==-1||(v[x].l<v[prev].l &&v[x].w<v[prev].w)){
                mxHeight=max(mxHeight,(solve(x-1,x,v,dp)+v[x].h));

            }
        }
        return dp[index]= mxHeight;
    }
    int maxHeight(int h[],int w[],int l[],int n)
    {
        vector<box>v;
        for(int x=0;x<n;x++){
            box t;
            t.h=h[x];
            t.w=max(w[x],l[x]);
            t.l=min(w[x],l[x]);
            v.push_back(t);


            t.h=w[x];
            t.w=max(h[x],l[x]);
            t.l=min(h[x],l[x]);
            v.push_back(t);

            t.h=l[x];
            t.w=max(w[x],h[x]);
            t.l=min(w[x],h[x]);
            v.push_back(t);

        }
        sort(v.begin(),v.end(),mycp);
        vector<int>dp(v.size(),-1);

        return solve(v.size()-1,-1,v,dp);

        //Your code here
    }



    //edit distance
    int solve(int x1,int x2,string &s,string &t,vector<vector<int>>&dp){
        if(x1==s.length())
        return t.length()-x2;
        if(x2==t.length()){
            return s.length()-x1;
        }
        if(dp[x1][x2]!=-1)
        return dp[x1][x2];
        if(s[x1]==t[x2])
        return dp[x1][x2]=solve(x1+1,x2+1,s,t,dp);
        else{
            int ins=1+solve(x1,x2+1,s,t,dp);
            int del=1+solve(x1+1,x2,s,t,dp);
            int rep=1+solve(x1+1,x2+1,s,t,dp);
            return dp[x1][x2]=min(ins,min(del,rep));
        }
    }
    int editDistance(string s, string t) {
        // Code here

        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return solve(0,0,s,t,dp);
    }


    //balanced partion
    //valid subsequence divisible by m


bool solve(int x,int ar[],int prev,int m){
    if(x<0){
        if(prev%m==0)
        return true;
        return false;
    }
    return solve(x-1,ar,prev+ar[x],m)||solve(x-1,ar,prev-ar[x],m);
}
bool validSequence(int ar[], int n, int M)
{
    vector<int>t(n+1,)
    return solve(n-1,ar,0,M);
    // Complete the function



}


//LCS of '0' K Repeated String

// Refer https://www.geeksforgeeks.org/longest-repeating-subsequence/
// for complete code.
// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();

    // Create and initialize DP table
    int dp[n+1][n+1];
  //initializing first row and column in dp table
    for(int i=0;i<=n;i++){
      dp[i][0] =0;
      dp[0][i] =0;
    }


    // Fill dp table (similar to LCS loops)
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            // If characters match and indexes are
            // not same
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];

            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}

Minimum number of deletions and insertions


// Dynamic Programming C++ implementation to find
// minimum number of deletions and insertions
// using memoization technique
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

// Returns length of longest common subsequence
int lcs(string& s1, string& s2, int i, int j)
{
    if (i == 0 || j == 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s1[i - 1] == s2[j - 1]) {
        return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1);
    }
    else {
        return dp[i][j] = max(lcs(s1, s2, i, j - 1),
                              lcs(s1, s2, i - 1, j));
    }
}

// function to find minimum number
// of deletions and insertions
void printMinDelAndInsert(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();

    dp[m][n];

    //    initialising dp array as -1
    memset(dp, -1, sizeof(dp));

    int len = lcs(str1, str2, m, n);

    cout << "Minimum number of deletions = " << (m - len)
         << endl;

    cout << "Minimum number of insertions = " << (n - len)
         << endl;
}

// driver code
int main()
{
    string str1 = "heap";
    string str2 = "pea";

    // Function Call
    printMinDelAndInsert(str1, str2);

    return 0;
}

// This code is contributed b

	Minimum insertions to sort an array





	public:
	int minInsertions(int arr[], int N)
	{
	    vector <int> v;
    v.push_back(arr[0]);
    for(int i=1; i<N; i++){
        auto it = upper_bound(v.begin(), v.end(), arr[i]);
        if(it == v.end()) v.push_back(arr[i]);
        else *it = arr[i];
    }
    return N-v.size();
	    // Your code goes here
	}
};


Count the number of ways to tile the floor of size n x m using
class Solution{
	public:
		int countWays(int n, int m)
	{
	    // Code here.
	    vector<int>dp(n+1,-1);
	    for(int x=1;x<=n;x++){
	        if(x<m){
	            dp[x]=1;
	        }
	        else if(x==m){
	            dp[x]=2;
	        }
	        else{
	            dp[x]=dp[x-1]+dp[x-m];
	        }
	    }
	    return dp[n];
	}
};


13.	Minimum steps to delete a string


public:
	int Rec(string &s,int l,int r,vector<vector<int>> &dp)
    {
        if(l == r)  return 1;

        if(l > r)  return 0;

        if(dp[l][r] != -1)  return dp[l][r];

        int case1 = Rec(s,l+1,r,dp) + 1;

        int case2 = INT_MAX;

        for(int i = l+1 ; i <= r ; i++)
        if(s[i]==s[l])
        case2 = min( case2 , ( (l+1 == i) ? 1 : Rec(s,l+1,i-1,dp) ) + Rec(s,i+1,r,dp) );

        return dp[l][r] = min(case1 , case2);
    }
	int minStepToDeleteString(string s)
	{
	    vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));

	    return Rec(s,0,s.length()-1,dp);
	}
};

14.	Subset with sum divisible by m


// C++ program to check if there is a subset
// with sum divisible by m.
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset
// of arr[] with sum divisible by m
bool helper(int N, int nums[], int sum, int idx, int m){
	// if we reach last index
	if(idx == N){
		// and if the sum mod m is zero
		if(sum && sum%m == 0){
			// return
			return true ;
		}
		return false ;
	}

	// 2 choices - to pick or to not pick
	bool picked = helper(N, nums, sum+nums[idx], idx+1,m) ;
	bool notPicked = helper(N, nums, sum,		 idx+1, m) ;

	return picked || notPicked ;
}

bool modularSum(int arr[], int n, int m)
{
	return helper(n, arr, 0, 0, m) ;
}

// Driver code
int main()
{
	int arr[] = {1, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int m = 5;

	modularSum(arr, n, m) ? cout << "YES\n" :
							cout << "NO\n";

	return 0;
}

	Count of strings that can be formed using a, b and c under given constraints


	//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    long long int count = 0;

    if(n>=1){

        //aaa...

        count += 1;

        //b...aaa...

        count += n;

        //c...aaa...

        count += n;

        if(n>=2){

            //bc...aaa...

            count += n*(n-1);

            //cc...aaa...

            count += n*(n-1)/2;

            if(n>=3){

                //bcc...aaa...

                count += (n-2)*(n-1)*n/2;

            }

        }

    }

    return count;
}
16.	Shortest Uncommon Subsequence

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int x,int y,string &s,string &t){
        if(x==s.length())
        return 600;
        if(y==t.length())
        return 1;
        int z=y;
        for(;z<t.length();z++){
            if(s[x]==t[z])
            break;
        }
        if(z==t.length())
        return 1;
        int take=1+solve(x+1,z+1,s,t);
        int notTake=solve(x+1,y,s,t);
        return min(take,notTake);
    }
    int shortestUnSub(string S, string T) {
        // code here
        int ans=solve(0,0,S,T);
        if(ans==600)
        return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
17.	Size of array after repeated deletion of LIS
/* C++ program to find size of array after repeated
deletion of LIS */
#include <bits/stdc++.h>
using namespace std;

// Function to construct Maximum Sum LIS
vector<int> findLIS(vector<int> arr, int n)
{
	// L[i] - The Maximum Sum Increasing
	// Subsequence that ends with arr[i]
	vector <vector<int> > L(n);

	// L[0] is equal to arr[0]
	L[0].push_back(arr[0]);

	// start from index 1
	for (int i = 1; i < n; i++)
	{
		// for every j less than i
		for (int j = 0; j < i; j++)
		{
			/* L[i] = {MaxSum(L[j])} + arr[i]
			where j < i and arr[j] < arr[i] */
			if (arr[i] > arr[j] && (L[i].size() < L[j].size()))
				L[i] = L[j];
		}

		// L[i] ends with arr[i]
		L[i].push_back(arr[i]);
	}

	// set lis = LIS
	// whose size is max among all
	int maxSize = 1;
	vector<int> lis;
	for (vector<int> x : L)
	{
		// The > sign makes sure that the LIS
		// ending first is chose.
		if (x.size() > maxSize)
		{
			lis = x;
			maxSize = x.size();
		}
	}

	return lis;
}

// Function to minimize array
void minimize(int input[], int n)
{
	vector<int> arr(input, input + n);

	while (arr.size())
	{
		// Find LIS of current array
		vector<int> lis = findLIS(arr, arr.size());

		// If all elements are in decreasing order
		if (lis.size() < 2)
			break;

		// Remove lis elements from current array. Note
		// that both lis[] and arr[] are sorted in
		// increasing order.
		for (int i=0; i<arr.size() && lis.size()>0; i++)
		{
			// If first element of lis[] is found
			if (arr[i] == lis[0])
			{
				// Remove lis element from arr[]
				arr.erase(arr.begin()+i) ;
				i--;

				// Erase first element of lis[]
				lis.erase(lis.begin()) ;
			}
		}
	}

	// print remaining element of array
	int i;
	for (i=0; i < arr.size(); i++)
		cout << arr[i] << " ";

	// print -1 for empty array
	if (i == 0)
		cout << "-1";
}

// Driver function
int main()
{
	int input[] = { 3, 2, 6, 4, 5, 1 };
	int n = sizeof(input) / sizeof(input[0]);

	// minimize array after deleting LIS
	minimize(input, n);

	return 0;
}
18.	Find number of times a string occurs as a subsequence


// A Naive recursive C++ program to find the number of
// times the second string occurs in the first string,
// whether continuous or discontinuous
#include <iostream>
using namespace std;

// Recursive function to find the number of times
// the second string occurs in the first string,
// whether continuous or discontinuous
int count(string a, string b, int m, int n)
{
	// If both first and second string is empty,
	// or if second string is empty, return 1
	if ((m == 0 && n == 0) || n == 0)
		return 1;

	// If only first string is empty and second
	// string is not empty, return 0
	if (m == 0)
		return 0;

	// If last characters are same
	// Recur for remaining strings by
	// 1. considering last characters of both strings
	// 2. ignoring last character of first string
	if (a[m - 1] == b[n - 1])
		return count(a, b, m - 1, n - 1) +
			count(a, b, m - 1, n);
	else
		// If last characters are different, ignore
		// last char of first string and recur for
		// remaining string
		return count(a, b, m - 1, n);
}

// Driver code
int main()
{
	string a = "GeeksforGeeks";
	string b = "Gks";

	cout << count(a, b, a.size(), b.size()) << endl;

	return 0;
}
19.	Printing Maximum Sum Increasing Subsequence


/* Dynamic Programming solution to construct
Maximum Sum Increasing Subsequence */
#include <bits/stdc++.h>
using namespace std;

// Function to construct and print the Maximum Sum
// Increasing Subsequence
void constructMaxSumIS(vector<int> arr, int n)
{
	// L[i] stores the value of Maximum Sum Increasing
	// Subsequence that ends with arr[i] and the index of
	// previous element used to construct the Subsequence
	vector<pair<int, int> > L(n);

	int index = 0;
	for (int i : arr) {
		L[index] = { i, index };
		index++;
	}

	// Set L[0].second equal to -1
	L[0].second = -1;

	// start from index 1
	for (int i = 1; i < n; i++) {
		// for every j less than i
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]
				and L[i].first < arr[i] + L[j].first) {
				L[i].first = arr[i] + L[j].first;
				L[i].second = j;
			}
		}
	}

	int maxi = INT_MIN, currIndex, track = 0;

	for (auto p : L) {
		if (p.first > maxi) {
			maxi = p.first;
			currIndex = track;
		}
		track++;
	}

	// Stores the final Subsequence
	vector<int> result;

	// Index of previous element
	// used to construct the Subsequence
	int prevoiusIndex;

	while (currIndex >= 0) {
		result.push_back(arr[currIndex]);
		prevoiusIndex = L[currIndex].second;

		if (currIndex == prevoiusIndex)
			break;

		currIndex = prevoiusIndex;
	}

	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << " ";
}

// Driver Code
int main()
{
	vector<int> arr = { 1, 101, 2, 3, 100, 4, 5 };
	int n = arr.size();

	// Function call
	constructMaxSumIS(arr, n);

	return 0;
}\



20.	Count Increasing Subsequence

// C++ program to count increasing subsequences
// in an array of digits.
#include<bits/stdc++.h>
using namespace std;

// Function To Count all the sub-sequences
// possible in which digit is greater than
// all previous digits arr[] is array of n
// digits
int countSub(int arr[], int n)
{
	// count[] array is used to store all sub-
	// sequences possible using that digit
	// count[] array covers all the digit
	// from 0 to 9
	int count[10] = {0};

	// scan each digit in arr[]
	for (int i=0; i<n; i++)
	{
		// count all possible sub-sequences by
		// the digits less than arr[i] digit
		for (int j=arr[i]-1; j>=0; j--)
			count[arr[i]] += count[j];

		// store sum of all sub-sequences plus
		// 1 in count[] array
		count[arr[i]]++;
	}

	// now sum up the all sequences possible in
	// count[] array
	int result = 0;
	for (int i=0; i<10; i++)
		result += count[i];

	return result;
}

// Driver program to run the test case
int main()
{
	int arr[] = {3, 2, 4, 5, 4};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << countSub(arr,n);
	return 0;
}


21.	Pairs with specific difference

// C++ program to find a pair with the given difference
#include <bits/stdc++.h>
using namespace std;

// The function assumes that the array is sorted
bool findPair(int arr[], int size, int n)
{
	unordered_map<int, int> mpp;
	for (int i = 0; i < size; i++) {
		mpp[arr[i]]++;

		// Check if any element whose frequency
		// is greater than 1 exist or not for n == 0
		if (n == 0 && mpp[arr[i]] > 1)
			return true;
	}

	// Check if difference is zero and
	// we are unable to find any duplicate or
	// element whose frequency is greater than 1
	// then no such pair found.
	if (n == 0)
		return false;

	for (int i = 0; i < size; i++) {
		if (mpp.find(n + arr[i]) != mpp.end()) {
			cout << "Pair Found: (" << arr[i] << ", "
				<< n + arr[i] << ")";
			return true;
		}
	}

	cout << "No Pair found";
	return false;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1, 8, 30, 40, 100 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int n = -60;
	findPair(arr, size, n);
	return 0;
}
2.	Minimum number of Coins

// A Dynamic Programming based C++ program to find minimum
// of coins to make a given change V
#include <bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[V] will have result
	int table[V + 1];

	// Base case (If given value V is 0)
	table[0] = 0;

	// Initialize all table values as Infinite
	for (int i = 1; i <= V; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all
	// values from 1 to V
	for (int i = 1; i <= V; i++) {
		// Go through all coins smaller than i
		for (int j = 0; j < m; j++)
			if (coins[j] <= i) {
				int sub_res = table[i - coins[j]];
				if (sub_res != INT_MAX
					&& sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
	}

	if (table[V] == INT_MAX)
		return -1;

	return table[V];
}

// Driver program to test above function
int main()
{
	int coins[] = { 9, 6, 5, 1 };
	int m = sizeof(coins) / sizeof(coins[0]);
	int V = 11;
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V);
	return 0;
}

1.	Iterative MergeSort


/* Iterative C program for merge sort */
#include <bits/stdc++.h>
using namespace std;

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r);

// Utility function to find minimum of two integers
int min(int x, int y) { return (x<y)? x :y; }


/* Iterative mergesort function to sort arr[0...n-1] */
void mergeSort(int arr[], int n)
{
int curr_size; // For current size of subarrays to be merged
				// curr_size varies from 1 to n/2
int left_start; // For picking starting index of left subarray
				// to be merged

// Merge subarrays in bottom up manner. First merge subarrays of
// size 1 to create sorted subarrays of size 2, then merge subarrays
// of size 2 to create sorted subarrays of size 4, and so on.
for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
{
	// Pick starting point of different subarrays of current size
	for (left_start=0; left_start<n-1; left_start += 2*curr_size)
	{
		// Find ending point of left subarray. mid+1 is starting
		// point of right
		int mid = min(left_start + curr_size - 1, n-1);

		int right_end = min(left_start + 2*curr_size - 1, n-1);

		// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
		merge(arr, left_start, mid, right_end);
	}
}
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout <<" "<< A[i];
	cout <<"\n";
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout <<"Given array is \n ";
	printArray(arr, n);

	mergeSort(arr, n);

	cout <<"\nSorted array is \n ";
	printArray(arr, n);
	return 0;
}
// This code is contributed shivanisinghss2110


2.	Recursive MergeSort


// Recursive C++ program for merge sort
#include<bits/stdc++.h>
using namespace std;

// Function to merge the two haves
// arr[l..m] and arr[m+1..r] of array arr[]
void merge(int arr[], int l, int m, int r);

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		// Same as (l+r)/2 but avoids
		// overflow for large l & h
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

// Function to merge the two haves arr[l..m]
// and arr[m+1..r] of array arr[]
void merge(int arr[], int l, int m, int r)
{
	int k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for(int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(int j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	// Merge the temp arrays
	// back into arr[l..r]
	int i = 0;
	int j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements
	// of L[], if there are any
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements
	// of R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Function to print an array
void printArray(int A[], int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", A[i]);

	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
3.	QuickSort


/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i
		= (low
		- 1); // Index of smaller element and indicates
				// the right position of pivot found so far

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

// This code is contributed by rathbhupendra
4.	CountingSort

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int>& arr)
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;

	vector<int> count(range), output(arr.size());
	for (int i = 0; i < arr.size(); i++)
		count[arr[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = arr.size() - 1; i >= 0; i--) {
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}

void printArray(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver code
int main()
{
	vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };

	// Function call
	countSort(arr);
	printArray(arr);
	return 0;
}
.	Sorting elements by frequency


// CPP program for above approach
#include <bits/stdc++.h>
using namespace std;

// Compare function
bool fcompare(pair<int, pair<int, int> > p,
			pair<int, pair<int, int> > p1)
{
	if (p.second.second != p1.second.second)
		return (p.second.second > p1.second.second);
	else
		return (p.second.first < p1.second.first);
}
void sortByFrequency(int arr[], int n)
{
	unordered_map<int, pair<int, int> > hash; // hash map
	for (int i = 0; i < n; i++) {
		if (hash.find(arr[i]) != hash.end())
			hash[arr[i]].second++;
		else
			hash[arr[i]] = make_pair(i, 1);
	} // store the count of all the elements in the hashmap

	// Iterator to Traverse the Hashmap
	auto it = hash.begin();

	// Vector to store the Final Sortted order
	vector<pair<int, pair<int, int> > > b;
	for (it; it != hash.end(); ++it)
		b.push_back(make_pair(it->first, it->second));

	sort(b.begin(), b.end(), fcompare);

	// Printing the Sorted sequence
	for (int i = 0; i < b.size(); i++) {
		int count = b[i].second.second;
		while (count--)
			cout << b[i].first << " ";
	}
}

// Driver code
int main()
{
	int arr[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	sortByFrequency(arr, n);

	return 0;
}
6.	Sort array in wave form

// A O(n) program to sort an input array in wave form
#include<iostream>
using namespace std;

// A utility method to swap two numbers.
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// This function sorts arr[0..n-1] in wave form, i.e., arr[0] >=
// arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5] ....
void sortInWave(int arr[], int n)
{
	// Traverse all even elements
	for (int i = 0; i < n; i+=2)
	{
		// If current even element is smaller than previous
		if (i>0 && arr[i-1] > arr[i] )
			swap(&arr[i], &arr[i-1]);

		// If current even element is smaller than next
		if (i<n-1 && arr[i] < arr[i+1] )
			swap(&arr[i], &arr[i + 1]);
	}
}

// Driver program to test above function
int main()
{
	int arr[] = {10, 90, 49, 2, 1, 5, 23};
	int n = sizeof(arr)/sizeof(arr[0]);
	sortInWave(arr, n);
	for (int i=0; i<n; i++)
	cout << arr[i] << " ";
	return 0;
}
7.	Finding minimum length sorted sub-array to sort an array

// C++ program to find the Minimum length Unsorted Subarray,
// sorting which makes the complete array sorted
#include<bits/stdc++.h>
using namespace std;

void printUnsorted(int arr[], int n)
{
int s = 0, e = n-1, i, max, min;

// step 1(a) of above algo
for (s = 0; s < n-1; s++)
{
	if (arr[s] > arr[s+1])
	break;
}
if (s == n-1)
{
	cout << "The complete array is sorted";
	return;
}

// step 1(b) of above algo
for(e = n - 1; e > 0; e--)
{
	if(arr[e] < arr[e-1])
	break;
}

// step 2(a) of above algo
max = arr[s]; min = arr[s];
for(i = s + 1; i <= e; i++)
{
	if(arr[i] > max)
	max = arr[i];
	if(arr[i] < min)
	min = arr[i];
}

// step 2(b) of above algo
for( i = 0; i < s; i++)
{
	if(arr[i] > min)
	{
	s = i;
	break;
	}
}

// step 2(c) of above algo
for( i = n -1; i >= e+1; i--)
{
	if(arr[i] < max)
	{
	e = i;
	break;
	}
}

// step 3 of above algo
cout << "The unsorted subarray which"
	<< " makes the given array" << endl
	<< "sorted lies between the indices "
	<< s << " and " << e;
return;
}

int main()
{
	int arr[] = {10, 12, 20, 30, 25,
				40, 32, 31, 35, 50, 60};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printUnsorted(arr, arr_size);
	getchar();
	return 0;
}

// This code is contributed
// by Akanksha Rai
8.	Sorting strings

// C++ program to sort a string of characters
#include<bits/stdc++.h>
using namespace std;

// function to print string in sorted order
void sortString(string &str)
{
sort(str.begin(), str.end());
cout << str;
}

// Driver program to test above function
int main()
{
	string s = "geeksforgeeks";
	sortString(s);
	return 0;
}
9.	Count distinct pairs with difference of K.

/* A sorting based program to count pairs with difference k*/
#include <iostream>
#include <algorithm>
using namespace std;

/* Standard binary search function */
int binarySearch(int arr[], int low, int high, int x)
{
	if (high >= low)
	{
		int mid = low + (high - low)/2;
		if (x == arr[mid])
			return mid;
		if (x > arr[mid])
			return binarySearch(arr, (mid + 1), high, x);
		else
			return binarySearch(arr, low, (mid -1), x);
	}
	return -1;
}

/* Returns count of pairs with difference k in arr[] of size n. */
int countPairsWithDiffK(int arr[], int n, int k)
{
	int count = 0, i;
	sort(arr, arr+n); // Sort array elements

	/* code to remove duplicates from arr[] */

	// Pick a first element point
	for (i = 0; i < n; i++){
	while(i - 1 >= 0 && arr[i] == arr[i - 1]) i++;

		if (binarySearch(arr, i+1, n-1, arr[i] + k) != -1)
			count++;
	}

	return count;
}

// Driver program
int main()
{
	int arr[] = {1, 5, 3, 4, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << "Count of pairs with given diff is "
		<< countPairsWithDiffK(arr, n, k);
	return 0;
}
10.	Maximum number of partitions that can be sorted individually to make sorted
// CPP program to find Maximum number of partitions such
// that we can get a sorted array.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum partitions.
int maxPartitions(int arr[], int n)
{
	int ans = 0, max_so_far = 0;
	for (int i = 0; i < n; ++i) {

		// Find maximum in prefix arr[0..i]
		max_so_far = max(max_so_far, arr[i]);

		// If maximum so far is equal to index, we can make
		// a new partition ending at index i.
		if (max_so_far == i)
			ans++;
	}
	return ans;
}

// Driver code
int main()
{
	int arr[] = { 1, 0, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxPartitions(arr, n);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
11.	Sorting all array elements except one

// CPP program to sort all elements except
// element at index k.
#include <bits/stdc++.h>
using namespace std;

int sortExceptK(int arr[], int k, int n)
{
	// Move k-th element to end
	swap(arr[k], arr[n-1]);

	// Sort all elements except last
	sort(arr, arr + n - 1);

	// Store last element (originally k-th)
	int last = arr[n-1];

	// Move all elements from k-th to one
	// position ahead.
	for (int i=n-1; i>k; i--)
	arr[i] = arr[i-1];

	// Restore k-th element
	arr[k] = last;
}

// Driver code
int main()
{
	int a[] = {10, 4, 11, 7, 6, 20 };
	int k = 2;
	int n = sizeof(a) / sizeof(a[0]);
	sortExceptK(a, k, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

13.	Rope Cutting

// C++ program to print how many
// Ropes are Left After Every Cut
#include <bits/stdc++.h>
using namespace std;

// Function print how many Ropes are
// Left AfterEvery Cutting operation
void cuttingRopes(int Ropes[], int n)
{
	// sort all Ropes in increase
	// of their length
	sort(Ropes, Ropes + n);

	int singleOperation = 0;

	// min length rope
	int cuttingLength = Ropes[0];

	// now traverse through the given
	// Ropes in increase order of length
	for (int i = 1; i < n; i++)
	{
		// After cutting if current rope length
		// is greater than '0' that mean all
		// ropes to it's right side are also
		// greater than 0
		if (Ropes[i] - cuttingLength > 0)
		{
			// print number of ropes remains
			cout << (n - i) << " ";

			// now current rope become
			// min length rope
			cuttingLength = Ropes[i];
			singleOperation++;
		}
	}
	if (singleOperation == 0)
		cout << "0 ";
}
int main()
{
	int Ropes[] = { 5, 1, 1, 2, 3, 5 };
	int n = sizeof(Ropes) / sizeof(Ropes[0]);
	cuttingRopes(Ropes, n);
	return 0;
}




14.	Merge k Sorted Arrays
// C++ program to merge K sorted arrays of size n each.

#include <bits/stdc++.h>
using namespace std;
#define N 4

// Merge arr1[0..N1-1] and arr2[0..N2-1] into
// arr3[0..N1+N2-1]
void mergeArrays(int arr1[], int arr2[], int N1, int N2,
				int arr3[])
{
	int i = 0, j = 0, k = 0;

	// Traverse both array
	while (i < N1 && j < N2) {
		// Check if current element of first
		// array is smaller than current element
		// of second array. If yes, store first
		// array element and increment first array
		// index. Otherwise do same with second array
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	// Store remaining elements of first array
	while (i < N1)
		arr3[k++] = arr1[i++];

	// Store remaining elements of second array
	while (j < N2)
		arr3[k++] = arr2[j++];
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them
// together and prints the final sorted output.
void mergeKArrays(int arr[][N], int i, int j, int output[])
{
	// If one array is in range
	if (i == j) {
		for (int p = 0; p < N; p++)
			output[p] = arr[i][p];
		return;
	}

	// if only two arrays are left them merge them
	if (j - i == 1) {
		mergeArrays(arr[i], arr[j], N, N, output);
		return;
	}

	// Output arrays
	int out1[N * (((i + j) / 2) - i + 1)],
		out2[N * (j - ((i + j) / 2))];

	// Divide the array into halves
	mergeKArrays(arr, i, (i + j) / 2, out1);
	mergeKArrays(arr, (i + j) / 2 + 1, j, out2);

	// Merge the output array
	mergeArrays(out1, out2, N * (((i + j) / 2) - i + 1),
				N * (j - ((i + j) / 2)), output);
}

// Driver's code
int main()
{
	// Change N at the top to change number of elements
	// in an array
	int arr[][N] = { { 2, 6, 12, 34 },
					{ 1, 9, 20, 1000 },
					{ 23, 34, 90, 2000 } };
	int K = sizeof(arr) / sizeof(arr[0]);
	int output[N * K];
	mergeKArrays(arr, 0, 2, output);

	// Function call
	cout << "Merged array is " << endl;
	printArray(output, N * K);

	return 0;
}

15.	Find all four sum numbers
// C++ program for to print all combination
// of 4 elements in A[] with sum equal to X
#include<bits/stdc++.h>
using namespace std;

/* Following function is needed
for library function qsort(). */
int compare (const void *a, const void * b)
{
	return ( *(int *)a - *(int *)b );
}

/* A sorting based solution to print
all combination of 4 elements in A[]
with sum equal to X */
void find4Numbers(int A[], int n, int X)
{
	int l, r;

	// Sort the array in increasing
	// order, using library function
	// for quick sort
	qsort (A, n, sizeof(A[0]), compare);

	/* Now fix the first 2 elements
	one by one and find
	the other two elements */
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i+1; j < n - 2; j++)
		{
			// Initialize two variables as
			// indexes of the first and last
			// elements in the remaining elements
			l = j + 1;
			r = n-1;

			// To find the remaining two
			// elements, move the index
			// variables (l & r) toward each other.
			while (l < r)
			{
				if( A[i] + A[j] + A[l] + A[r] == X)
				{
					cout << A[i]<<", " << A[j] <<
						", " << A[l] << ", " << A[r];
					l++; r--;
				}
				else if (A[i] + A[j] + A[l] + A[r] < X)
					l++;
				else // A[i] + A[j] + A[l] + A[r] > X
					r--;
			} // end of while
		} // end of inner for loop
	} // end of outer for loop
}

/* Driver code */
int main()
{
	int A[] = {1, 4, 45, 6, 10, 12};
	int X = 21;
	int n = sizeof(A) / sizeof(A[0]);
	find4Numbers(A, n, X);
	return 0;
}

// This code is contributed by rathbhupendra

16.	Maximum Intervals Overlap

// C++ program that print maximum
// number of overlap
// among given ranges
#include <bits/stdc++.h>
using namespace std;

// Function that print maximum
// overlap among ranges
void overlap(vector<pair<int, int> > v)
{
	// variable to store the maximum
	// count
	int ans = 0;
	int count = 0;
	vector<pair<int, char> > data;

	// storing the x and y
	// coordinates in data vector
	for (int i = 0; i < v.size(); i++) {

		// pushing the x coordinate
		data.push_back({ v[i].first, 'x' });

		// pushing the y coordinate
		data.push_back({ v[i].second, 'y' });
	}

	// sorting of ranges
	sort(data.begin(), data.end());

	// Traverse the data vector to
	// count number of overlaps
	for (int i = 0; i < data.size(); i++) {

		// if x occur it means a new range
		// is added so we increase count
		if (data[i].second == 'x')
			count++;

		// if y occur it means a range
		// is ended so we decrease count
		if (data[i].second == 'y')
			count--;

		// updating the value of ans
		// after every traversal
		ans = max(ans, count);
	}

	// printing the maximum value
	cout << ans << endl;
}

// Driver code
int main()
{
	vector<pair<int, int> > v
		= { { 1, 2 }, { 2, 4 }, { 3, 6 } };
	overlap(v);
	return 0;
}
17.	Marks of PCM
struct mark {
    int p, c, m;
};

bool mycp(mark m1, mark m2) {
    if (m1.p < m2.p) {
        return true;
    }
    if (m1.p == m2.p) {
        if (m1.c > m2.c)
            return true;
        if(m1.c==m2.c){
            if (m1.m < m2.m)
                return true;
            else
                return false;
        }
    }
    return false;
}

class Solution {
   public:
    void customSort(int phy[], int chem[], int math[], int N) {
        vector<mark> v;
        for (int x = 0; x < N; x++) {
            mark t;
            t.p = phy[x];
            t.c = chem[x];
            t.m = math[x];
            v.push_back(t);
        }

        sort(v.begin(), v.end(), mycp);
        for(int x=0;x<N;x++){
            phy[x]=v[x].p;
            chem[x]=v[x].c;
            math[x]=v[x].m;
        }
        // your code here
    }
};

18.	Case-specific Sorting of Strings
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        string l="";
        string u="";
        for(auto it:s){
            if(it>='A'&&it<='Z')
            u+=it;
            else
            l+=it;
        }
        sort(u.begin(),u.end());

        sort(l.begin(),l.end());
        int lc=0,uc=0;
        for(int x=0;x<n;x++){
            if(s[x]>='A'&&s[x]<='Z'){
                s[x]=u[uc++];
            }
            else{
                s[x]=l[lc++];
            }
        }
        return s;
        // your code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
19.	Print Binary Tree levels in sorted order


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define lli long long int
#define ull unsigned long long int
#define mod 1000000007
#define pq priority_queue
#define pb push_back
#define ld long double
#define REP(x, n) for (int x = 0; x < n; x++)
class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int ar[], int n)
    {
        // Your code here
        int x=0;
        int level=0;
        vector<vector<int>>ans;

        while(x<n){
            int size=pow(2,level++);
            // if(x+size<=n)
            // sort(ar+x,ar+x+size);
            // else
            vector<int>t;
            while(size-->0){
                t.pb(ar[x++]);
                if(x==n)
                break ;
            }
            sort(t.begin(),t.end());
            ans.pb(t);
        }
        for(int x=0;x<ans.size();x++){

        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;

		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


20.	Minimum Swaps to Sort
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define lli long long int
#define ull unsigned long long int
#define mod 1000000007
#define pq priority_queue
#define pb push_back
#define ld long double
#define REP(x, n) for (int x = 0; x < n; x++)

class Solution
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
	    int x=0;
	    vector<pair<int,int>>v;
	    for(auto it: nums){
	        v.pb({it,x++});
	    }
	    sort(v.begin(),v.end());
	    int ans=0;
	    for(int x=0;x<v.size();x++){
	        if(v[x].second!=x){
	            swap(v[x],v[v[x].second]);
	            ans++;
	            x--;
	        }
	    }
	    return ans;   // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

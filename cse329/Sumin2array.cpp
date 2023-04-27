//ques is find the target value int two array in which sum of both one ele is equal to target


#include <bits/stdc++.h>
 

#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 



//approach 1 -- just full fledge bruteforce T.C. = O(m*n) and S.C. = O(1)
bool bruteforce(int arr[],int nums[],int tar,int alen,int nlen){
    for(int i=0;i<alen;i++){
        for(int j=0;j<nlen;j++){
            if(arr[i]+nums[j] == tar){
                return true;
            }
        }
    }
    return false;
} 

//approach 2 -- two pointer -- t.c. O(mlogm + nlogn) s.c O(1)
bool TwoPointer(int arr[],int nums[],int val,int m,int n){
    sort(arr, arr+m);
    sort(nums, nums+n);
    int left = 0;
    int right = n-1;
    while(left < m && right >= 0){
        int sum = arr[left] + nums[right];
        if(sum == val){
            return true;
        }
        else if(sum < val){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}


//approach 3 -- using binary search -- t,c O(nlogn + mlogn) s.c. O(1)
int binarysearch(int nums[],int n, int val){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == val){
            return mid;
        }
        else if(nums[mid] > val){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
bool BS(int arr[],int nums[],int val,int m, int n){
    sort(nums, nums+n);
    for(int i=0;i<m;i++){
        int tar = val - arr[i];
        if(binarysearch(nums,n,tar) != -1){ 
            return true;
        }
    }
    return false;
}

//approach 4 -- using set -- t.c. O(mlogm + nlogm) s.c (m)
bool hashset(int arr[],int nums[],int tar,int m,int n){
    set<int> s;
    for(int i=0;i<m;i++){
        s.insert(arr[i]);
    }
    for(int i=0;i<n;i++){
        int val = tar - nums[i];
        if(s.find(val) != s.end()){
            return true;
        }
    }
    return false;
}

void krdiyasuru()
{
    cii(m,n);
    ci(Target);
    int a[m],b[n];
    for(int i=0;i<m;i++){
        cin >> a[i] ;
    }
     for(int i=0;i<n;i++){
        cin >> b[i] ;
    }
    cout << bruteforce(a,b,Target,m,n)<< endl;
    cout << TwoPointer(a,b,Target,m,n) << endl;
    cout << BS(a,b,Target,m,n) << endl;
    cout << hashset(a,b,Target,m,n) << endl;
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
    //    krosuru
    {
        krdiyasuru();
    }
}
 
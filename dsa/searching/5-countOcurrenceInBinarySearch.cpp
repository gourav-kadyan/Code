#include <bits/stdc++.h>

#define krosuru  \
    ll ___T;     \
    cin >> ___T; \
    while (___T-- > 0)
#define yehbhitheekhai            \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;
//int binarysearch(vector<int>& v, int n, int value);

int firstOc(int arr[], int n, int value)
{
    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == value){
            if(arr[mid-1] != value || mid == 0) return mid;
            else high = mid-1;
        }
        else if(arr[mid] > value){
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return -1;
}
int lastOc(int arr[], int n, int value)
{
    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == value){
            if(arr[mid+1] != value || mid == n-1) return mid;
            else low = mid+1;
        }
        else if(arr[mid] > value){
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return -1;
}
int Count(int arr[],int n,int value){
    int first = firstOc(arr,n,value);
    if(first == -1) return 0;
    else return lastOc(arr,n,value) - first + 1;
}
void krdiyasuru()
{
    int n ;
    cin>>n;
    int value;
    cin>>value;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int count = Count(arr, n, value);
    cout<<count<<endl;
}

int main(void)
{
    yehbhitheekhai;
    //    solve();
    //   krosuru
    {
        krdiyasuru();
    }
}

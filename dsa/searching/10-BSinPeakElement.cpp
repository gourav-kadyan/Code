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
//find peak element in non sorted array using binarysearch
int binarysearch(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid + 1])){
            return mid;
        }
        else if(mid > 0 && arr[mid] >= arr[mid - 1]){
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return -1;
}
void krdiyasuru()
{
    int n ;
    cin>>n;
    // int value;
    // cin>>value;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int index = binarysearch(arr, n);
    cout<<arr[index]<<endl;
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

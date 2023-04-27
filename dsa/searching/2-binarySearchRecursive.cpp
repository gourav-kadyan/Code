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
int binarysearch(int arr[], int n, int value,int low,int high)
{
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(arr[mid] == value) return mid;
    else if(arr[mid] > value) return binarysearch(arr,n,value,low,mid-1);
    else return binarysearch(arr,n,value,mid+1,high);
}
void krdiyasuru()
{
    int n ;
    cin>>n;
    int value;
    cin>>value;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int index = binarysearch(arr, n, value,0,n-1);
    cout<<index<<endl;
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

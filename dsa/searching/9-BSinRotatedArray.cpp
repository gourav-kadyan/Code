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
// time complexity is log n
// one half of array is always sorted
int binarysearch(int arr[], int n, int value)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] <= value && arr[mid] > value)
            {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if( arr[high] >= value && arr[mid] < value){
                low = mid + 1;
            }
            high = mid - 1;
        }
    }
    return -1;
}
void krdiyasuru()
{
    int n;
    cin >> n;
    int value;
    cin >> value;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int index = binarysearch(arr, n, value);
    cout << index << endl;
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

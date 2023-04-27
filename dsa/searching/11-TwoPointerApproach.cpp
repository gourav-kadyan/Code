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
// two pointer approaches used for finding sum / any other input things that contains to value
//  its very much looks like a binary search
//  like i m using to chk can we make given sum possible using two values in array
//  its time = is big o of n and space is big o of 1
// note --- it is used in sorted array

// //sum is having two values
// bool ChkSum(int arr[],int n, int sum){
//     int l = 0; // l == low
//     int h = n - 1;  // h = high
//     while(l < h){ //we dont use same element as low and high
//         if((arr[l]+arr[h]) == sum ){
//             return true;
//         }
//         else if((arr[l]+arr[h]) > sum){
//             h -= 1;
//         }
//         else {
//             l += 1;
//         }
//     }
//     return false;
// }

// sum is having three values
//time : O(n^2) space : O(1)
bool ChkSum(int arr[], int n, int sum, int i)
{
    int l = i;     // l == low
    int h = n - 1; // h = high
    while (l < h)
    { // we dont use same element as low and high
        if ((arr[l] + arr[h]) == sum)
        {
            return true;
        }
        else if ((arr[l] + arr[h]) > sum)
        {
            h -= 1;
        }
        else
        {
            l += 1;
        }
    }
    return false;
}
bool ChkTriplet(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        if (ChkSum(arr, n, sum - arr[i], i + 1))
        {
            return true;
        }
    }
    return false;
}
void krdiyasuru()
{
    int n;
    cin >> n;
    int sum;
    cin >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (ChkTriplet(arr, n, sum) == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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

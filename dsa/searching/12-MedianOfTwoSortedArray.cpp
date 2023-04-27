#include <bits/stdc++.h>

#define ll long long

#define ci(X) \
    ll X;     \
    cin >> X
#define cii(X, Y) \
    ll X, Y;      \
    cin >> X >> Y
#define ciii(X, Y, Z) \
    ll X, Y, Z;       \
    cin >> X >> Y >> Z
#define ciiii(W, X, Y, Z) \
    ll W, X, Y, Z;        \
    cin >> W >> X >> Y >> Z

#define krosuru  \
    ll ___T;     \
    cin >> ___T; \
    while (___T-- > 0)
#define yehbhitheekhai            \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

using namespace std;
//time  : O(m + n) space : O(1)

// double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
// {
//     int n = arr1.size();
//     int m = arr2.size();  
//     int x = n + m;
//     int i = 0, j = 0, k = 0;
//     vector<int> v(x);
//     while (i < n && j < m)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             v[k] = arr1[i];
//             k++;
//             i++;
//         }
//         else
//         {
//             v[k] = arr2[j];
//             k++;
//             j++;
//         }
//     }
//     while (i < n)
//     {
//         v[k] = arr1[i];
//         k++;
//         i++;
//     }
//     while (j < m)
//     {
//         v[k] = arr2[j];
//         k++;
//         j++;
//     }
//     if (x % 2 == 0)
//     {
//         double sum = v[x / 2] + v[x / 2 - 1];
//         double d = sum / 2;
//         return d;
//     }
//     return v[x/2];
// }



//find median using binary search
//time = O(log n1) 
//condition is arr1 is always smaller than or equal to arr2
//condition some ele of arr1 and arr2 are smaller and bigger to others ele in array

double getMedian(vector<int> arr1, int n1, vector<int> arr2, int n2){
    int l = 0;
    int h = n1 - 1;
    while(l <= h){
        int i1 = l + (h - l) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1; 
        int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
        int max1 = (i1 == 0) ? INT_MIN : arr1[i1 -1];
        int min2 = (i2 == n2) ? INT_MAX : arr2[i2];
        int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];
        if(max1 <= min2 && max2 <= min1){
            if((n1 + n2) % 2 == 0){
                return ((double)max(max1,max2) + min(min1, min2)) /2;
            }
            else {
                return ((double)max(max1, max2));
            }
        }
        else if(max1 > min2){
            h = i1 - 1;
        }
        else {
            l = i1 + 1;
        }
    }
    return -1;
}

void krdiyasuru()
{
    cii(x, y);
    vector<int> nums1(x);
    vector<int> nums2(y);
    for (int i = 0; i < x; i++)
    {
        int temp;
        cin >> temp;
        nums1[i] = temp;
    }
    for (int j= 0;j < y; j++)
    {
        int lol;
        cin >> lol;
        nums2[j] = lol;
    }
    if(x <= y)
    cout << getMedian(nums1, x, nums2, y) << endl;
    else 
    cout << getMedian(nums2, y, nums1, x) << endl;


    //cout << findMedianSortedArrays(nums1, nums2) << endl; O(n+m)
}

int main()
{
    yehbhitheekhai;
    //    solve();
    //krosuru
    {
        krdiyasuru();
    }
}

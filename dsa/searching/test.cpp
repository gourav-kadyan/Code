
// #include <bits/stdc++.h>
// using namespace std;
// double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
// {
//     int n = arr1.size();
//     int m = arr2.size();
//     int i = 0, j = 0, k = 0;
//     int x = n + m;
//     vector<int> v;

//     while (i < n && j < m)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             v.push_back( arr1[i++]);
//         }
//         else
//         {
//             v.push_back(arr2[j++]);
//         }
//     }
//     while (i < n)
//     {
//         v.push_back( arr1[i++];
//     }
//     while (j < m)
//     {
//         v[k++] = arr2[j++];
//     }
//     if (x % 2 == 0)
//     {
//         return (v[x / 2] + v[(x / 2) + 1]) / 2;
//     }
//     return v[x / 2];
// }
// int main()
// {
//     // Your code goes here;
//     int n, m;
//     cin >> n >> m;
//     vector<int> nums1(n);
//     vector<int> nums2(m);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums1[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         cin >> nums2[i];
//     }
//     double lol = findMedianSortedArrays(nums1, nums2);
//     cout << lol << endl;
//     return 0;
// }
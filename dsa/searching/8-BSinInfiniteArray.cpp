#include<bits/stdc++.h>
using namespace std;
//time = big o of log of position
//unbounded binary search 
int binarysearch(int arr[], int low, int high, int value)
{
    
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == value){
            return mid;
        }
        else if(arr[mid] > value){
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return -1;
}
int search(int arr[], int n , int x){
    if(arr[0] == x) return 0;
    
    int i= 1;
    while(i <= x){
        if(arr[i] == x) return i;
        i *= 2;
    }
    return binarysearch(arr,i/2+1,i-1,x);
}
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    int arr[n];
    // for(int i = 0;i<n;i++){
    //     cin >> arr[i];
    // }
    for(int i =0;i<n;i++){
        arr[i] = i;
    }
    int index = search(arr,n,x);
    cout << index << endl;
    return 0;
}
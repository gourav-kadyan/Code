#include<bits/stdc++.h>
using namespace std;

//count 1 using binary search algorithm
// time is big o of log n
// space is constant
int countOnes(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == 0){
            low = mid + 1;
        }
        else {
            if(mid == 0 || arr[mid-1] == 0){
                return (n-mid);
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int count = countOnes(arr,n);
    cout << count <<endl;
}

#include <bits/stdc++.h>
using namespace std;


//2 sum in 1 array and also duplicate is allowed

//two pointer approach -- t.c. = O(nlogn) s.c. -- O(1)
void twoPointers(int arr[],int n, int val){
    sort(arr,arr+n);
    int left = 0;
    int right = n-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum < val){
            left++;
        }
        else if(sum > val){
            right--;
        }
        else{
            cout << arr[left] << " " << arr[right] << endl;
            left++;
            right--;
            while(left < right && arr[left] == arr[left - 1]){
                left++;
            }
            while(left < right && arr[right] == arr[right + 1]){
                right--;
            }
        }
    }
}

//binary search approach
bool binarysearch(int arr[],int val,int low,int high){

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == val){
            return true;
        }
        else if(arr[mid] > val){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return false;
}
void bs(int arr[],int n,int val){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int varr = val - arr[i];
        if(binarysearch(arr,varr,i+1,n-1)==true){
            cout << arr[i] << " " << varr << endl;
            if(arr[i] == arr[i+1]){
                i++;
            }
            while(arr[i]==arr[i-1] && i < n){
                i++;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int target;
    cin >>  target;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    twoPointers(arr,n,target);
    bs(arr,n,target);
    return 0;
}
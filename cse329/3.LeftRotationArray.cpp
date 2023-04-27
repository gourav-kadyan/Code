#include<bits/stdc++.h>
using namespace std;

//left rotation in array
void rev(int arr[], int low, int high){
    while(low < high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
int main(){
    int k;
    cin >> k;
    int arr[5] = {1,2,3,4,5};
    int n=5;
    k = k%n;
    rev(arr,0,n-1);
    rev(arr,0,k-1);
    rev(arr,k,n-1); 
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
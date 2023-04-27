#include<bits/stdc++.h>
using namespace std;

//array insertion at start, at end, at between
int main(){
    int n =5;
    int idx = 2;
    int value = 69;
    int arr[5]= {1, 2, 3,4};
    for(int i=n-1;i>=idx;i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = value;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
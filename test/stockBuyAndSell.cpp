#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int sell = INT_MIN;
    int buy = INT_MAX;

    for(int i=0;i<n;i++){
        if(buy > arr[i]){
            buy = arr[i];
        }
        sell = max(sell,arr[i]-buy);
    }

    cout << sell << endl;
}
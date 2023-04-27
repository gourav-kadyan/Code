#include<bits/stdc++.h>
using namespace std;

//array insertion at start, at end, at between
int main(){
    int idx = 4;
    int arr[5]= {1,69, 2, 3,4};
    for(int i=idx;i<5-1;i++){
        arr[i] = arr[i+1];
    }
    for(int i=0;i<4;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
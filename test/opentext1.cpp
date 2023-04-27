#include <bits/stdc++.h>
using namespace std;

int solution(int A[], int B[],int n){

    
    int a =0;
    int b=0;
    int left_sum = 0, right_sum = 0;
    int left_pointer = 0, right_pointer = n - 1;

    while (left_pointer <= right_pointer) {
        if (left_sum <= right_sum) {
            left_sum += A[left_pointer];
            left_pointer++;
        }
        else {
            right_sum += A[right_pointer];
            right_pointer--;
        }
    }
    if(left_sum == right_sum){
        a = left_pointer;
    }
    
    left_sum = 0;
    right_sum = 0;
    left_pointer = 0;
    right_pointer = n - 1;

    while (left_pointer <= right_pointer) {
        if (left_sum <= right_sum) {
            left_sum += B[left_pointer];
            left_pointer++;
        }
        else {
            right_sum += B[right_pointer];
            right_pointer--;
        }
    }
    if(left_sum == right_sum){
        b = left_pointer;
    }
    
    if(a == b){
        return a;
    }
    return 0;
    
}

int main() {
    
    int A[5] ={0, 4, -1, 0, 3};
    int B[5] = {0 ,-2, 5, 0, 3};
    
    int ans = solution(A,B,5);
    
    cout << ans << endl;

    return 0;
}
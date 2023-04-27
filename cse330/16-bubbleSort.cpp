#include <bits/stdc++.h>
 

using namespace std;
void bubblesort(int v[], int n, int i){
    if(i == n-1){
        return;
    }
    if(v[i+1] < v[i]){
        swap(v[i+1],v[i]);
    }
    bubblesort(v,n,i+1);
}
void bubblehelp(int arr[], int n , int i){
    if( i >= n-1)
    return;
    bubblesort(arr,n,0);
    bubblehelp(arr,n,i+1);
}
void krdiyasuru()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    bubblehelp(arr,n,0);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] <<" ";
    }

    cout<<endl;
}
 
int main()
{
   
    {
        krdiyasuru();
    }
}
 
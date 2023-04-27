//algo is
/*
000--> before all this algo we have build heap either max or min
    1. swap root node to last node  and size--
    2. root node go to correct position (heapify)
    3. do it again until size is 1 or only root node is proesent
    */

//first build an heap i go with min heap

#include<bits/stdc++.h>
using namespace std;
//to build min heap we do arr[i] > arr[largest or smalles]
void heapify(int arr[],int n,int i){
    int parent = i;
    int left = 2*i+1;  //due to zeroes based indexing
    int right = 2*i+2;
    if(left < n && arr[parent] > arr[left]){
        parent = left;
    }
    if(right < n && arr[parent] > arr[right]){
        parent = right;
    }
    if(parent != i){
        swap(arr[parent],arr[i]);
        heapify(arr,n,parent);
    }
}

void buildheap(int arr[],int n){
    int size = n/2-1;//index of last non leaf node
    for(int i=size;i>=0;i--){
        heapify(arr,n,i);
    }

}
void printheap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void heapsort(int arr[],int n){
    int size = n;
    while(size > 0){
        swap(arr[0],arr[size-1]);
        size--;
        heapify(arr,size,0);
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    buildheap(arr,n);
    cout << "heap before sort" << endl;
    printheap(arr,n);
    heapsort(arr,n);
    cout<< "heap after sort" << endl;
    printheap(arr,n);
    return 0;
}
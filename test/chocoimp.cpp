#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 

using namespace std;
class heap{
    public:
    int arr[1000001];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        if(size == 0){
            arr[1] = val;
            size++;
            return;
        }
        int index = size+1;
        arr[index] = val;
        size++;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
        return;
    }

    void print(){
        if(size == 0){
            cout << "bhai kya krr rha hai" << endl;
        }
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int s(){
        return size-1;
    }
    int top(){
        return arr[1];
    }
    void del(){
        if(size == 0){
            cout << "bhai chahata kya hai apni jindagi se"<< endl;
            return;
        }
        if(size == 1){
            size--;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i=1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if(leftIndex <= size && arr[leftIndex] < arr[i]){
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[rightIndex] < arr[i]){
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else{
                return;
            }
            return;
        }
    }
    void hehe(){
        heapify(arr,size,arr[size]);
        return;
    }
    void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    return;
}
};

 
void krdiyasuru()
{
    ci(n);
    heap h;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        h.insert(a[i]);
    }
    ll take = 0;
    while(h.s() > 1){
        int first = h.top();
        cout << first << " ";
        h.del();
        h.hehe();
        int second = h.top();
        cout << second << " ";
        h.del();
        h.hehe();
        take += (first + second);
        h.insert(first+second);
        h.hehe();
    }
    cout << take << endl;
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
     //   krosuru
    {
        krdiyasuru();
    }
}
 
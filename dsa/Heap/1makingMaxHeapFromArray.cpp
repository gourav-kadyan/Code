#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
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
            if(arr[parent] < arr[index]){
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
            if(leftIndex <= size && arr[leftIndex] > arr[i]){
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[rightIndex] > arr[i]){
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else{
                return;
            }
            return;
        }
    }
};



int main(){
    heap h;
    h.insert(35);
    h.insert(10);
    h.insert(69);
    h.insert(88);
    h.insert(99);
    h.print();
    h.del();
    h.del();
    h.print();
    h.del();
    h.del();
    h.del();
    h.del();
    h.print();

    return 0;
}
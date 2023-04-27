#include <bits/stdc++.h> 
using namespace std; 
//implementing queue using array
//for best comp we have to use cir-array
 
struct Q{
    int *arr;
    int cap,siz,front;
    Q(int val){
        cap = val;
        siz = 0;
        front = 0;
    }
    bool full(){
        return (siz == cap);
    }
    bool emp(){
        return (siz == 0);
    }
    int fr(){
        if(emp()){
            return -1;
        }
        return front;
    }
    int r(){
        if(emp()){
            return -1;
        }
        return (front + siz-1) % cap;
    }
    void nq(int val){
        if(full()){
            return;
        }
        int rear = r();
        rear = (rear + 1) % cap;
        arr[rear] = val;
        siz++;
    }
    void dq(){
        if(emp()){
            return;
        }
        front = (front + 1) % cap;
        siz--;
    }
    int sz(){
        return siz;
    }
};

int main(){
    Q q(5);
    q.nq(10);
    q.nq(20);
    q.nq(30);
    q.nq(40);
    cout << q.fr() << endl;
    cout << q.r() << endl;
    cout << q.emp() << endl;
    cout << q.sz() << endl;
    q.dq();
    cout << q.full() << endl;
    cout << q.r() << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//implementing stack using array
struct MyStack{
    int *arr;
    int cap;
    int top;
    MyStack(int val){
        cap = val;
        arr = new int[cap];
        top = -1;
    }
    void _push(int val){
        //for overflow
        if(top == cap-1){
            cout << "eror 69 : stack overflow" << endl ;
            return;
        }
        top++;
        arr[top] = val;
    }
    int _pop(){
        //for underflow 
        if(top == -1){
            cout << "error 96 : stack underflow :";
            return INT_MIN;
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peek(){
        if(top == -1) return -1;
        return arr[top];
    }
    int _size(){
        return top + 1;
    }
    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    MyStack s(10);
    cout << s.isEmpty() << endl;
    s._push(5);
    s._push(10);
    s._push(15);
    cout << s.isEmpty() << endl;
    cout << s.peek() << endl;
    cout << s._pop() << endl;
    cout << s.peek() << endl;
    s._push(20);
    cout << s.peek() << endl;
    cout << s._size() << endl;

    return 0;
}
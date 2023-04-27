#include<bits/stdc++.h>
using namespace std;
//implement stack using vector 
struct MyStack{
    vector<int> v;
    void _push(int val){
        v.push_back(val);
    }
    int _pop(){
        int res = v.back();
        v.pop_back();
        return res;
    }
    bool isEmpty(){
        return v.empty();
    }
    int peek(){
        return v.back();
    }
    int _size(){
        return v.size();
    }
};

int main(){
    MyStack s;
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
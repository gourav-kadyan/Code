#include<bits/stdc++.h>
using namespace std;
//stl stack -- all op func have t.c. is O(1)
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
    return 0;
}
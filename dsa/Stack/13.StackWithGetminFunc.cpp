#include <bits/stdc++.h>
using namespace std;

struct MyStack
{

    stack<int> ms;
    stack<int> as;

    void push1(int x)
    {

        if (ms.empty())
        {
            ms.push(x);
            as.push(x);
            return;
        }

        ms.push(x);

        if (as.top() >= ms.top())
            as.push(x);
    }

    void pop1()
    {

        if (as.top() == ms.top())
            as.pop();
        ms.pop();
    }

    int top()
    {
        return ms.top();
    }

    int getMin()
    {
        return as.top();
    }
};

int main()
{
    MyStack s;
    s.push1(4);
    s.push1(5);
    s.push1(8);
    s.push1(1);
    s.pop1();

    cout << " Minimum Element from Stack: " << s.getMin() << endl;

    return 0;
}

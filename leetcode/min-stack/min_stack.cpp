#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> s, mins;

public:
    MinStack() {}

    void push(int x)
    {
        s.push(x);

        if (mins.empty())
        {
            mins.push(x);
        }
        else
        {
            mins.push(min(getMin(), x));
        }
    }

    void pop()
    {
        s.pop();
        mins.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return mins.top();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << "\n";
    minStack->pop();
    cout << minStack->top() << "\n";
    cout << minStack->getMin() << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string S, string T)
{
    stack<char> s, t;
    for (size_t i = 0; i < S.size(); ++i)
    {
        if (S[i] == '#')
        {
            if (!s.empty())
                s.pop();
        }
        else
        {
            s.push(S[i]);
        }
    }

    for (size_t i = 0; i < T.size(); ++i)
    {
        if (T[i] == '#')
        {
            if (!t.empty())
                t.pop();
        }
        else
        {
            t.push(T[i]);
        }
    }
    while (!s.empty() && !t.empty())
    {
        if (s.top() != t.top())
            return false;
        s.pop();
        t.pop();
    }
    return s.empty() && t.empty();
}

int main(int argc, char const *argv[])
{
    /* code */
    cout << backspaceCompare("ab#c", "ad#c") << "\n"; // 1
    cout << backspaceCompare("ab##", "c#d#") << "\n"; // 1
    cout << backspaceCompare("a##c", "#a#c") << "\n"; // 1
    cout << backspaceCompare("a#c", "b") << "\n";     // 0
    return 0;
}

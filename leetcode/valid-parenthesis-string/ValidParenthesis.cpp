#include <bits/stdc++.h>
using namespace std;

bool check(int i, int cnt, const string &s)
{
    if (i == s.size()) return cnt == 0;
    if (cnt < 0) return false;
    char c = s[i];
    if (c == '(')
    {
        return check(i + 1, cnt + 1, s);
    }
    else if (c == ')')
    {
        return check(i + 1, cnt - 1, s);
    }
    else if (c == '*')
    {
        return check(i + 1, cnt + 1, s) || check(i + 1, cnt - 1, s) || check(i + 1, cnt, s);
    }
    return cnt == 0;
}

bool checkValidString(string s)
{
    return check(0, 0, s);
}

int main(int argc, char const *argv[])
{
    cout << checkValidString("()") << "\n";
    cout << checkValidString("(*)") << "\n";
    cout << checkValidString("(*))") << "\n";
    return 0;
}

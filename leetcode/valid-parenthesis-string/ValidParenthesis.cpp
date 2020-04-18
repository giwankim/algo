#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int n = (int)s.size();
    vector<vector<int>> T(n, vector<int>(n));
    for (int i = 0; i+1 < n; ++i) {
        if (s[i] == '*')
            T[i][i] = 1;
        if ((s[i] == '(' || s[i] == '*') &&
            (s[i+1] == ')' || s[i+1] == '*')) {
            T[i][i+1] = 1;
        }
    }
    if (s[n-1] == '*')
        T[n-1][n-1] = 1;

    return T[0][n-1];
}

int main(int argc, char const *argv[])
{
    cout << checkValidString("()") << "\n";
    cout << checkValidString("(*)") << "\n";
    cout << checkValidString("(*))") << "\n";
    return 0;
}

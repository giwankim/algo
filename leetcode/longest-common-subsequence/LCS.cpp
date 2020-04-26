#include "bits/stdc++.h"
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int n = (int)text1.size(), m = (int)text2.size();
    vector<vector<int>> T(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (text1[i-1] == text2[j-1])
            {
                T[i][j] = T[i - 1][j - 1] + 1;
            }
            else
            {
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);
            }
        }
    }
    return T[n][m];
}

int main(int argc, char const *argv[])
{
    cout << longestCommonSubsequence("abcde", "ace") << "\n";
    cout << longestCommonSubsequence("abc", "abc") << "\n";
    cout << longestCommonSubsequence("abc", "def") << "\n";
    return 0;
}

#include "bits/stdc++.h"
using namespace std;

int minDistance(string word1, string word2) {
    int n = (int)word1.size();
    int m = (int)word2.size();
    vector<vector<int>> T(n + 1, vector<int>(m + 1));
    for (int j = 0; j <= m; ++j) {
        T[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
        T[i][0] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            T[i][j] = min({T[i-1][j], T[i][j-1], T[i-1][j-1]}) + 1;
            if (word1[i-1] == word2[j-1]) {
                T[i][j] = min(T[i][j], T[i-1][j-1]);
            }
        }
    }
    return T[n][m];
}

int main(int argc, char const *argv[])
{
    {
        cout << minDistance("horse", "ros") << endl;            // 3
    }
    {
        cout << minDistance("intention", "execution") << endl;  // 5
    }
    return 0;
}

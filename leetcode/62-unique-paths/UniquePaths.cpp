#include "bits/stdc++.h"
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> T(n, vector<int>(m));
    for (int i = 0; i < n; ++i) T[i][0] = 1;
    for (int j = 1; j < m; ++j) T[0][j] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            T[i][j] = T[i-1][j] + T[i][j-1];
        }
    }
    return T[n-1][m-1];
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1=====\n";
        int m = 3;
        int n = 2;
        int result = uniquePaths(m, n);
        int correct_result = 3;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
        {
        cout << "=====Example 1=====\n";
        int m = 7;
        int n = 3;
        int result = uniquePaths(m, n);
        int correct_result = 28;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    return 0;
}

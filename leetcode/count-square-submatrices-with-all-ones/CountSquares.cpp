#include "bits/stdc++.h"
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    if (matrix.empty())
        return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> T(n, vector<int>(m));
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        T[0][j] = matrix[0][j];
        ans += T[0][j];
    }
    for (int i = 1; i < n; ++i) {
        T[i][0] = matrix[i][0];
        ans += T[i][0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j]) {
                T[i][j] = min({T[i-1][j], T[i][j-1], T[i-1][j-1]}) + 1;
            }
            ans += T[i][j];
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        vector<vector<int>> matrix {{0,1,1,1}, {1,1,1,1}, {0,1,1,1}};
        cout << countSquares(matrix) << endl;  // 15
    }
    {
        vector<vector<int>> matrix {{1,0,1}, {1,1,0}, {1,1,0}};
        cout << countSquares(matrix) << endl;  // 7
    }
    return 0;
}

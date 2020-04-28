#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty())
        return 0;
    int n = (int)matrix.size(), m = (int)matrix[0].size();
    vvi T(n, vi(m));
    for (int i = 0; i < n; ++i) T[i][0] = matrix[i][0]-'0';
    for (int j = 0; j < m; ++j) T[0][j] = matrix[0][j]-'0';
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] == '1'){
                T[i][j] = min({T[i-1][j], T[i][j-1], T[i-1][j-1]}) + 1;
            }
        }
    }
    int ans = 0;
    for  (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, T[i][j]);
        }
    }
    return ans * ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
     };
     cout << maximalSquare(matrix) << "\n";
    return 0;
}

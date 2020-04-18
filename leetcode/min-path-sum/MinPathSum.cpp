#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    vector<vector<int>> T(n, vector<int>(m));
    T[0][0] = grid[0][0];
    for (int j = 1; j < m; ++j)
    {
        T[0][j] = T[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < n; ++i) {
        T[i][0] = T[i-1][0] + grid[i][0];
        for (int j = 1; j < m; ++j)
        {
            T[i][j] = min(T[i][j-1], T[i-1][j]) + grid[i][j];
        }
    }
    return T[n - 1][m - 1];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(grid) << "\n";
    return 0;
}

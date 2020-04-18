#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    vector<int> T(m);
    T[m - 1] = grid[n - 1][m - 1];
    for (int j = m - 2; j >= 0; --j)
    {
        T[j] = T[j + 1] + grid[n - 1][j];
    }
    for (int i = n - 2; i >= 0; --i)
    {
        T[m - 1] = T[m - 1] + grid[i][m - 1];
        for (int j = m - 2; j >= 0; --j)
        {
            T[j] = min(T[j + 1], T[j]) + grid[i][j];
        }
    }
    return T[0];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int m, n;
vector<vector<int>> check;

void bfs(int i, int j, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    q.emplace(i, j);
    check[i][j] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (grid[nx][ny] == '1' && check[nx][ny] == 0)
            {
                q.emplace(nx, ny);
                check[nx][ny] = 1;
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty()) return 0;
    n = (int)grid.size();
    m = (int)grid[0].size();
    check.resize(n, vector<int>(m));
    int nc = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '1' && check[i][j] == 0)
            {
                bfs(i, j, grid);
                nc += 1;
            }
        }
    }
    return nc;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid) << "\n";
    return 0;
}

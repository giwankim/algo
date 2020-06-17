#include "bits/stdc++.h"
using namespace std;
#define UNVISITED 0
#define VISITED 1
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

void _print(vector<vector<char>> &board) {
    for (auto &vec : board) {
        for (char c : vec) {
            cout << c << " ";
        }
        cout << "\n";
    }
}

void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& check) {
    for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (grid[i][j] == '0' || check[nx][ny] == VISITED)
            continue;
        check[nx][ny] = VISITED;
        dfs(nx, ny, grid, check);
    }
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())
        return 0;
    n = (int)grid.size();
    m = (int)grid[0].size();
    vector<vector<int>> check(n, vector<int>(m, UNVISITED));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1' && check[i][j] == UNVISITED) {
                ans += 1;
                check[i][j] = VISITED;
                dfs(i, j, grid, check);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<vector<char>> grid{
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
        };
        int result = numIslands(grid);
        int correct_result = 1;
        cout << "Expect:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(correct_result == result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<vector<char>> grid{
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        };
        int result = numIslands(grid);
        int correct_result = 3;
        cout << "Expect:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(correct_result == result);
    }
    return 0;
}

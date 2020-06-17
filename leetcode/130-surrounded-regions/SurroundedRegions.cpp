#include "bits/stdc++.h"
using namespace std;
#define UNVISITED 0
#define VISITED 1
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

void _print(const vector<vector<char>> &board)
{
    for (const auto &vec : board)
    {
        for (char c : vec)
        {
            cout << c << " ";
        }
        cout << "\n";
    }
}

void bfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &check)
{
    queue<pair<int, int>> q;
    q.emplace(i, j);
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
            if (board[nx][ny] == 'X' || check[nx][ny] == VISITED)
                continue;
            q.emplace(nx, ny);
            check[nx][ny] = VISITED;
        }
    }
}

void solve(vector<vector<char>> &board)
{
    if (board.empty())
        return;
    n = (int)board.size();
    m = (int)board[0].size();
    vector<vector<int>> check(n, vector<int>(m, UNVISITED));
    for (int i = 0; i < n; ++i)
    {
        if (board[i][0] == 'O')
        {
            check[i][0] = VISITED;
            bfs(i, 0, board, check);
        }
        if (board[i][m - 1] == 'O')
        {
            check[i][m - 1] = VISITED;
            bfs(i, m - 1, board, check);
        }
    }
    for (int j = 0; j < m; ++j)
    {
        if (board[0][j] == 'O')
        {
            check[0][j] = VISITED;
            bfs(0, j, board, check);
        }
        if (board[n - 1][j] == 'O')
        {
            check[n - 1][j] = VISITED;
            bfs(n - 1, j, board, check);
        }
    }

    for (int i = 1; i + 1 < n; ++i)
    {
        for (int j = 1; j + 1 < m; ++j)
        {
            if (board[i][j] == 'O' && check[i][j] == UNVISITED)
                board[i][j] = 'X';
        }
    }
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1=====\n";
        vector<vector<char>> board{
            {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
        vector<vector<char>> correct_board{
            {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}};
        cout << "Expect:\n";
        _print(correct_board);
        cout << "Output:\n";
        solve(board);
        _print(board);
        assert(board == correct_board);
    }
    return 0;
}

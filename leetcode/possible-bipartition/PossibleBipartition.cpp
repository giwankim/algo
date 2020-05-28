#include "bits/stdc++.h"
using namespace std;

bool dfs(int from, int color, vector<int> &check, vector<vector<int>> &adj)
{
    check[from] = color;
    for (int j = 0; j < (int)adj[from].size(); ++j)
    {
        int to = adj[from][j];
        if (check[to] == color)
        {
            return false;
        }
        else if (check[to] == -1)
        {
            bool cur = dfs(to, color ^ 1, check, adj);
            if (cur == false)
                return false;
        }
    }
    return true;
}

bool possibleBipartition(int N, vector<vector<int>> &dislikes)
{
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < (int)dislikes.size(); ++i)
    {
        int from = dislikes[i][0];
        int to = dislikes[i][1];
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    vector<int> check(N + 1, -1);
    for (int i = 1; i <= N; ++i)
    {
        if (check[i] == -1)
        {
            if (dfs(i, 0, check, adj) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    {
        int N = 4;
        vector<vector<int>> dislikes{{1, 2}, {1, 3}, {2, 4}};
        cout << possibleBipartition(N, dislikes) << endl; // 1
    }
    {
        int N = 3;
        vector<vector<int>> dislikes{{1, 2}, {1, 3}, {2, 3}};
        cout << possibleBipartition(N, dislikes) << endl; // 0
    }
    {
        int N = 5;
        vector<vector<int>> dislikes{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
        cout << possibleBipartition(N, dislikes) << endl; // 0
    }
    return 0;
}

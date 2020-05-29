#include "bits/stdc++.h"
using namespace std;

bool dfs(int i, const vector<vector<int>>& adj, vector<int>& check) {
    check[i] = 0;
    for (int j = 0; j < (int)adj[i].size(); ++j) {
        int k = adj[i][j];
        if (check[k] == 0) {
            return false;
        } else if (check[k] == -1) {
            if (dfs(k, adj, check) == false)
                return false;
        }
    }
    check[i] = 1;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto& edge : prerequisites) {
        adj[edge[0]].push_back(edge[1]);
    }
    vector<int> check(numCourses, -1);
    for (int i = 0; i < numCourses; ++i) {
        if (check[i] == -1) {
            if (dfs(i, adj, check) == false) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    {
        vector<vector<int>> prereqs {{1, 0}};
        cout << canFinish(2, prereqs) << endl;  // 1
    }
    {
        vector<vector<int>> prereqs {{1, 0}, {0, 1}};
        cout << canFinish(2, prereqs) << endl;  // 0
    }
    return 0;
}

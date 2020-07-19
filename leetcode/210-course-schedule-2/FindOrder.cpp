#include "bits/stdc++.h"
using namespace std;

void _print(vector<int>& vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << "\n";
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses);
    for (int i = 0; i < prerequisites.size(); ++i) {
        int from = prerequisites[i][0];
        int to = prerequisites[i][1];
        adj[from].push_back(to);
        indeg[to] += 1;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ret;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ret.push_back(v);
        for (int j = 0; j < adj[v].size(); ++j) {
            int u = adj[v][j];
            indeg[u] -= 1;
            if (indeg[u] == 0) {
                q.push(u);
            }
        }
    }
    if (ret.size() < numCourses) {
        return vector<int>();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int numCourses = 2;
        vector<vector<int>> prerequisites{{1, 0}};
        vector<int> result = findOrder(numCourses, prerequisites);
        vector<int> correct_result{0, 1};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }
    {
        cout << "=====Example 2=====\n";
        int numCourses = 4;
        vector<vector<int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        vector<int> result = findOrder(numCourses, prerequisites);
        vector<int> correct_result{0, 2, 1, 3};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }
    return 0;
}

#include "bits/stdc++.h"
using namespace std;

enum Color {UNVISITED, VISITING, VISITED};
vector<vector<int>> adj;
vector<Color> colors;
vector<int> order;

void _print(vector<int>& vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << "\n";
}

bool dfs(int i) {
    colors[i] = VISITING;
    for (int j = 0; j < adj[i].size(); ++j) {
        int to = adj[i][j];
        if (colors[to] == VISITING) {
            return false;
        }
        if (colors[to] == UNVISITED) {
            if (dfs(to) == false) {
                return false;
            }
        }
    }
    colors[i] = VISITED;
    order.push_back(i);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    adj.assign(numCourses, vector<int>());
    for (int i = 0; i < prerequisites.size(); ++i) {
        int from = prerequisites[i][0];
        int to = prerequisites[i][1];
        adj[from].push_back(to);
    }
    order.clear();
    colors.assign(numCourses, UNVISITED);
    for (int i = 0; i < numCourses; ++i) {
        if (colors[i] == UNVISITED) {
            colors[i] = VISITING;
            if (dfs(i) == false) {
                return vector<int>();
            }
        }
    }
    return order;
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
    return 0;
}

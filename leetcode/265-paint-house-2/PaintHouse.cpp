#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000

int minCostII(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    int n = (int)costs.size();
    int m = (int)costs[0].size();
    vector<vector<int>> T(n, vector<int>(m, INF));
    for (int j = 0; j < m; ++j) {
        T[0][j] = costs[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k) {
                if (j == k) continue;
                T[i][j] = min(T[i][j], T[i - 1][k]);
            }
            T[i][j] += costs[i][j];
        }
    }
    int ans = INF;
    for (int j = 0; j < m; ++j) {
        ans = min(ans, T[n - 1][j]);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<vector<int>> costs {{1, 5, 3}, {2, 9, 4}};
        int result = minCostII(costs);
        int correct_result = 5;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        assert(result == correct_result);
    }
    return 0;
}
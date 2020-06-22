#include "bits/stdc++.h"
using namespace std;

int minCost(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    int n = (int)costs.size();
    int m = (int)costs[0].size();
    vector<vector<int>> T(n, vector<int>(m));
    for (int j = 0; j < m; ++j) {
        T[0][j] = costs[0][j];
    }
    for (int i = 1; i < n; ++i) {
        T[i][0] = min(T[i - 1][1], T[i - 1][2]) + costs[i][0];
        T[i][1] = min(T[i - 1][0], T[i - 1][2]) + costs[i][1];
        T[i][2] = min(T[i - 1][0], T[i - 1][1]) + costs[i][2];
    }
    return min({T[n - 1][0], T[n - 1][1], T[n - 1][2]});
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<vector<int>> costs {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
        int result = minCost(costs);
        int correct_result = 10;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        assert(result == correct_result);
    }
    return 0;
}
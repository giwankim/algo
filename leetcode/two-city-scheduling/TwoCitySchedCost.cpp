#include "bits/stdc++.h"
using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = (int)costs.size() / 2;
    vector<pair<int, int>> diffs(costs.size());
    for (int i = 0; i < (int)diffs.size(); ++i) {
        diffs[i] = make_pair(costs[i][0] - costs[i][1], i);
    }
    sort(diffs.begin(), diffs.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int idx = diffs[i].second;
        ans += costs[idx][0];
    }
    for (int i = n; i < 2*n; ++i) {
        int idx = diffs[i].second;
        ans += costs[idx][1];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        vector<vector<int>> costs {{10,20},{30,200},{400,50},{30,20}};
        cout << twoCitySchedCost(costs) << endl;
        // 110
    }
    {
        vector<vector<int>> costs { {259,770}, {448,54}, {926,667}, {184,139}, {840,118}, {577,469} };
        cout << twoCitySchedCost(costs) << endl;
        // 1859
    }
    return 0;
}

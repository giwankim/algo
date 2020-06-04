#include "bits/stdc++.h"
using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
    std::sort(costs.begin(), costs.end(), [](auto& v1, auto& v2) {
        return v1[0] - v1[1] < v2[0] - v2[1];
    });
    int n = (int)costs.size() / 2;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += costs[i][0] + costs[i + n][1];
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

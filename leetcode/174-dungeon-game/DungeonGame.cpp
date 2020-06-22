#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000

void _print(vector<vector<int>>& T) {
    for (int i = 0; i < (int)T.size(); ++i) {
        for (int j = 0; j < (int)T[i].size(); ++j) {
            cout << T[i][j] << " ";
        }
        cout << "\n";
    }
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = (int)dungeon.size();
    int m = (int)dungeon[0].size();
    vector<vector<int>> T(n, vector<int>(m));
    T[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);
    for (int j = m - 2; j>= 0; --j) {
        T[n - 1][j] = max(1, T[n - 1][j + 1] - dungeon[n - 1][j]);
    }
    for (int i = n - 2; i >= 0; --i) {
        T[i][m - 1] = max(1, T[i + 1][m - 1] - dungeon[i][m - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 2; j >= 0; --j) {
            T[i][j] = min(T[i + 1][j], T[i][j + 1]) - dungeon[i][j];
            T[i][j] = max(T[i][j], 1);
        }
    }
    // _print(T);
    return T[0][0];
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<vector<int>> dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
        int result = calculateMinimumHP(dungeon);
        int correct_result = 7;
        cout << "Expected: " << correct_result << "\n";
        cout << "Output: " << result << "\n";
        assert(result == correct_result);
    }
    return 0;
}

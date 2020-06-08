#include "bits/stdc++.h"
using namespace std;

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> T(amount+1, vector<int>(n + 1));
    for (int j = 0; j <= n; ++j) {
        T[0][j] = 1;
    }
    for (int i = 1; i <= amount; ++i) {
        for (int j = 1; j <= n; ++j) {
            T[i][j] = T[i][j - 1];
            int coin = coins[j - 1];
            if (i - coin >= 0) {
                T[i][j] += T[i - coin][j];
            }
        }
    }
    return T[amount][n];
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1======\n";
        vector<int> coins{1, 2, 5};
        int amount = 5;
        int result = change(amount, coins);
        int correct_result = 4;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }

    {
        cout << "=====Example 2======\n";
        vector<int> coins{
            2,
        };
        int amount = 3;
        int result = change(amount, coins);
        int correct_result = 0;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }

    {
        cout << "=====Example 3======\n";
        vector<int> coins{
            10,
        };
        int amount = 10;
        int result = change(amount, coins);
        int correct_result = 1;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }
    return 0;
}

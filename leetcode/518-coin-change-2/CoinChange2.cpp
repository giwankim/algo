#include "bits/stdc++.h"
using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> T(amount + 1);
    T[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            T[i] += T[i - coin];
        }
    }
    return T[amount];
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1======\n";
        vector<int> coins {1,2,5};
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
        vector<int> coins {2,};
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
        vector<int> coins {10,};
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

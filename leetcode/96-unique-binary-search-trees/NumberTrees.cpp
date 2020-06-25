#include "bits/stdc++.h"
using namespace std;

int numTrees(int n) {
    vector<int> T(n + 1);
    T[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            T[i] += T[j] * T[i - j - 1];
        }
    }
    return T[n];
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int n = 3;
        int result = numTrees(n);
        int correct_result = 5;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }
    return 0;
}

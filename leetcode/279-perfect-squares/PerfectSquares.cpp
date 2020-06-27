#include "bits/stdc++.h"
using namespace std;

int numSquares(int n) {
    vector<int> T(n + 1, n);
    T[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j*j <= i; ++j) {
            T[i] = min(T[i], 1 + T[i - j*j]);
        }
    }
    return T[n];
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int n = 12;
        int result = numSquares(n);
        int correct_result = 3;
        cout << "Expected:\n";
        cout << correct_result << "\n";
        cout << "Output:\n";
        cout << result << "\n";
    }
    {
        cout << "=====Example 2=====\n";
        int n = 13;
        int result = numSquares(n);
        int correct_result = 2;
        cout << "Expected:\n";
        cout << correct_result << "\n";
        cout << "Output:\n";
        cout << result << "\n";
    }
}

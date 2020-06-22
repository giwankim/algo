#include "bits/stdc++.h"
using namespace std;

int numWays(int n, int k) {
    if (n == 0)
        return 0;
    if (n == 1)
        return k;
    vector<int> T(n);
    T[0] = k;
    T[1] = k * k;
    for (int i = 2; i < n; ++i) {
        T[i] = (k - 1) * (T[i - 2] + T[i - 1]);
    }
    return T[n - 1];
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int n = 3;
        int k = 2;
        int result = numWays(n, k);
        int correct_result = 6;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        int n = 1;
        int k = 0;
        int result = numWays(n, k);
        int correct_result = 0;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        assert(result == correct_result);
    }
 
    return 0;
}
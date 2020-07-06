#include "bits/stdc++.h"
using namespace std;

int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int x = 1;
        int y = 4;
        int result = hammingDistance(x, y);
        int correct_result = 2;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    return 0;
}

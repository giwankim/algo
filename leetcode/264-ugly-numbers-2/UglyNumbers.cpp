#include "bits/stdc++.h"
using namespace std;

int nthUglyNumber(int n) {
    vector<int> T(n);
    T[0] = 1;
    int i = 0, j = 0, k = 0;
    for (int l = 1; l < n; ++l) {
        T[l] = min({2*T[i], 3*T[j], 5*T[k]});
        if (T[l] == 2*T[i]) i +=1;
        if (T[l] == 3*T[j]) j +=1;
        if (T[l] == 5*T[k]) k +=1;
    }
    return T[n-1];
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int n = 10;
        int result = nthUglyNumber(n);
        int correct_result = 12;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int m, int n) {
    while (m < n) {
        n = n & (n - 1);
    }
    return m & n;
}

int main(int argc, char const *argv[]) {
    cout << rangeBitwiseAnd(5, 7) << "\n";
    cout << rangeBitwiseAnd(0, 1) << "\n";
    return 0;
}

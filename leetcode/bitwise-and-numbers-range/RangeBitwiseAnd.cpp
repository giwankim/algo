#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int m, int n) {
    int shifts = 0;
    while (m < n) {
        m >>= 1;
        n >>= 1;
        shifts += 1;
    }
    return m << shifts;
}

int main(int argc, char const *argv[]) {
    cout << rangeBitwiseAnd(5, 7) << "\n";
    cout << rangeBitwiseAnd(0, 1) << "\n";
    return 0;
}

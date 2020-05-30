#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007

int numTilings(int N) {
    vector<vector<long long>> T(N, vector<long long>(4));
    T[0][0] = T[0][3] = 1;
    for (int i = 1; i < N; ++i) {
        T[i][0] = T[i-1][3];
        T[i][1] = (T[i-1][0] + T[i-1][2]) % MOD;
        T[i][2] = (T[i-1][0] + T[i-1][2]) % MOD;
        T[i][3] = (T[i-1][0] + T[i-1][1] + T[i-1][2] + T[i-1][3]) % MOD;
    }
    return (int)T[N-1][3];
}

int main(int argc, char const *argv[])
{
    {
        cout << numTilings(2) << endl; // 2
    }
    {
        cout << numTilings(3) << endl;  // 5
    }
    {
        cout << numTilings(4) << endl;  // 11
    }
    return 0;
}

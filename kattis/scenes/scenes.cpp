#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007

int n, w, h;
long long T[101][10001];

int main(int argc, char const *argv[]) {
    freopen("in4.txt", "r", stdin);
    freopen("out4.txt", "w", stdout);
    cin >> n >> w >> h;
    memset(T, 0, sizeof T);
    // T[i][j] := number of ways to tile with k ribbons when i columns are tiled.
    for (int j = 0; j <= n; ++j) {
        T[w][j] = 1;
    }
    for (int i = w - 1; i >= 0; --i) {
        for (int j = 0; j <= n; ++j) {
            int max_k = min(h, j);
            for (int k = 0; k <= max_k; ++k) {
                T[i][j] += T[i + 1][j - k];
            }
            T[i][j] %= MOD;
        }
    }
    int plains = min(h, n / w) + 1;
    int ans = (T[0][n] - plains + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}

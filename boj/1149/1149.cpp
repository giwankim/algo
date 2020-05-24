#include "bits/stdc++.h"
using namespace std;
#define COLORS 3
int n, a[1000][1000], T[1000][COLORS];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLORS; ++j) {
            cin >> a[i][j];
        }
    }
    memset(T, 0, sizeof T);
    for (int j = 0; j < COLORS; ++j)
        T[0][j] = a[0][j];
    for (int i = 1; i < n; ++i) {
        T[i][0] = min(T[i-1][1], T[i-1][2]) + a[i][0];
        T[i][1] = min(T[i-1][0], T[i-1][2]) + a[i][1];
        T[i][2] = min(T[i-1][0], T[i-1][1]) + a[i][2];
    }
    cout << min({T[n-1][0], T[n-1][1], T[n-1][2]}) << "\n";
    return 0;
}

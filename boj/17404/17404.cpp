#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000

int n, a[1000][3];

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }    
    vector<vector<vector<int>>> T(n, vector<vector<int>>(3, vector<int>(3, INF)));
    for (int k = 0; k < 3; ++k) {
        T[0][k][k] = a[0][k];
    }
    for (int k = 0; k < 3; ++k) {
        for (int i = 1; i < n; ++i) {
            T[i][0][k] = min(T[i-1][1][k], T[i-1][2][k]) + a[i][0];
            T[i][1][k] = min(T[i-1][0][k], T[i-1][2][k]) + a[i][1];
            T[i][2][k] = min(T[i-1][0][k], T[i-1][1][k]) + a[i][2];
        }
    }
    int ans = min({T[n-1][1][0], T[n-1][2][0],
                   T[n-1][0][1], T[n-1][2][1],
                   T[n-1][0][2], T[n-1][1][2]});
    cout << ans << "\n";
    return 0;
}

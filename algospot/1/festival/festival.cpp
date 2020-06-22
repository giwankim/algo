#include "bits/stdc++.h"
using namespace std;
#define INF 1e9

int c, n, l, a[1000];

double solve() {
    double ans = INF;
    for (int len = l; len <= n; ++len) {
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += a[i];
        }
        ans = min(ans, (double)sum / len);
        for (int i = len; i < n; ++i) {
            sum += a[i];
            sum -= a[i - len];
            ans = min(ans, (double)sum / len);
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c;
    cout << setprecision(12);
    while (c--) {
        cin >> n >> l;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve() << "\n";
    }
    return 0;
}

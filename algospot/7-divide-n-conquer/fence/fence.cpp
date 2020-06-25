#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> h;

int Solve(int left, int right) {
    if (left == right) return h[left];

    // Divide into sub-problems
    int mid = left + (right - left) / 2;
    int ret = max(Solve(left, mid), Solve(mid+1, right));

    // Merge left and right sub-problems
    int lo = mid, hi = mid+1;
    int height = min(h[lo], h[hi]);
    ret = max(ret, (hi - lo + 1) * height);
    while (left < lo && hi < right) {
        if (h[lo-1] < h[hi+1]) {
            height = min(height, h[++hi]);
        } else {
            height = min(height, h[--lo]);
        }
        ret = max(ret, (hi - lo + 1) * height);
    }
    while (left < lo) {
        height = min(height, h[--lo]);
        ret = max(ret, (hi - lo + 1) * height);
    }
    while (hi < right) {
        height = min(height, h[++hi]);
        ret = max(ret, (hi - lo + 1) * height);
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // freopen("log.txt", "w", stderr);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        h.resize(n);
        for (int i = 0; i < n; ++i) cin >> h[i];
        cout << Solve(0, n-1) << "\n";
    }
    return 0;
}

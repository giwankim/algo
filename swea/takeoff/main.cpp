/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeW7FakkUDFAVH&
*/
#include <bits/stdc++.h>
using namespace std;

int n, l, a[20][20];

bool garo(int i) {
  bool check[20] = {false};
  for (int j = 1; j < n; ++j) {
    int diff = a[i][j] - a[i][j-1];
    if (diff == 0) continue;
    if (diff > 1 || diff < -1) return false;
    if (diff == 1) {
      for (int k = 1; k <= l; ++k) {
        if (j-k < 0) return false;
        if (a[i][j-k] != a[i][j-1]) return false;
        if (check[j-k]) return false;
        check[j-k] = true;
      }
    } else if (diff == -1) {
      for (int k = 0; k < l; ++k) {
        if (j+k == n) return false;
        if (a[i][j+k] != a[i][j]) return false;
        if (check[j+k]) return false;
        check[j+k] = true;
      }
    }
  }
  return true;
}

bool sero(int j) {
  bool check[20] = {false};
  for (int i = 1; i < n; ++i) {
    int diff = a[i][j] - a[i-1][j];
    if (diff == 0) continue;
    if (diff < -1 || diff > 1) return false;
    if (diff == 1) {
      for (int k = 1; k <= l; ++k) {
        if (i-k < 0) return false;
        if (a[i-k][j] != a[i-1][j]) return false;
        if (check[i-k]) return false;
        check[i-k] = true;
      }
    } else if (diff == -1) {
      for (int k = 0; k < l; ++k) {
        if (i+k == n) return false;
        if (a[i+k][j] != a[i][j]) return false;
        if (check[i+k]) return false;
        check[i+k] = true;
      }
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += garo(i);
      ans += sero(i);
    }
    cout << "#" << t << " " << ans << "\n";
  }
}
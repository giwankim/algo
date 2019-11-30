/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[10][10], d[10][10];

int go(int i, int j, int cnt, int cap) {
  if (cnt == 0) return 0;
  int ans = go(i, j+1, cnt-1, cap);
  if (a[i][j] <= cap) {
    int a2 = a[i][j] * a[i][j];
    ans = max(ans, a2 + go(i, j+1, cnt-1, cap-a[i][j]));
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    memset(d, 0, sizeof d);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n-m+1; ++j) {
        d[i][j] = go(i, j, m, c);
      }
    }
    int row[10] = {0};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n-m+1; ++j) {
        row[i] = max(row[i], d[i][j]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        ans = max(ans, row[i]+row[j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j+2*m-1 < n; ++j) {
        for (int k = j+m; k < n-m+1; ++k) {
          ans = max(ans, d[i][j] + d[i][k]);
        }
      }
    }
    cout << "#" << t << " " << ans << "\n";
  }
}
/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH
*/
#include <bits/stdc++.h>
using namespace std;

int x, dir, a[4][8];

void rotate() {
  int dirs[4] = {0};
  dirs[x] = dir;
  for (int i = x+1; i < 4; ++i) {
    if (a[i-1][2] == a[i][6]) break;
    dirs[i] = -dirs[i-1];
  }
  for (int i = x-1; i >= 0; --i) {
    if (a[i][2] == a[i+1][6]) break;
    dirs[i] = -dirs[i+1];
  }
  for (int i = 0; i < 4; ++i) {
    if (dirs[i] == -1) {
      int tmp = a[i][0];
      for (int j = 0; j <= 6; ++j) {
        a[i][j] = a[i][j+1];
      }
      a[i][7] = tmp;
    } else if (dirs[i] == 1) {
      int tmp = a[i][7];
      for (int j = 7; j >= 1; --j) {
        a[i][j] = a[i][j-1];
      }
      a[i][0] = tmp;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int k;
    cin >> k;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 8; ++j) {
        cin >> a[i][j];
      }
    }
    while (k--) {
      cin >> x >> dir;
      --x;
      rotate();
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
      if (a[i][0] == 1) {
        ans |= 1 << i;
      }
    }
    cout << "#" << t << " " << ans << "\n";
  }
}
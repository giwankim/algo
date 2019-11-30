/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GLXqKAWYDFAXB
*/
#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n, a[49][49], d[49][49];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%1d", &a[i][j]);
      }
    }
    memset(d, -1, sizeof d);
    queue<pair<int, int>> q;
    q.emplace(n/2, n/2);
    d[n/2][n/2] = 0;
    while (!q.empty()) {
      int x, y;
      tie(x, y) = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (d[nx][ny] != -1) continue;
        q.emplace(nx, ny);
        d[nx][ny] = d[x][y] + 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (d[i][j] <= n/2) {
          ans += a[i][j];
        }
      }
    }
    cout << "#" << t << " " << ans << "\n";
  }
}
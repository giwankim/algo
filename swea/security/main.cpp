/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu
*/
#include <bits/stdc++.h>
using namespace std;

int dx[]= {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n, m, a[20][20], d[20][20], cost[22];

void bfs(int x, int y) {
  memset(d, -1, sizeof d);
  queue<pair<int, int>> q;
  q.emplace(x, y);
  d[x][y] = 0;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (d[nx][ny] != -1) continue;
      q.emplace(nx, ny);
      d[nx][ny] = d[x][y] + 1;
    }
  }
}

int go(int x, int y, int k) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (d[i][j] != -1 && d[i][j] < k) {
        ans += a[i][j];
      }
    }
  }
  int profit = m*ans - cost[k];
  return profit >= 0 ? ans : 0;
}

int main() {
  cost[1] = 1;
  for (int i = 2; i <= 21; ++i) {
    cost[i] = cost[i-1] + 4*(i-1);
  }
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        bfs(i, j);
        for (int k = 1; k <= n+1; ++k) {
          ans = max(ans, go(i, j, k));
        }
      }
    }
    printf("#%d %d\n", t, ans);
  }
}
/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl
*/
#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n, m, k;
int a[100][100][3], na[100][100][3];

void simulate() {
  while (m--) {
    memset(na, 0, sizeof na);
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        if (a[x][y][0] == 0) continue;
        int size = a[x][y][0];
        int dir = a[x][y][1];
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (na[nx][ny][2] < size) {
          na[nx][ny][1] = dir;
          na[nx][ny][2] = size;
        }
        na[nx][ny][0] += size;
      }
    }
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        int size = na[x][y][0];
        int dir = na[x][y][1];
        a[x][y][0] = size;
        a[x][y][1] = dir;
        if (x == 0 || y == 0 || x == n-1 || y == n-1) {
          if (size > 0) {
            a[x][y][0] /= 2;
            if (dir == 0 || dir == 2) {
              a[x][y][1] = dir + 1;
            } else {
              a[x][y][1] = dir - 1;
            }
          }
        }
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    memset(a, 0, sizeof a);
    cin >> n >> m >> k;
    while (k--) {
      int x, y, size, dir;
      cin >> x >> y >> size >> dir;
      a[x][y][0] = size;
      a[x][y][1] = --dir;
      a[x][y][2] = size;
    }
    simulate();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += a[i][j][0];
      }
    }
    cout << "#" << t << " " << ans << "\n";
  }
}

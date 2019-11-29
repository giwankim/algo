#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

const int n = 12;
const int m = 6;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char a[n][m+1];
int d[n][m];

void bfs(int x, int y, vii& b) {
  char c = a[x][y];
  memset(d, -1, sizeof d);
  queue<ii> q;
  q.emplace(x, y);
  d[x][y] = 0;
  int cnt = 1;
  while (!q.empty()) {
    int x1, y1;
    tie(x1, y1) = q.front(); q.pop();
    for (int k = 0; k < 4; ++k) {
      int nx = x1 + dx[k];
      int ny = y1 + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (a[nx][ny] != c || d[nx][ny] != -1) continue;
      q.emplace(nx, ny);
      d[nx][ny] = d[x][y] + 1;
      cnt += 1;
    }
  }
  if (cnt >= 4) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (d[i][j] != -1) {
          b.emplace_back(i, j);
        }
      }
    }
  }
}

int main() {
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  while (true) {
    vii b;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == '.') continue;
        bfs(i, j, b);
      }
    }
    if (b.empty()) break;
    ans += 1;
    for (int i = 0; i < b.size(); ++i) {
      int x, y;
      tie(x, y) = b[i];
      a[x][y] = '.';
    }
    for (int j = 0; j < m; ++j) {
      while (true) {
        bool ok = false;
        for (int i = n-1; i >= 1; --i) {
          if (a[i][j] != '.') continue;
          if (a[i-1][j] != '.') {
            a[i][j] = a[i-1][j];
            a[i-1][j] = '.';
            ok = true;
          }
        }
        if (ok == false) break;
      }
    }
  }
  cout << ans << "\n";
}
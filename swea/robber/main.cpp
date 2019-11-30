/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pipe = {
  {},{0,1,2,3},{0,2},{1,3},
  {0,1},{1,2},{2,3},{0,3}
};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n, m, r, c, l, d[50][50];
bool a[50][50][4];

void bfs() {
  memset(d, -1, sizeof d);
  queue<pair<int, int>> q;
  q.emplace(r, c);
  d[r][c] = 0;
  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      int nk = (k + 2) % 4;
      if (a[x][y][k] == false || a[nx][ny][nk] == false) continue;
      if (d[nx][ny] != -1) continue;
      q.emplace(nx, ny);
      d[nx][ny] = d[x][y] + 1;
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    memset(a, 0, sizeof a);
    cin >> n >> m >> r >> c >> l;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int p;
        cin >> p;
        for (int k : pipe[p]) {
          a[i][j][k] = true;
        }
      }
    }
    bfs();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (d[i][j] == -1) continue;
        if (d[i][j] < l) ++ans;
      }
    }
    cout << "#" << t << " " << ans << "\n";
  }
}
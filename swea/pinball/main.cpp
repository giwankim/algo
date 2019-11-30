/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int block[6][4] = {{0,0,0,0},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1}};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n, a[100][100];

int simulate(int sx, int sy, int k, map<ii, ii>& wormhole) {
  int pts = 0;
  int x = sx, y = sy;
  while (true) {
    x += dx[k];
    y += dy[k];
    if (x < 0 || x >= n || y < 0 || y >= n) {
      k = (k + 2) % 4;
      x += dx[k];
      y += dy[k];
      ++pts;
    }
    if (1 <= a[x][y] && a[x][y] <= 5) {
      k = block[a[x][y]][k];
      ++pts;
    } else if (a[x][y] >= 6) {
      tie(x, y) = wormhole[make_pair(x, y)];
    }
    if (a[x][y] == -1) break;
    if (x == sx && y == sy) break;
  }
  return pts;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n;
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
        if (6 <= a[i][j]) {
          m[a[i][j]].emplace_back(i, j);
        }
      }
    }
    map<pair<int, int>, pair<int, int>> wormhole;
    for (auto& p : m) {
      auto h1 = p.second[0];
      auto h2 = p.second[1];
      wormhole[h1] = h2;
      wormhole[h2] = h1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == 0) {
          for (int k = 0; k < 4; ++k) {
            ans = max(ans, simulate(i, j, k, wormhole));
          }
        }
      }
    }
    cout << "#" << t << " " << ans << "\n";
  }
}
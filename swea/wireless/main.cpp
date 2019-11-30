/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?conte
*/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,1,0,-1};
int n, m;
pair<int, int> user[2][101];
tuple<int, int, int, int> bc[8];
bool check[8];

int go(int i, int j) {
  if (i == 2) return 0;
  int ans = go(i+1, j);
  int ux, uy;
  tie(ux, uy) = user[i][j];
  for (int k = 0; k < m; ++k) {
    if (check[k]) continue;
    int x, y, c, p;
    tie(x, y, c, p) = bc[k];
    if (abs(ux - x) + abs(uy - y) <= c) {
      check[k] = true;
      ans = max(ans, p + go(i+1, j));
      check[k] = false;
    }
  }
  return ans;
}

int main() {
  int TC;
  cin >> TC;
  for (int tc = 1; tc <= TC; ++tc) {
    cin >> n >> m;
    int x = 1, y = 1;
    user[0][0] = make_pair(x, y);
    for (int i = 1; i <= n; ++i) {
      int dir;
      cin >> dir;
      x += dx[dir];
      y += dy[dir];
      user[0][i] = make_pair(x, y);
    }
    x = y = 10;
    user[1][0] = make_pair(x, y);
    for (int i = 1; i <= n; ++i) {
      int dir;
      cin >> dir;
      x += dx[dir];
      y += dy[dir];
      user[1][i] = make_pair(x, y);
    }
    for (int i = 0; i < m; ++i) {
      int x, y, c, p;
      cin >> y >> x >> c >> p;
      bc[i] = make_tuple(x, y, c, p);
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      ans += go(0, i);
    }
    cout << "#" << tc << " " << ans << "\n";
  }
  return 0;
}
/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu
*/
#include <cstring>
#include <iostream>
using namespace std;

int dx[] = {1,1,-1,-1};
int dy[] = {-1,1,1,-1};
int n, a[20][20], side[4];
bool check[101];

bool ok(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < n;
}

int go(int i, int x, int y, int cnt) {
  if (i == 4) return cnt;
  for (int j = 0; j < side[i]; ++j) {
    if (check[a[x][y]]) return -1;
    check[a[x][y]] = true;
    cnt += 1;
    x += dx[i];
    y += dy[i];
  }
  return go(i+1, x, y, cnt);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 1; k < n; ++k) {
          side[0] = side[2] = k;
          for (int l = 1; l < n; ++l) {
            side[1] = side[3] = l;
            if (ok(i+k, j-k) && ok(i+l, j+l) && ok(i+k+l, j-k+l)) {
              memset(check, 0, sizeof check);
              int tmp = go(0, i, j, 0);
              if (tmp != -1) {
                if (ans == -1 || ans < tmp) {
                  ans = tmp;
                }
              }
            }
          }
        }
      }
    }
    cout << "#" << t << " " << ans << "\n";
  }
  return 0;
}
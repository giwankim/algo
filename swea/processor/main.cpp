/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n, a[12][12];
bool check[12][12];
vector<pair<int, int>> cores;
int max_cnt, min_len;

bool can_wire(int i, int k) {
  int x, y;
  tie(x, y) = cores[i];
  while (true) {
    x += dx[k];
    y += dy[k];
    if (x < 0 || x >= n || y < 0 || y >= n) {
      return true;
    }
    if (a[x][y] == 1 || check[x][y]) {
      return false;
    }
  }
  return false;
}

int wire(int i, int k) {
  int cnt = 0;
  int x, y;
  tie(x, y) = cores[i];
  while (true) {
    x += dx[k];
    y += dy[k];
    if (x < 0 || x >= n || y < 0 || y >= n) {
      break;
    }
    check[x][y] = true;
    ++cnt;
  }
  return cnt;
}

void unwire(int i, int k) {
  int x, y;
  tie(x, y) = cores[i];
  while (true) {
    x += dx[k];
    y += dy[k];
    if (x < 0 || x >= n || y < 0 || y >= n) {
      break;
    }
    check[x][y] = false;
  }
}

void go(int i, int cnt, int len) {
  if (i == cores.size()) {
    if (cnt > max_cnt) {
      max_cnt = cnt;
      min_len = len;
    } else if (cnt == max_cnt) {
      min_len = min(min_len, len);
    }
    return;
  }
  go(i+1, cnt, len);
  for (int k = 0; k < 4; ++k) {
    if (!can_wire(i, k)) {
      int cur = wire(i, k);
      go(i+1, cnt+1, len+c);
      unwire(i, k);
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n;
    cores.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
        if (i > 0 && j > 0 && a[i][j] == 1) {
          cores.emplace_back(i, j);
        }
      }
    }
    memset(check, 0, sizeof check);
    max_cnt = -1;
    min_len = 9999;
    go(0, 0, 0);
    cout << "#" << t << " " << min_len << "\n";
  }
}

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[3], d[61][61][61];

int go(int i, int j, int k) {
  if (i < 0) return go(0, j, k);
  if (j < 0) return go(i, 0, k);
  if (k < 0) return go(i, j, 0);
  int& ans = d[i][j][k];
  if (i == 0 && j == 0 && k == 0) return ans = 0;
  if (ans != -1) return ans;
  vector<int> p = {1,3,9};
  do {
    int tmp = go(i - p[0], j - p[1], k - p[2]);
    if (ans == -1 || tmp < ans) {
      ans = tmp;
    }
  } while (next_permutation(p.begin(), p.end()));
  return ++ans;
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memset(d, -1, sizeof d);
  cout << go(a[0], a[1], a[2]) << '\n';
}

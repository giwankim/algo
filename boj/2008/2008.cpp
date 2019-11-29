#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 1e9;
int n, m, s, t, x, y, a[501];

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  cin >> n >> m;
  cin >> s >> t >> x >> y;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vvi d(501, vi(501, INF));
  for (int j = 1; j <= n; ++j) {
    d[0][j] = j == s ? 0 : abs(s - j) * y;
  }
  

  cout << d[m][t] << '\n';
}

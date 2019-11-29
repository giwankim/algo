#include <cstring>
#include <iostream>
using namespace std;

const int mod = 1000000007;
int n, d[51][51][51][51];

int go(int index, int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0) return 0;
  if (index == n) {
    return a == 0 && b == 0 && c == 0;
  }
  int& ans = d[index][a][b][c];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = 0; i <= 1; ++i) {
    for (int j = 0; j <= 1; ++j) {
      for (int k = 0; k <= 1; ++k) {
        if (i + j + k == 0) continue;
        ans += go(index+1, a-i, b-j, c-k);
        ans %= mod;
      }
    }
  }
  return ans;
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int s, a, b, c;
  cin >> n >> a >> b >> c;
  memset(d, -1, sizeof d);
  cout << go(0, a, b, c) << '\n';
}
